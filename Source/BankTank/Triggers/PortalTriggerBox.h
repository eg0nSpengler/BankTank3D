// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Engine.h"
#include "DrawDebugHelpers.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Classes/Components//AudioComponent.h"
#include "PortalTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class BANKTANK_API APortalTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	APortalTriggerBox();

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	virtual void PostActorCreated() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* c_StaticMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	UAudioComponent* c_AudioComponent;

};
