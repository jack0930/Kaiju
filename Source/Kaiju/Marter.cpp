// Fill out your copyright notice in the Description page of Project Settings.


#include "Marter.h"

#include "Kaiju.h"


AMarter::AMarter()
{
	CurrentAtk = 10;
	LevelUpExp = 100;
	AtkUp = 20;
}

void AMarter::Basic()
{
	if (CurrentHealth>20)
	{
		CurrentHealth -= 20;
		Use(UseDistance*2);
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

void AMarter::Special()
{
	if (CurrentHealth>120)
	{
		CurrentHealth -= 120;
		Use(UseDistance*5);
		ABuilding* Building = Cast<ABuilding>(HitData.GetActor());
		if (Building)
		{
			Building->DealDamage(CurrentAtk*1.2,this);
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

void AMarter::Ultimate()
{
	if (CurrentHealth>1000)
	{
		CurrentHealth -= 1000;
		Use(UseDistance*3);
		ABuilding* Building = Cast<ABuilding>(HitData.GetActor());
		if (Building)
		{
			Building->DealDamage(CurrentAtk*1.2,this);
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


void AMarter::BeginPlay()
{
	Super::BeginPlay();
	
	GameState = Cast<AKaijuGameStateBase>(GetWorld()->GetGameState());
	
	AKaijuGameMode* GameMode = Cast<AKaijuGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
		GameMode->KaijuSelectMenu->Marter=this;
}