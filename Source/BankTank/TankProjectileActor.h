#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Classes/GameFramework/ProjectileMovementComponent.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Classes/Particles/ParticleSystemComponent.h"
#include "Engine.h"
#include "TankProjectileActor.generated.h"

UCLASS()
class BANKTANK_API ATankProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATankProjectileActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	const float BALL_SPEED = 60.0f;

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UProjectileMovementComponent* c_ProjectileComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* c_StaticMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	UParticleSystemComponent* c_ParticleSystemComponent;


};
