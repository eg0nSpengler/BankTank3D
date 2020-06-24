#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Math/IntVector.h"
#include "Engine/World.h"
#include "LevelGeneratorActor.generated.h"

UCLASS()
class BANKTANK_API ALevelGeneratorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelGeneratorActor();

protected:
	virtual void BeginPlay() override;
	void BuildRoom();

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	int maxTileX;

	UPROPERTY(EditAnywhere)
	int maxTileY;

	UPROPERTY(EditAnywhere)
	int tileSize;

	UPROPERTY()
	TArray<int> tileType;

private:
	UPROPERTY(EditAnywhere)
	UInstancedStaticMeshComponent* floorMeshInstance;

	UPROPERTY(EditAnywhere)
	UInstancedStaticMeshComponent* pillarMeshInstance;

};
