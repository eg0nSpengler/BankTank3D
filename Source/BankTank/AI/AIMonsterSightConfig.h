// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AISenseConfig_Sight.h"
#include "AIMonsterSightConfig.generated.h"

/**
 * 
 */
UCLASS()
class BANKTANK_API UAIMonsterSightConfig : public UAISenseConfig_Sight
{
	GENERATED_BODY()

public:
    UAIMonsterSightConfig(const FObjectInitializer& ObjectInitializer);
};
