// Copyright Epic Games, Inc. All Rights Reserved.

#include "KaijuCharacter.h"

#include "Kaiju.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "Elements/Framework/TypedElementSorter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

AKaijuCharacter::AKaijuCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(1.f, 1.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create the camera boom component
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));

	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false;

	// Create the camera component
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));

	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false;

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	
}

void AKaijuCharacter::BeginPlay()
{
	Super::BeginPlay();

	// stub
}

void AKaijuCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

	if (bCharacterTurn)
	{
		UE_LOG(LogKaiju, Error, TEXT("%d"),GameState->TurnCount);
		MoveMenu->AddToViewport();
		bCharacterTurn = false;
		InGameUIMenu->UpdateValues();
	}
	
	if (CurrentExp>=LevelUpExp)
	{
		CurrentLevel++;
		CurrentAtk += AtkUp;
		CurrentExp -= LevelUpExp;
		InGameUIMenu->UpdateValues();
	}
	
	if (CurrentHealth<=0)
	{
		if (CurrentAtk>1)
		{
			CurrentLevel--;
			CurrentAtk -= AtkUp;
		}
		else
		{
			CurrentExp = 0;
		}
		CurrentHealth = 70.0f;
		InGameUIMenu->UpdateValues();
	}
}


void AKaijuCharacter::DealDamage(float Damage)
{
	CurrentHealth = CurrentHealth - Damage;	
	
	if (CurrentHealth <= 0)
	{  
		CurrentLevel--;
		if (CurrentLevel >= 0) CurrentLevel = 1;
		CurrentHealth = 70.0f;
	}

}

void AKaijuCharacter::Basic()
{
	if (MoveCount<2)
	{
		MoveCount++;
		if (Enemy)
			MoveMenu->AddToViewport();
	}
	else
	{
		if (Enemy)
		{
			MoveCount =1 ;
			GameState->TurnCount++;
			Enemy->EnemyTurn();
		}
	}
}

void AKaijuCharacter::Special()
{
	if (MoveCount<2)
	{
		MoveCount++;
		if (Enemy)
			MoveMenu->AddToViewport();
	}
	else
	{
		if (Enemy)
		{
			MoveCount =1 ;
			GameState->TurnCount++;
			Enemy->EnemyTurn();
		}
	}
}

void AKaijuCharacter::Ultimate()
{
	if (MoveCount<2)
	{
		MoveCount++;
		if (Enemy)
			MoveMenu->AddToViewport();
	}
	else
	{
		if (Enemy)
		{
			MoveCount =1 ;
			GameState->TurnCount++;
			Enemy->EnemyTurn();
		}
	}
}

void AKaijuCharacter::Move()
{
	Use(UseDistance);
	
	ABuilding* Building = Cast<ABuilding>(HitData.GetActor());
	if (Building)
	{
		UE_LOG(LogKaiju, Error, TEXT("Not enough spase"));
		MoveMenu->AddToViewport();
	}
	else
	{
		
		SetActorLocation(GetActorLocation()+FVector(UseDistance,UseDistance,0)*GetActorForwardVector());
		
		if (MoveCount<2)
		{
			MoveCount++;
			if (Enemy)
				MoveMenu->AddToViewport();
		}
		else
		{
			if (Enemy)
			{
				MoveCount =1 ;
				GameState->TurnCount++;
				Enemy->EnemyTurn();
			}
		}
	}
}

void AKaijuCharacter::LevelUp()
{
	CurrentLevel++;
	CurrentAtk += AtkUp;
	CurrentExp = 0;
}

void AKaijuCharacter::Use(float Distance)
{
	FVector Start = GetActorLocation();
	FVector End = Start + GetCharacterMovement()->GetForwardVector() *
		Distance;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	FCollisionQueryParams TraceParams;
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.AddIgnoredActors(ActorsToIgnore);
	TraceParams.TraceTag = FName("Use Trace Tag");
	GetWorld()->DebugDrawTraceTag = TraceParams.TraceTag;
	bool bSweep = GetWorld()->LineTraceSingleByChannel(HitData, Start,
		End, ECC_Visibility, TraceParams);
	
	if (bSweep)
	{
		if (HitData.GetActor())
		{
			UE_LOG(LogTemp, Warning, TEXT("We hit: %s"), *HitData.GetActor()->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("What happened?!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Didn't hit an actor!"));
	}
}
