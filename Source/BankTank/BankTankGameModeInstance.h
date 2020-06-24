#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EngineUtils.h"
#include "BankTankGameModeInstance.generated.h"

UCLASS()
class BANKTANK_API UBankTankGameModeInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UBankTankGameModeInstance(const FObjectInitializer& ObjectInitializer);

public:
	void OnStart();
	void Tick(float DeltaTime);

};
