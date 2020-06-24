// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMonsterPerceptionComponent.h"

UAIMonsterPerceptionComponent::UAIMonsterPerceptionComponent()
{
	SightConfig = CreateDefaultSubobject<UAIMonsterSightConfig>(TEXT("Sight Config"));
	this->ConfigureSense(*SightConfig);
	this->SetDominantSense(SightConfig->GetSenseImplementation());
}
