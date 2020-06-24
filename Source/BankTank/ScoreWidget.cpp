// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"
#include "BankTankGameModeBase.h"

UScoreWidget::UScoreWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

int UScoreWidget::GetScore()
{
	ABankTankGameModeBase* GMBase = Cast<ABankTankGameModeBase>(GetWorld()->GetAuthGameMode());
	return GMBase->GetScore();
}
