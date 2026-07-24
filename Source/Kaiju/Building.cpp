// Fill out your copyright notice in the Description page of Project Settings.


#include "Building.h"

#include "KaijuCharacter.h"

// Sets default values
ABuilding::ABuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilding::DealDamage(float Damage, AKaijuCharacter* Attacker)
{
	CurrentHealth = CurrentHealth - Damage;	
	
	if (CurrentHealth <= 0)
	{  
		if (Attacker)
		{
			Attacker->CurrentExp += GiveExp;
			Attacker->CurrentHealth += GiveHealth;
		}
		Destroy();
	}
}

