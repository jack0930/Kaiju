// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class AKaijuCharacter;
/**
 * 
 */
UCLASS()
class KAIJU_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	
	virtual void BeginPlay();
	
	UPROPERTY(EditAnywhere)
	UBlackboardData* AIBlackboard;
	
	UPROPERTY(EditAnywhere)
	UBehaviorTree* BehaviourTree;
	
	UPROPERTY()
	UBlackboardComponent* BlackboardComponent;
	
	UPROPERTY()
	AKaijuCharacter* Player;
	
	UPROPERTY()
	AKaijuCharacter* CurrentPawn;
	
	UPROPERTY()
    int EnemyCharacterIndex;
	
	void EnemyTurn();
	
	UFUNCTION()
	void EnmemyBasic();
	
	UFUNCTION()
	void EnmemySpecial();
	
	UFUNCTION()
	void EnmemyUltimate();
	
	UFUNCTION()
	void EnmemyMove();
};
