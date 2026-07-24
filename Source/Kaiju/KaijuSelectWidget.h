// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "KaijuGameStateBase.h"
#include "KaijuSelectWidget.generated.h"

class AKaijuCharacter;
class AAerodactar;
class AKyrocdan;
class AMarter;
class AGorlock;
UCLASS()
class KAIJU_API UKaijuSelectWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta=(BindWidget))
	UButton* BackButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* AerodactarButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* KyrocdanButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* MarterButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* GorlockButton;
	
	UPROPERTY()
	AAerodactar* Aerodactar;
	
	UPROPERTY()
	AKyrocdan* Kyrocdan;
	
	UPROPERTY()
	AMarter* Marter;
	
	UPROPERTY()
	AGorlock* Gorlock;
	
	UPROPERTY()
	AKaijuGameStateBase* GameState;
	
	FString Kaiju[4] = {
		"Aerodactar",
		"Kyrocdan",
		"Marter",
		"Gorlock"
	};
	
	int Enemy;
	
	virtual void NativeConstruct() override;
	
	UFUNCTION()
	void CloseMenu();
	
	UFUNCTION()
	void SetAerodactar();
	
	UFUNCTION()
	void SetKyrocdan();
	
	UFUNCTION()
	void SetMarter();
	
	UFUNCTION()
	void SetGorlock();
	
	UFUNCTION()
	void SetEnemy(AKaijuCharacter* Player);
};
