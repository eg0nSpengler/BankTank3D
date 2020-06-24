// Fill out your copyright notice in the Description page of Project Settings.
#include "BankTankGameModeBase.h"
#include "BankTank.h"

FString ABankTankGameModeBase::GetPawnGunStatus()
{
	for (const auto& pawn : pawnList)
	{
		if (pawn->ActorHasTag("Player"))
		{
			UE_LOG(LogTemp, Warning, TEXT("Found the player!"));
			return "Player found!";
		}
	}
	return "UNKNOWN";
}

void ABankTankGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	mapTimeLeft = 0;
	totalMapCoins = 0;
	totalScore = 0;
	coinsCollected = 0;

	for (TActorIterator<APawn> pawnItr(GetWorld()); pawnItr; ++pawnItr)
	{
		pawnList.Add(*pawnItr);
		UE_LOG(LogContainerAddition, Display, TEXT("Added %s to pawnList."), *pawnItr->GetName());
	}


	UE_LOG(LogContainerQuery, Display, TEXT("The current map contains %d pawn(s)"), pawnList.Num());

	for (TActorIterator<ACoinActor> coinItr(GetWorld()); coinItr; ++coinItr)
	{
		coinList.Add(*coinItr);
		UE_LOG(LogContainerAddition, Display, TEXT("Added %s to the coinList."), *coinItr->GetName());
	}
	totalMapCoins = coinList.Num();

	UE_LOG(LogContainerQuery, Display, TEXT("The current map has %d coins"), coinList.Num());

	for (TActorIterator<ATriggerBox> portalTrigItr(GetWorld()); portalTrigItr; ++portalTrigItr)
	{
		portalTrigger = *portalTrigItr;
		UE_LOG(LogTemp, Display, TEXT("Successfully referenced %s Trigger Box!"), *portalTrigger->GetName());
	}
	auto funcName = GET_FUNCTION_NAME_CHECKED(ABankTankGameModeBase, GetNumCoinsInLevel);
	auto funcName2 = GET_FUNCTION_NAME_CHECKED(ABankTankGameModeBase, DelegateTestFunc);

	OnTestDelegate.BindUFunction(this, funcName2);
	OnTestDelegate.ExecuteIfBound();

	gameState = GAMESTATE::GAME_PLAY;

	GetWorld()->GetTimerManager().SetTimer(LevelTimerHandle, this, &ABankTankGameModeBase::ResetLevel, mapTime, false);

}

void ABankTankGameModeBase::ResetLevel()
{
	if (gameState == GAMESTATE::GAME_RESET)
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName(), false));
		coinsCollected = 0;
	}
	else
	{
		return;
	}
}

void ABankTankGameModeBase::CalculateScore()
{
	if (gameState == GAMESTATE::GAME_POST_BRIEFING)
	{
		if (coinsCollected <= 0 && mapTimeLeft >= 1)
		{
			totalScore = mapTimeLeft * SCORE_TIME_BONUS;
			UE_LOG(LogTemp, Display, TEXT("The total score is %d"), totalScore);
		}
		else
		{
			totalScore = (coinsCollected * SCORE_COIN_BONUS) + (mapTimeLeft * SCORE_TIME_BONUS);
			UE_LOG(LogTemp, Display, TEXT("The total score is %d"), totalScore);
		}
	}
}

void ABankTankGameModeBase::ShowPortal()
{
	if (!portalTrigger)
	{
		UE_LOG(LogTemp, Error, TEXT("No Portal Trigger placed within current level!"));
		return;
	}
	
	portalTrigger->SetActorHiddenInGame(false);
	UE_LOG(LogTemp, Display, TEXT("TODO Portal Trigger Logic"));
}

int ABankTankGameModeBase::GetNumCoinsInLevel() const
{
	return coinList.Num();
}

int ABankTankGameModeBase::GetScore() const
{
	return totalScore;
}

void ABankTankGameModeBase::RemovePawnFromList(APawn* pawn)
{
	if (!pawn)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to remove pawn!"));
		return;
	}

	UE_LOG(LogContainerRemoval, Warning, TEXT("Removed %s from PawnList!"), *pawn->GetName());
	pawnList.RemoveSwap(pawn);
	UE_LOG(LogContainerQuery, Warning, TEXT("The PawnList now contains %d elements"), pawnList.Num());
}

void ABankTankGameModeBase::RemoveCoinFromList(ACoinActor* coin)
{
	if (!coin)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to remove coin!"));
		return;
		
	}

	coinsCollected++;
	coinList.RemoveSwap(coin);

	if (coinList.Num() <= 0)
	{
		ShowPortal();
	}
}

void ABankTankGameModeBase::DelegateTestFunc()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString("Delegate Test Function called"));
	}
}
