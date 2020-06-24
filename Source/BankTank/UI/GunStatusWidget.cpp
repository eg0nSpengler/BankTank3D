// Fill out your copyright notice in the Description page of Project Settings.


#include "GunStatusWidget.h"

UGunStatusWidget::UGunStatusWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

FString UGunStatusWidget::UpdateGunStatus() const
{
	ATankPawn* tankPawn = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	return tankPawn->GunStatusToFString();
}

