// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMonsterSightConfig.h"

UAIMonsterSightConfig::UAIMonsterSightConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	this->SightRadius = 5000;
	this->LoseSightRadius = 2000;
	this->PeripheralVisionAngleDegrees = 70;
	this->DetectionByAffiliation.bDetectEnemies = true;
	this->DetectionByAffiliation.bDetectFriendlies = true;
	this->DetectionByAffiliation.bDetectNeutrals = true;
}
