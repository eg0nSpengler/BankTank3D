
#include "LevelGeneratorNode.h"

ULevelGeneratorNode::ULevelGeneratorNode()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void ULevelGeneratorNode::BeginPlay()
{
	Super::BeginPlay();
}


void ULevelGeneratorNode::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

