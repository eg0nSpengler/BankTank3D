#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "LevelGeneratorNode.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BANKTANK_API ULevelGeneratorNode : public USceneComponent
{
	GENERATED_BODY()

public:	
	ULevelGeneratorNode();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
