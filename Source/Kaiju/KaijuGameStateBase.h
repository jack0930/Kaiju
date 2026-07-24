// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "KaijuGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class KAIJU_API AKaijuGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	
	int TurnCount = 1;
	
	FString PlayerKaiju = "";
	
	FString EnemyKaiju = "";
};
