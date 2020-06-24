// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Classes/Components/InputComponent.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Classes/GameFramework/FloatingPawnMovement.h"
#include "Classes/Camera/CameraComponent.h"
#include "Classes/Components/AudioComponent.h"
#include "Classes/Engine/World.h"
#include "TankProjectileActor.h"
#include "CoinActor.h"
#include "HealthActorComponent.h"
#include "Engine.h"
#include "TankPawn.generated.h"

DECLARE_DELEGATE(FGunStatusUpdateDelegate);
DECLARE_DELEGATE(FGunChargeDelegate);
DECLARE_DELEGATE(FGunReadyDelegate);
UCLASS()
class BANKTANK_API ATankPawn : public APawn
{
	GENERATED_BODY()

	enum class GUN_STATUS
	{
		NONE,
		READY,
		REARMING,
		CHARGING,
		MAX_POWER
	};

public:
	// Sets default values for this pawn's properties
	ATankPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float value);
	void TurnLeft(float value);
	void OnUseAfterburnerBegin();
	void OnUseAfterburnerEnd();
	void OnFireWeaponBegin();
	void OnFireWeaponEnd();
	void OnChargeWeaponBegin();
	void OnChargeWeaponEnd();
	void DelegateTestFunc();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void UpdateGunStatus();
	
	UFUNCTION()
	void ResetGunStatus();

	UFUNCTION()
	bool IsGunReady();

	UFUNCTION()
	FString GunStatusToFString();

private:
	const float reloadTime = 3.0f;
	const float maxChargeAmount = 10.0f;
	bool bIsMoving;
	bool bIsWeaponCharging;
	bool bIsAfterburnerActive;
	float timeSinceLastShot;
	float gunChargeAmount; 
	GUN_STATUS gunStatus;

private:
	UPROPERTY()
	UHealthActorComponent* c_HealthComponent;

	UPROPERTY()
	UInputComponent* c_InputComponent;

	UPROPERTY()
	UStaticMeshComponent* c_StaticMeshComponent;

	UPROPERTY()
	UFloatingPawnMovement* c_FloatingPawnComponent;

	UPROPERTY()
	UCameraComponent* c_CameraComponent;

	UPROPERTY(EditAnywhere, Category = "Audio")
	UAudioComponent* c_AudioComponent_Gun;

	UPROPERTY(EditAnywhere, Category = "Audio")
	UAudioComponent* c_AudioComponent_Afterburner;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* GunFireAudio;

	UPROPERTY(EditAnywhere, Category = "Blueprint References")
	TSubclassOf<AActor>ProjectileActor;

	UPROPERTY(EditAnywhere, Category = "Variables")
	float afterburnerSpeed = 10.0f;

private:
	FTimerHandle ReloadTimerHandle;
	FGunStatusUpdateDelegate OnGunStatusUpdate;
	FGunChargeDelegate OnGunCharge;
	FGunReadyDelegate OnGunReady;
};
