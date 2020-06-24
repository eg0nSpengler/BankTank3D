// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "AIMonsterSightConfig.h"
#include "AIMonsterPerceptionComponent.generated.h"

/**
 * 
 */
UCLASS()
class BANKTANK_API UAIMonsterPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()

public:
	UAIMonsterPerceptionComponent();
	
private:
	UPROPERTY()
	UAIMonsterSightConfig* SightConfig;
};
