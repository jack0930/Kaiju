// Fill out your copyright notice in the Description page of Project Settings.


#include "Kyrocdan.h"
#include "Kaiju.h"


AKyrocdan::AKyrocdan()
{
	CurrentAtk = 15;
	LevelUpExp = 120;
	AtkUp = 30;
}

void AKyrocdan::Basic()
{
	if (CurrentHealth>20)
	{
		CurrentHealth -= 20;
		Use(UseDistance);
		ABuilding* Building = Cast<ABuilding>(HitData.GetActor());
		if (Building)
		{
			Building->DealDamage(CurrentAtk,this);
		}
	
		UE_LOG(LogKaiju, Error, TEXT("Player Exp : %f"),CurrentExp);
		UE_LOG(LogKaiju, Error, TEXT("Player Eng : %f"),CurrentHealth);
		
		Super::Basic();
	
	}
	else
	{
		UE_LOG(LogKaiju, Error, TEXT("Not enough Eng"));
		MoveMenu->AddToViewport();
	}
}

void AKyrocdan::Special()
{
	if (CurrentHealth>120)
	{
		CurrentHealth -= 120;
		Use(UseDistance*3);
		ABuilding* Building = Cast<ABuilding>(HitData.GetActor());
		if (Building)
		{
			Building->DealDamage(CurrentAtk*1.3,this);
		}
	
		UE_LOG(LogKaiju, Error, TEXT("Player Exp : %f"),CurrentExp);
		UE_LOG(LogKaiju, Error, TEXT("Player Eng : %f"),CurrentHealth);
		
		Super::Special();
	
	}
	else
	{
		UE_LOG(LogKaiju, Error, TEXT("Not enough Eng"));
		MoveMenu->AddToViewport();
	}
}

void AKyrocdan::Ultimate()
{
	if (CurrentHealth>1000)
	{
		CurrentHealth -= 1000;
		Use(UseDistance*5);
		ABuilding* Building = Cast<ABuilding>(HitData.GetActor());
		if (Building)
		{
			Building->DealDamage(CurrentAtk*1.5,this);
		}
		UE_LOG(LogKaiju, Error, TEXT("Player Exp : %f"),CurrentExp);
		UE_LOG(LogKaiju, Error, TEXT("Player Eng : %f"),CurrentHealth);
		
		Super::Ultimate();
	
	}
	else
	{
		UE_LOG(LogKaiju, Error, TEXT("Not enough Eng"));
		MoveMenu->AddToViewport();
	}
}

void AKyrocdan::BeginPlay()
{
	Super::BeginPlay();
	
	GameState = Cast<AKaijuGameStateBase>(GetWorld()->GetGameState());
	
	AKaijuGameMode* GameMode = Cast<AKaijuGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
		GameMode->KaijuSelectMenu->Kyrocdan=this;
}
