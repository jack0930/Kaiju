// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Building.generated.h"

class AKaijuCharacter;

UCLASS()
class KAIJU_API ABuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHealth = 100;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GiveExp = 25;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GiveHealth = 50;
	
	UFUNCTION()
	void DealDamage(float Damage, AKaijuCharacter* Attacker);

};
