#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "Classes/Engine/TargetPoint.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIMonsterPerceptionComponent.h"
#include "Engine/World.h"
#include "AIMonsterPawn.h"
#include "TankPawn.h"
#include "MonsterPawnAIController.generated.h"


UCLASS()
class BANKTANK_API AMonsterPawnAIController : public AAIController
{
	GENERATED_BODY()

private:
	AMonsterPawnAIController(const FObjectInitializer& ObjectInitializer);

	void BeginPlay() override;
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION(BlueprintCallable, Category = Behavior)
	void SearchForEnemy();

	UFUNCTION()
	void SetEnemy(AActor* InPawn);

	UFUNCTION(BlueprintCallable, Category = Behavior)
	void AttackEnemy(AActor* InPawn);

	UFUNCTION()
	void GoToRandomWayPoint();

	UFUNCTION()
	void OnPawnDetected(const TArray<AActor*>& detectedPawns);

	UFUNCTION()
	ATargetPoint* GetRandomWayPoint();

private:
	bool bIsPlayerDetected;

private:
	UPROPERTY()
	TArray<AActor*> wayPoints;

	UPROPERTY()
	FTimerHandle movementTimer;

	UPROPERTY(Transient)
	UBlackboardComponent* c_BlackBoardComponent;

	UPROPERTY(Transient)
	UBehaviorTreeComponent* c_BehaviorTreeComponent;

	UPROPERTY(EditAnywhere)
	ATargetPoint* WayPoint1;

	UPROPERTY(EditAnywhere)
	ATargetPoint* WayPoint2;

	UPROPERTY()
	UAIMonsterPerceptionComponent* c_AIPerceptionComponent;

};
