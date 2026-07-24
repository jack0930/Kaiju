// Fill out your copyright notice in the Description page of Project Settings.


#include "KaijuSelectWidget.h"

#include "Aerodactar.h"
#include "EnemyAIController.h"
#include "Gorlock.h"
#include "Kaiju.h"
#include "Kyrocdan.h"
#include "Marter.h"
#include "Kismet/GameplayStatics.h"

void UKaijuSelectWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	GameState = Cast<AKaijuGameStateBase>(GetWorld()->GetGameState());
	
	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this,
			&UKaijuSelectWidget::CloseMenu);
	}
	if (AerodactarButton)
	{
		if (GameState) 
			AerodactarButton->OnClicked.AddUniqueDynamic(this,
				&UKaijuSelectWidget::SetAerodactar);
	}
	if (KyrocdanButton)
	{
		if (GameState) 
			KyrocdanButton->OnClicked.AddUniqueDynamic(this,
				&UKaijuSelectWidget::SetKyrocdan);
	}
	if (MarterButton)
	{
		if (GameState)
			MarterButton->OnClicked.AddUniqueDynamic(this,
				&UKaijuSelectWidget::SetMarter);
	}
	if (GorlockButton)
	{
		if (GameState)
			GorlockButton->OnClicked.AddUniqueDynamic(this,
				&UKaijuSelectWidget::SetGorlock);
	}
}

void UKaijuSelectWidget::CloseMenu()
{
	UGameplayStatics::OpenLevel(this, TEXT("MainMenu"));
	RemoveFromParent();
}

void UKaijuSelectWidget::SetAerodactar()
{
	if (!GameState) return;;
	
	GameState->PlayerKaiju = Kaiju[0];
	
	if (GameState->PlayerKaiju.IsEmpty()) return;
	
	UE_LOG(LogKaiju, Error, TEXT("Player is playing : %s"),*FString(GameState->PlayerKaiju));
	
	if (Aerodactar)
	{
		Aerodactar->SetActorLocation(Aerodactar->SpawnLocation);
		GetWorld()->GetFirstPlayerController()->UnPossess();
		GetWorld()->GetFirstPlayerController()->Possess(Aerodactar);
		
		if (Aerodactar->InGameUIMenuClass)
		{
			Aerodactar->InGameUIMenu =
				Cast<UInGameUIWidget>(CreateWidget(GetGameInstance(), Aerodactar->InGameUIMenuClass));
			
			Aerodactar->InGameUIMenu->Character = Aerodactar;
			Aerodactar->InGameUIMenu->UpdateValues();
			Aerodactar->InGameUIMenu->AddToViewport();
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("InGameUIMenu does not exist"));
		}
		
		if (Aerodactar->MoveMenuClass)
		{
			Aerodactar->MoveMenu =
				Cast<UMoveMenuWidget>(CreateWidget(GetGameInstance(), Aerodactar->MoveMenuClass));
			
			Aerodactar->MoveMenu->Character = Aerodactar;
			Aerodactar->MoveMenu->AddToViewport();
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("MoveMenu does not exist"));
		}

		SetEnemy(Aerodactar);
		
		switch (Enemy)
		{
		case 1:
			Aerodactar->Enemy = Cast<AEnemyAIController>(Kyrocdan->GetController());
			break;
			
		case 2:
			Aerodactar->Enemy = Cast<AEnemyAIController>(Marter->GetController());
			break;
		case 3:
			Aerodactar->Enemy = Cast<AEnemyAIController>(Gorlock->GetController());
			break;
			
		default:
			break;
		}
	}
	else
	{
		UE_LOG(LogKaiju, Error, TEXT("Aerodactar does not exist"));
	}
	
	RemoveFromParent();
	
	GetWorld()->GetFirstPlayerController()->
		SetInputMode(FInputModeGameOnly());
	
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
}

void UKaijuSelectWidget::SetKyrocdan()
{
	if (!GameState) return;;
	
	GameState->PlayerKaiju = Kaiju[1];
	
	if (GameState->PlayerKaiju.IsEmpty()) return;
	
	UE_LOG(LogKaiju, Error, TEXT("Player is playing : %s"),*FString(GameState->PlayerKaiju));
	
	if (Kyrocdan)
	{
		Kyrocdan->SetActorLocation(Kyrocdan->SpawnLocation);
		GetWorld()->GetFirstPlayerController()->UnPossess();
		GetWorld()->GetFirstPlayerController()->Possess(Kyrocdan);
		
		if (Kyrocdan->InGameUIMenuClass)
		{
			Kyrocdan->InGameUIMenu =
				Cast<UInGameUIWidget>(CreateWidget(GetGameInstance(), Kyrocdan->InGameUIMenuClass));
			
			Kyrocdan->InGameUIMenu->Character = Kyrocdan;
			Kyrocdan->InGameUIMenu->UpdateValues();
			Kyrocdan->InGameUIMenu->AddToViewport();
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("InGameUIMenu does not exist"));
		}
		
		if (Kyrocdan->MoveMenuClass)
		{
			Kyrocdan->MoveMenu =
				Cast<UMoveMenuWidget>(CreateWidget(GetGameInstance(), Kyrocdan->MoveMenuClass));
			
			Kyrocdan->MoveMenu->Character = Kyrocdan;
			Kyrocdan->MoveMenu->AddToViewport();
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("MoveMenu does not exist"));
		}
		
		SetEnemy(Kyrocdan);
		
		switch (Enemy)
		{
		case 0:
			Kyrocdan->Enemy = Cast<AEnemyAIController>(Aerodactar->GetController());
			break;
			
		case 2:
			Kyrocdan->Enemy = Cast<AEnemyAIController>(Marter->GetController());
			break;
		case 3:
			Kyrocdan->Enemy = Cast<AEnemyAIController>(Gorlock->GetController());
			break;
			
		default:
			break;
		}
	}
	else
	{
		UE_LOG(LogKaiju, Error, TEXT("Kyrocdan does not exist"));
	}
	
	GetWorld()->GetFirstPlayerController()->
		SetInputMode(FInputModeGameOnly());
	
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
	
	RemoveFromParent();
	
}

void UKaijuSelectWidget::SetMarter()
{
	if (!GameState) return;;
	
	GameState->PlayerKaiju = Kaiju[2];
	
	if (GameState->PlayerKaiju.IsEmpty()) return;
	
	UE_LOG(LogKaiju, Error, TEXT("Player is playing : %s"),*FString(GameState->PlayerKaiju));
			
	if (Marter)
	{
		Marter->SetActorLocation(Marter->SpawnLocation);
		GetWorld()->GetFirstPlayerController()->UnPossess();
		GetWorld()->GetFirstPlayerController()->Possess(Marter);
		
		if (Marter->InGameUIMenuClass)
		{
			Marter->InGameUIMenu =
				Cast<UInGameUIWidget>(CreateWidget(GetGameInstance(), Marter->InGameUIMenuClass));
			
			Marter->InGameUIMenu->Character = Marter;
			Marter->InGameUIMenu->UpdateValues();
			Marter->InGameUIMenu->AddToViewport();
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("InGameUIMenu does not exist"));
		}
		
		if (Marter->MoveMenuClass)
		{
			Marter->MoveMenu =
				Cast<UMoveMenuWidget>(CreateWidget(GetGameInstance(), Marter->MoveMenuClass));
			
			Marter->MoveMenu->Character = Marter;
			Marter->MoveMenu->AddToViewport();
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("MoveMenu does not exist"));
		}
		
		SetEnemy(Marter);
		
		switch (Enemy)
		{
		case 1:
			Marter->Enemy = Cast<AEnemyAIController>(Kyrocdan->GetController());
			break;
			
		case 0:
			Marter->Enemy = Cast<AEnemyAIController>(Aerodactar->GetController());
			break;
		case 3:
			Marter->Enemy = Cast<AEnemyAIController>(Gorlock->GetController());
			break;
			
		default:
			break;
		}
	}
	else
	{
		UE_LOG(LogKaiju, Error, TEXT("Marter does not exist"));
	}
	
	RemoveFromParent();
	
	GetWorld()->GetFirstPlayerController()->
		SetInputMode(FInputModeGameOnly());
	
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
}

void UKaijuSelectWidget::SetGorlock()
{
	if (!GameState) return;;
	
	GameState->PlayerKaiju = Kaiju[3];
	
	if (GameState->PlayerKaiju.IsEmpty()) return;
	
	UE_LOG(LogKaiju, Error, TEXT("Player is playing : %s"),*FString(GameState->PlayerKaiju));
	
	if (Gorlock)
	{
		Gorlock->SetActorLocation(Gorlock->SpawnLocation);
		GetWorld()->GetFirstPlayerController()->UnPossess();
		GetWorld()->GetFirstPlayerController()->Possess(Gorlock);
		
		if (Gorlock->InGameUIMenuClass)
		{
			Gorlock->InGameUIMenu =
				Cast<UInGameUIWidget>(CreateWidget(GetGameInstance(), Gorlock->InGameUIMenuClass));
			
			Gorlock->InGameUIMenu->Character = Gorlock;
			Gorlock->InGameUIMenu->UpdateValues();
			Gorlock->InGameUIMenu->AddToViewport();
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("InGameUIMenu does not exist"));
		}
		
		if (Gorlock->MoveMenuClass)
		{
			Gorlock->MoveMenu =
				Cast<UMoveMenuWidget>(CreateWidget(GetGameInstance(), Gorlock->MoveMenuClass));
			
			Gorlock->MoveMenu->Character = Gorlock;
			Gorlock->MoveMenu->AddToViewport();
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("MoveMenu does not exist"));
		}
		
		SetEnemy(Gorlock);
		
		switch (Enemy)
		{
		case 1:
			Gorlock->Enemy = Cast<AEnemyAIController>(Kyrocdan->GetController());
			break;
			
		case 2:
			Gorlock->Enemy = Cast<AEnemyAIController>(Marter->GetController());
			break;
		case 0:
			Gorlock->Enemy = Cast<AEnemyAIController>(Aerodactar->GetController());
			break;
			
		default:
			break;
		}
	}
	else
	{
		UE_LOG(LogKaiju, Error, TEXT("Gorlock does not exist"));
	}
	
	RemoveFromParent();
	
	GetWorld()->GetFirstPlayerController()->
		SetInputMode(FInputModeGameOnly());
	
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
}

void UKaijuSelectWidget::SetEnemy(AKaijuCharacter* Player)
{
	if (!GameState) return;
	
	do
	{
		Enemy = FMath::RandRange(0,3);
		GameState->EnemyKaiju = Kaiju[Enemy];
	}
	while (GameState->PlayerKaiju == GameState->EnemyKaiju);

	switch (Enemy)
	{
	case 0:
		if (Aerodactar)
		{
			AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(
				Aerodactar->GetController());
			
			Aerodactar->SetActorLocation(Aerodactar->EnemySpawnLocation);
			Aerodactar->SetActorRotation(FRotator(0,180,0));
			if (Player->InGameUIMenu)
				Player->InGameUIMenu->Enemy = Aerodactar;
			
			if (EnemyAIController)
			{
				EnemyAIController->UnPossess();
				EnemyAIController->Possess(Aerodactar);
				EnemyAIController->EnemyCharacterIndex = Enemy;
				EnemyAIController->Player = Player;
			}
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("Aerodactar does not exist"));
		}
		break;
		
	case 1:
		if (Kyrocdan)
		{
			AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(
				Kyrocdan->GetController());
			
			Kyrocdan->SetActorLocation(Kyrocdan->EnemySpawnLocation);
			Kyrocdan->SetActorRotation(FRotator(0,180,0));
			if (Player->InGameUIMenu)
				Player->InGameUIMenu->Enemy = Kyrocdan;
			
			if (EnemyAIController)
			{
				EnemyAIController->UnPossess();
				EnemyAIController->Possess(Kyrocdan);
				EnemyAIController->EnemyCharacterIndex = Enemy;
				EnemyAIController->Player = Player;
			}
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("Kyrocdan does not exist"));
		}
		break;
		
	case 2:
		if (Marter)
		{
			AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(
				Marter->GetController());
			
			Marter->SetActorLocation(Marter->EnemySpawnLocation);
			Marter->SetActorRotation(FRotator(0,180,0));
			if (Player->InGameUIMenu)
				Player->InGameUIMenu->Enemy = Marter;
			
			if (EnemyAIController)
			{
				EnemyAIController->UnPossess();
				EnemyAIController->Possess(Marter);
				EnemyAIController->EnemyCharacterIndex = Enemy;
				EnemyAIController->Player = Player;
			}
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("Marter does not exist"));
		}
		break;
		
	case 3:
		if (Gorlock)
		{
			AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(
				Gorlock->GetController());
			
			Gorlock->SetActorLocation(Gorlock->EnemySpawnLocation);
			Gorlock->SetActorRotation(FRotator(0,180,0));
			if (Player->InGameUIMenu)
				Player->InGameUIMenu->Enemy = Gorlock;
			
			if (EnemyAIController)
			{
				EnemyAIController->UnPossess();
				EnemyAIController->Possess(Gorlock);
				EnemyAIController->EnemyCharacterIndex = Enemy;
				EnemyAIController->Player = Player;
			}
		}
		else
		{
			UE_LOG(LogKaiju, Error, TEXT("Gorlock does not exist"));
		}
		break;
		
	default:
		UE_LOG(LogKaiju, Error, TEXT("Enemy does not exist"));
		break;
	}
	
	UE_LOG(LogKaiju, Error, TEXT("Enemy is playing : %s"),*FString(GameState->EnemyKaiju));
}

