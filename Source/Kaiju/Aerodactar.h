// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KaijuCharacter.h"
#include "Aerodactar.generated.h"

/**
 * 
 */
UCLASS()
class KAIJU_API AAerodactar : public AKaijuCharacter
{
	GENERATED_BODY()
	
public:
	
	AAerodactar();
	
	virtual void Basic()override;
	
	virtual void Special()override;
	
	virtual void Ultimate()override;

private:
	virtual void BeginPlay() override;;
};
