// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveMenuWidget.h"

#include "Kaiju.h"
#include "KaijuCharacter.h"

void UMoveMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	GameState = Cast<AKaijuGameStateBase>(GetWorld()->GetGameState());
	
	if (BasicButton)
	{
		BasicButton->OnClicked.AddUniqueDynamic(this, &UMoveMenuWidget::Basic);
	}
	if (SpecialButton)
	{
		SpecialButton->OnClicked.AddUniqueDynamic(this, &UMoveMenuWidget::Special);
	}
	if (UltimateButton)
	{
		UltimateButton->OnClicked.AddUniqueDynamic(this, &UMoveMenuWidget::Ultimate);
	}
	if (MoveButton)
	{
		MoveButton->OnClicked.AddUniqueDynamic(this, &UMoveMenuWidget::Move);
	}
	if (UpButton)
	{
		UpButton->OnClicked.AddUniqueDynamic(this, &UMoveMenuWidget::Up);
	}
	if (DownButton)
	{
		DownButton->OnClicked.AddUniqueDynamic(this, &UMoveMenuWidget::Down);
	}
	if (LeftButton)
	{
		LeftButton->OnClicked.AddUniqueDynamic(this, &UMoveMenuWidget::Left);
	}
	if (RightButton)
	{
		RightButton->OnClicked.AddUniqueDynamic(this, &UMoveMenuWidget::Right);
	}
	
}

void UMoveMenuWidget::Basic()
{
	RemoveFromParent();
	Character->Basic();
	Character->InGameUIMenu->UpdateValues();
}

void UMoveMenuWidget::Special()
{
	RemoveFromParent();
	Character->Special();
	Character->InGameUIMenu->UpdateValues();
}

void UMoveMenuWidget::Ultimate()
{
	RemoveFromParent();
	Character->Ultimate();
	Character->InGameUIMenu->UpdateValues();
}

void UMoveMenuWidget::Move()
{
	RemoveFromParent();
	Character->Move();
	Character->InGameUIMenu->UpdateValues();
}

void UMoveMenuWidget::Up()
{
	Character->SetActorRotation(FRotator(0,0,0));
}

void UMoveMenuWidget::Down()
{
	Character->SetActorRotation(FRotator(0,180,0));
}

void UMoveMenuWidget::Left()
{
	Character->SetActorRotation(FRotator(0,-90,0));
}

void UMoveMenuWidget::Right()
{
	Character->SetActorRotation(FRotator(0,90,0));
}
