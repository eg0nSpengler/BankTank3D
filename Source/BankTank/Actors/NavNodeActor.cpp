#include "NavNodeActor.h"
// Sets default values
ANavNodeActor::ANavNodeActor()
{
	c_SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	c_StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	this->SetActorHiddenInGame(true);
}

// Called when the game starts or when spawned
void ANavNodeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANavNodeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}





