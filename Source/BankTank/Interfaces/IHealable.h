// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IHealable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIHealable : public UInterface
{
	GENERATED_BODY()
};

class BANKTANK_API IIHealable
{
	GENERATED_BODY()

public:
	virtual void TakeDamage() = 0;

};
