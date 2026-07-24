// Fill out your copyright notice in the Description page of Project Settings.


#include "Aerodactar.h"

#include "Kaiju.h"


AAerodactar::AAerodactar()
{
	CurrentAtk = 10;
	LevelUpExp = 70;
	AtkUp = 10;
}

void AAerodactar::Basic()
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

void AAerodactar::Special()
{
	if (CurrentHealth>100)
	{
		CurrentHealth -= 100;
		Use(UseDistance*3);
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

void AAerodactar::Ultimate()
{
	if (CurrentHealth>800)
	{
		CurrentHealth -= 800;
		Use(UseDistance*3);
		ABuilding* Building = Cast<ABuilding>(HitData.GetActor());
		if (Building)
		{
			Building->DealDamage(CurrentAtk*2,this);
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

void AAerodactar::BeginPlay()
{
	Super::BeginPlay();
	
	GameState = Cast<AKaijuGameStateBase>(GetWorld()->GetGameState());
	
	AKaijuGameMode* GameMode = Cast<AKaijuGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
		GameMode->KaijuSelectMenu->Aerodactar=this;
}