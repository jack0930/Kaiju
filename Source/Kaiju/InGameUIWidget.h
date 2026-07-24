// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KaijuGameStateBase.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "InGameUIWidget.generated.h"

class AKaijuCharacter;
/**
 * 
 */
UCLASS()
class KAIJU_API UInGameUIWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerName;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* EnemyName;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CurrentLevelText;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* EnemyLevelText;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CurrentHealthText;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* EnemyHealthText;
	
	UPROPERTY(meta = (BindWidget))
	UProgressBar* ExpBar;
	
	UPROPERTY(meta = (BindWidget))
	UProgressBar* EnemyExpBar;
    
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MaxExpText;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* EnemyMaxExpText;
    
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CurrentExpText;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* EnemyExpText;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CurrentTurnText;
	
	UPROPERTY()
	AKaijuCharacter* Character;
	
	UPROPERTY()
	AKaijuCharacter* Enemy;
	
	UPROPERTY()
	AKaijuGameStateBase* GameState;
	
	void UpdateValues();
	
	virtual void NativeConstruct() override;
};
