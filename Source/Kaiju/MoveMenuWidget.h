// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KaijuGameStateBase.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MoveMenuWidget.generated.h"

class AKaijuCharacter;
/**
 * 
 */
UCLASS()
class KAIJU_API UMoveMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta=(BindWidget))
	UButton* BasicButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* SpecialButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* UltimateButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* MoveButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* UpButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* DownButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* LeftButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* RightButton;
	
	UPROPERTY()
	AKaijuCharacter* Character;
	
	UPROPERTY()
	AKaijuGameStateBase* GameState;
	
	virtual void NativeConstruct() override;
	
	UFUNCTION()
	virtual void Basic();
	
	UFUNCTION()
	virtual void Special();
	
	UFUNCTION()
	virtual void Ultimate();
	
	UFUNCTION()
	void Move();
	
	UFUNCTION()
	virtual void Up();
	
	UFUNCTION()
	virtual void Down();
	
	UFUNCTION()
	virtual void Left();
	
	UFUNCTION()
	virtual void Right();
};
