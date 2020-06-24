#include "PortalActor.h"

APortalActor::APortalActor()
{
	PrimaryActorTick.bCanEverTick = true;
	c_StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	this->RootComponent = c_StaticMeshComponent;
	this->Tags.Add(FName("Portal"));
}

// Called when the game starts or when spawned
void APortalActor::BeginPlay()
{
	Super::BeginPlay();
	this->SetActorHiddenInGame(true);
	this->SetActorEnableCollision(false);
}

// Called every frame
void APortalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APortalActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

