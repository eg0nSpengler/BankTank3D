// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWidget.h"
#include "ScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class BANKTANK_API UScoreWidget : public UBaseWidget
{
	GENERATED_BODY()

	UScoreWidget(const FObjectInitializer& ObjectInitializer);

public:
	UFUNCTION(BlueprintCallable, meta = (BindWidget))
	int GetScore();
};
