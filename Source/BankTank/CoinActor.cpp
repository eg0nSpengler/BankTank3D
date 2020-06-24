#include "CoinActor.h"
#include "BankTankGameModeBase.h"
#include "BankTank.h"

ACoinActor::ACoinActor()
{
	PrimaryActorTick.bCanEverTick = true;
	c_StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	c_SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider Component"));
	c_SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoinActor::OnOverlapBegin);
	c_AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
	c_AudioComponent->bStopWhenOwnerDestroyed = false;
	this->RootComponent = c_StaticMeshComponent;
	this->Tags.Add(FName("Coin"));
}


void ACoinActor::BeginPlay()
{
	Super::BeginPlay();
}

void ACoinActor::Levitate(float dTime)
{
	FVector actorLocation = GetActorLocation();
	auto deltaHeight = FMath::Sin(runningTime + dTime) - FMath::Sin(runningTime);
	actorLocation.Z += deltaHeight * 50.0f;
	runningTime += dTime;
	SetActorLocation(actorLocation);
}

void ACoinActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player") == true)
	{
		c_AudioComponent->Play();
		DestroyCoin();
	}
}

void ACoinActor::DestroyCoin()
{
	UE_LOG(LogContainerRemoval, Warning, TEXT("Removed %s from coinList!"), *this->GetName());
	ABankTankGameModeBase* GMBase = Cast<ABankTankGameModeBase>(GetWorld()->GetAuthGameMode());
	GMBase->RemoveCoinFromList(this);
	Destroy();
}

void ACoinActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Levitate(DeltaTime);
}

