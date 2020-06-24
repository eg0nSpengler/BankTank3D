// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWidget.h"
#include "BankTankGameModeBase.h"
#include "GunStatusWidget.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGunStatusDelegate, FString, gunStatus);
UCLASS()
class BANKTANK_API UGunStatusWidget : public UBaseWidget
{
	GENERATED_BODY()
public:
	UGunStatusWidget(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, meta = (BindWidget))
	FString UpdateGunStatus() const; 

	UPROPERTY(BlueprintAssignable)
	FGunStatusDelegate OnGunStatusUpdate;

};
