// Fill out your copyright notice in the Description page of Project Settings.
#include "BankTankGameModeInstance.h"

UBankTankGameModeInstance::UBankTankGameModeInstance(const FObjectInitializer& ObjectInitializer)
{

}

void UBankTankGameModeInstance::OnStart()
{
	Super::OnStart();

}

void UBankTankGameModeInstance::Tick(float DeltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("Testing!"));
}

