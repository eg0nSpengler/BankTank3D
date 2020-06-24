
#pragma once
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "GameFramework/GameModeBase.h"
#include "CoinActor.h"
#include "TankPawn.h"
#include "Engine/TriggerBox.h"
#include "Delegates/Delegate.h"
#include "BankTankGameModeBase.generated.h"

enum class GAMESTATE
{
	GAME_PLAY,
	GAME_END,
	GAME_RESET,
	GAME_BRIEFING,
	GAME_POST_BRIEFING,
};


DECLARE_DYNAMIC_DELEGATE(FDynTestDelegate);
UCLASS()
class BANKTANK_API ABankTankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void DelegateTestFunc();

	UFUNCTION()
	void RemoveCoinFromList(ACoinActor* coin);

	UFUNCTION()
	void RemovePawnFromList(APawn* pawn);

	UFUNCTION()
	int GetNumCoinsInLevel() const;

	UFUNCTION()
	int GetScore() const;

	FDynTestDelegate OnTestDelegate;

private:
	void BeginPlay();
	void ResetLevel();
	void CalculateScore();
	void ShowPortal();
	FString GetPawnGunStatus();

private:
	UPROPERTY()
	TArray<APawn*> pawnList;

	UPROPERTY()
	TArray<ACoinActor*> coinList;

	UPROPERTY()
	ATriggerBox* portalTrigger;

	UPROPERTY()
	APawn* playerPawn;

private:
	GAMESTATE gameState;
	const int SCORE_TIME_BONUS = 100;
	const int SCORE_COIN_BONUS = 10000;
	const float mapTime = 10.0f;
	int mapTimeLeft;
	int totalMapCoins;
	int totalScore;
	int coinsCollected;
	FTimerHandle LevelTimerHandle;
	
	
	
};
