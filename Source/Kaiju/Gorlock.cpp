// Fill out your copyright notice in the Description page of Project Settings.


#include "Gorlock.h"

#include "Kaiju.h"


AGorlock::AGorlock()
{
	CurrentAtk = 10;
	LevelUpExp = 100;
	AtkUp = 20;
	CurrentHealth = 200;
}

void AGorlock::Basic()
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

void AGorlock::Special()
{
	if (CurrentHealth>120)
	{
		CurrentHealth -= 120;
		Use(UseDistance*2);
		ABuilding* Building = Cast<ABuilding>(HitData.GetActor());
		if (Building)
		{
			Building->DealDamage(CurrentAtk*1.1,this);
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

void AGorlock::Ultimate()
{
	if (CurrentHealth>1000)
	{
		CurrentHealth -= 1000;
		Use(UseDistance);
		ABuilding* Building = Cast<ABuilding>(HitData.GetActor());
		if (Building)
		{
			Building->DealDamage(CurrentAtk*1,this);
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

void AGorlock::BeginPlay()
{
	Super::BeginPlay();
	
	GameState = Cast<AKaijuGameStateBase>(GetWorld()->GetGameState());
	
	AKaijuGameMode* GameMode = Cast<AKaijuGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
		GameMode->KaijuSelectMenu->Gorlock=this;
}