// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelGeneratorActor.h"

// Sets default values
ALevelGeneratorActor::ALevelGeneratorActor()
{
	PrimaryActorTick.bCanEverTick = true;
	floorMeshInstance = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Floor Mesh"));
	pillarMeshInstance = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Pillar Mesh"));
	maxTileX = 32;
	maxTileY = 32;
	tileSize = 100;
	this->RootComponent = floorMeshInstance;
}

// Called when the game starts or when spawned
void ALevelGeneratorActor::BeginPlay()
{
	Super::BeginPlay();
	BuildRoom();
}

void ALevelGeneratorActor::BuildRoom()
{
	auto tileArraySize = maxTileX * maxTileY;
	tileType.SetNumZeroed(maxTileX * maxTileY);

	for (int x = 0; x <= tileArraySize; x++)
	{
		auto worldX = x / maxTileY * tileSize;
		auto worldY = x % maxTileY * tileSize;
		FVector worldVec(worldX, worldY, 0);
		floorMeshInstance->AddInstance(FTransform(this->GetActorRotation().Quaternion(), worldVec, this->GetActorScale()));
	}
	


	/*for (int i = 0; i <= tileArraySize; i++)
	{
		auto worldX = i / maxTileY * tileSize;
		auto worldY = i % maxTileY * tileSize;
		FVector worldVec(worldX, worldY, 0);
		floorMeshInstance->AddInstance(FTransform(this->GetActorRotation().Quaternion(), worldVec, this->GetActorScale()));
	}*/
}

// Called every frame
void ALevelGeneratorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

