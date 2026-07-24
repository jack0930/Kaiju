// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameUIWidget.h"
#include "KaijuCharacter.h"

void UInGameUIWidget::UpdateValues()
{
	if (Character)
	{
		CurrentHealthText->SetText(FText::FromString(FString::FromInt
			(Character->CurrentHealth)));
		
		CurrentLevelText->SetText(FText::FromString(FString::FromInt
			(Character->CurrentLevel)));
		
		ExpBar->SetPercent(Character->CurrentExp /
			Character->LevelUpExp);
		CurrentExpText->SetText(FText::FromString(FString::FromInt
			(Character->CurrentExp)));
		MaxExpText->SetText(FText::FromString(FString::FromInt
			(Character->LevelUpExp)));
	}

	if (Enemy)
	{
		EnemyHealthText->SetText(FText::FromString(FString::FromInt
			(Enemy->CurrentHealth)));
		
		EnemyLevelText->SetText(FText::FromString(FString::FromInt
			(Enemy->CurrentLevel)));
		
		EnemyExpBar->SetPercent(Enemy->CurrentExp /
			Enemy->LevelUpExp);
		EnemyExpText->SetText(FText::FromString(FString::FromInt
			(Enemy->CurrentExp)));
		EnemyMaxExpText->SetText(FText::FromString(FString::FromInt
			(Enemy->LevelUpExp)));
	}
	
	if (GameState)
	{
		CurrentTurnText->SetText(FText::FromString(FString::FromInt
			(GameState->TurnCount)));
		
		PlayerName->SetText(FText::FromString(
			GameState->PlayerKaiju));
		
		EnemyName->SetText(FText::FromString(
			GameState->EnemyKaiju));
	}
}

void UInGameUIWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	GameState = Cast<AKaijuGameStateBase>(GetWorld()->GetGameState());
}
