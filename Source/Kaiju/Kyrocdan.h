// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KaijuCharacter.h"
#include "Kyrocdan.generated.h"

/**
 * 
 */
UCLASS()
class KAIJU_API AKyrocdan : public AKaijuCharacter
{
	GENERATED_BODY()
	
public:
	
	AKyrocdan();
	
	virtual void Basic()override;
	
	virtual void Special()override;
	
	virtual void Ultimate()override;
	
private:
	virtual void BeginPlay() override;;
};
