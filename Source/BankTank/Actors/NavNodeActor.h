#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "NavNodeActor.generated.h"

UCLASS()
class BANKTANK_API ANavNodeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANavNodeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	UPROPERTY(EditAnywhere)
	USceneComponent* c_SceneComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* c_StaticMeshComponent;
};



