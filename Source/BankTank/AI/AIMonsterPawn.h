#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Classes/GameFramework/FloatingPawnMovement.h"
#include "Classes/Engine/TargetPoint.h"
#include "Classes/Components/AudioComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "HealthActorComponent.h"
#include "AIMonsterPawn.generated.h"




UCLASS()
class BANKTANK_API AAIMonsterPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAIMonsterPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* BotBehavior;

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* c_StaticMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	UAudioComponent* c_AudioComponent;

	UPROPERTY()
	UFloatingPawnMovement* c_MovementComponent;

	UPROPERTY()
	UHealthActorComponent* c_HealthComponent;

};
