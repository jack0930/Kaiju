// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "KaijuGameStateBase.h"
#include "KaijuSelectWidget.h"
#include "MoveMenuWidget.h"
#include "GameFramework/Character.h"
#include "KaijuGameMode.h"
#include "Building.h"
#include "EnemyAIController.h"
#include "InGameUIWidget.h"
#include "KaijuCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 *  A controllable top-down perspective character
 */
UCLASS(abstract)
class AKaijuCharacter : public ACharacter
{
	GENERATED_BODY()

private:

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

public:

	/** Constructor */
	AKaijuCharacter();

	/** Initialization */
	virtual void BeginPlay() override;

	/** Update */
	virtual void Tick(float DeltaSeconds) override;

	/** Returns the camera component **/
	UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent.Get(); }

	/** Returns the Camera Boom component **/
	USpringArmComponent* GetCameraBoom() const { return CameraBoom.Get(); }

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHealth = 100;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentLevel = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentAtk = 20;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AtkUp = 20;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentExp = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LevelUpExp = 100;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UKaijuSelectWidget* KaijuMenu;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UMoveMenuWidget> MoveMenuClass;
	
	UPROPERTY()
	UMoveMenuWidget* MoveMenu;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UInGameUIWidget> InGameUIMenuClass;
	
	UPROPERTY()
	UInGameUIWidget* InGameUIMenu;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector SpawnLocation = FVector(-2260.000000,-2250.000000,96.000000);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector EnemySpawnLocation = FVector (2240.000000,2250.000000,96.000000);
	
	UPROPERTY()
	AKaijuGameStateBase* GameState;
	
	UPROPERTY()
	FHitResult HitData;
	
	int MoveCount = 1;
	
	bool bCharacterTurn = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AEnemyAIController* Enemy;
	
	UFUNCTION()
	void DealDamage(float Damage);

	UFUNCTION()
	virtual void Basic();
	
	UFUNCTION()
	virtual void Special();
	
	UFUNCTION()
	virtual void Ultimate();
	
	UFUNCTION()
	void Move();
	
	UFUNCTION()
	void LevelUp();
	
	UPROPERTY(EditAnywhere)
	float UseDistance = 300;
	
	UFUNCTION()
	void Use(float Distance);
};

