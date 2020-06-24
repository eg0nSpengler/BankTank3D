#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "LevelGeneratorNodeActor.generated.h"

UCLASS()
class BANKTANK_API ALevelGeneratorNodeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ALevelGeneratorNodeActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	USceneComponent* c_SceneComponent;


};
