// Copyright Epic Games, Inc. All Rights Reserved.

#include "KaijuGameMode.h"

#include "Blueprint/UserWidget.h"
#include "GameFramework/GameState.h"

AKaijuGameMode::AKaijuGameMode()
{
	// stub
}

void AKaijuGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	if (KaijuSelectClass)
	{
		KaijuSelectMenu =
			Cast<UKaijuSelectWidget>(CreateWidget(GetGameInstance(), KaijuSelectClass));

		GetWorld()->GetFirstPlayerController()->
			SetInputMode(FInputModeUIOnly());
		
		GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
		KaijuSelectMenu->AddToViewport();
	}
}