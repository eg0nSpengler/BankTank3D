#include "LevelGeneratorNodeActor.h"



ALevelGeneratorNodeActor::ALevelGeneratorNodeActor()
{
	PrimaryActorTick.bCanEverTick = true;
	c_SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	this->RootComponent = c_SceneComponent;

}

void ALevelGeneratorNodeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALevelGeneratorNodeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

