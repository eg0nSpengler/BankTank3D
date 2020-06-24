#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.generated.h"


UCLASS()
class BANKTANK_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UBaseWidget(const FObjectInitializer& ObjectInitializer);
};
