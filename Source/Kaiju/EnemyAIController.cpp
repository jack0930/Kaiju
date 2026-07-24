// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kaiju.h"
#include "KaijuCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"


void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	
	UseBlackboard(AIBlackboard, BlackboardComponent);
	RunBehaviorTree(BehaviourTree);
	
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValueAsBool("EnemyTurn",false);
		BlackboardComponent->SetValueAsBool("CanUltimate",false);
		BlackboardComponent->SetValueAsBool("CanSpecial",false);
		BlackboardComponent->SetValueAsBool("CanBasic",false);
		BlackboardComponent->SetValueAsBool("CanMove",false);
	}
}

void AEnemyAIController::EnemyTurn()
{
	if (CurrentPawn == nullptr)
		CurrentPawn = Cast<AKaijuCharacter>(GetPawn());
	
	if (BlackboardComponent)
	{
		UE_LOG(LogKaiju, Error, TEXT("Enemy's Turn"));
		BlackboardComponent->SetValueAsBool("EnemyTurn",true);
	}
	
	do
	{
		
	}while (false);
	
	EnmemyBasic();
}

void AEnemyAIController::EnmemyBasic()
{
	if (CurrentPawn)
	{
		UE_LOG(LogKaiju, Error, TEXT("Enemy use basic"));
		CurrentPawn->Basic();
	}
	if (CurrentPawn->MoveCount<2)
		EnemyTurn();
	else
	{
		CurrentPawn->MoveCount = 1;
		if (Player)
		{
			UE_LOG(LogKaiju, Error, TEXT("Player's Turn"));
			BlackboardComponent->SetValueAsBool("EnemyTurn",false);
			Player->bCharacterTurn = true;
		}
	}
}

void AEnemyAIController::EnmemySpecial()
{
	if (CurrentPawn)
	{
		UE_LOG(LogKaiju, Error, TEXT("Enemy use basic"));
		CurrentPawn->Special();
	}
	if (CurrentPawn->MoveCount<2)
		EnemyTurn();
	else
	{
		CurrentPawn->MoveCount = 1;
		if (Player)
		{
			UE_LOG(LogKaiju, Error, TEXT("Player's Turn"));
			BlackboardComponent->SetValueAsBool("EnemyTurn",false);
			Player->bCharacterTurn = true;
		}
	}
}

void AEnemyAIController::EnmemyUltimate()
{
	if (CurrentPawn)
	{
		UE_LOG(LogKaiju, Error, TEXT("Enemy use basic"));
		CurrentPawn->Ultimate();
	}
	if (CurrentPawn->MoveCount<2)
		EnemyTurn();
	else
	{
		CurrentPawn->MoveCount = 1;
		if (Player)
		{
			UE_LOG(LogKaiju, Error, TEXT("Player's Turn"));
			BlackboardComponent->SetValueAsBool("EnemyTurn",false);
			Player->bCharacterTurn = true;
		}
	}
}

void AEnemyAIController::EnmemyMove()
{
	if (CurrentPawn)
	{
		UE_LOG(LogKaiju, Error, TEXT("Enemy use basic"));
		CurrentPawn->Move();
	}
	if (CurrentPawn->MoveCount<2)
		EnemyTurn();
	else
	{
		CurrentPawn->MoveCount = 1;
		if (Player)
		{
			UE_LOG(LogKaiju, Error, TEXT("Player's Turn"));
			BlackboardComponent->SetValueAsBool("EnemyTurn",false);
			Player->bCharacterTurn = true;
		}
	}
}
