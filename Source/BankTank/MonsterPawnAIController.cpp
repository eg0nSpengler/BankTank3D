#include "MonsterPawnAIController.h"

AMonsterPawnAIController::AMonsterPawnAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	c_AIPerceptionComponent = CreateDefaultSubobject<UAIMonsterPerceptionComponent>(TEXT("AI Perception Component"));
	c_BlackBoardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
	c_BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	this->SetPerceptionComponent(*c_AIPerceptionComponent);
}

void AMonsterPawnAIController::BeginPlay()
{
	Super::BeginPlay();

	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), wayPoints);
	c_AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &AMonsterPawnAIController::OnPawnDetected);

}


ATargetPoint* AMonsterPawnAIController::GetRandomWayPoint()
{
	auto index = FMath::RandRange(0, wayPoints.Num() - 1);
	return Cast<ATargetPoint>(wayPoints[index]);
}


void AMonsterPawnAIController::GoToRandomWayPoint()
{	
	MoveToActor(GetRandomWayPoint());
	
}

void AMonsterPawnAIController::OnPawnDetected(const TArray<AActor*>& detectedPawns)
{
	for (auto pawn : detectedPawns)
	{ 
		FString detectString = FString("I'm detecting ");
		detectString += *pawn->GetName();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, detectString);
		SetEnemy(pawn);
	}
}
 
void AMonsterPawnAIController::SearchForEnemy()
{
	APawn* OurBot = GetPawn();
	APawn* EnemyPawn = nullptr;

	if (!OurBot)
	{
		return;
	}

	const FVector OurBotLocation = OurBot->GetActorLocation();

	float maxDistanceFrom = MAX_FLT;

	for (FConstPawnIterator Itr = GetWorld()->GetPawnIterator(); Itr; ++Itr)
	{
		APawn* testPawn = Cast<APawn>(*Itr);
		if (testPawn)
		{
			const float DistSquared = FVector::Dist(testPawn->GetActorLocation(), OurBotLocation);
			if (DistSquared <= maxDistanceFrom)
			{
				maxDistanceFrom = DistSquared;
				EnemyPawn = testPawn;
			}
		}
	}

	if (EnemyPawn) 

	{
		SetFocus(EnemyPawn, EAIFocusPriority::Gameplay);
		SetEnemy(EnemyPawn);
	}
}

void AMonsterPawnAIController::SetEnemy(AActor* InPawn)
{
	if (c_BlackBoardComponent)
	{
		c_BlackBoardComponent->SetValueAsObject(FName("Enemy"), InPawn);
		c_BlackBoardComponent->SetValueAsVector(FName("Destination"), InPawn->GetActorLocation());
		c_BlackBoardComponent->SetValueAsObject(FName("SelfActor"), GetPawn());
	}
	AttackEnemy(InPawn);
}

void AMonsterPawnAIController::AttackEnemy(AActor* InPawn)
{
	
}

void AMonsterPawnAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	UE_LOG(LogTemp, Warning, TEXT("MonsterPawnAIController has possessed %s"), *InPawn->GetName());
	AAIMonsterPawn* Bot = Cast<AAIMonsterPawn>(InPawn);

	if (Bot && Bot->BotBehavior)
	{
		c_BlackBoardComponent->InitializeBlackboard(*Bot->BotBehavior->BlackboardAsset);

	}
	c_BehaviorTreeComponent->StartTree(*Bot->BotBehavior);
}

void AMonsterPawnAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
}

