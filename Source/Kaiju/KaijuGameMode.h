// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "KaijuGameStateBase.h"
#include "KaijuSelectWidget.h"
#include "GameFramework/GameModeBase.h"
#include "KaijuGameMode.generated.h"

/**
 *  Simple Game Mode for a top-down perspective game
 *  Sets the default gameplay framework classes
 *  Check the Blueprint derived class for the set values
 */
UCLASS(abstract)
class AKaijuGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	/** Constructor */
	AKaijuGameMode();
	
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UKaijuSelectWidget> KaijuSelectClass;
	
	UPROPERTY()
	UKaijuSelectWidget* KaijuSelectMenu;
};



