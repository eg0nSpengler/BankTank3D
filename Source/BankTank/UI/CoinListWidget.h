

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "CoinListWidget.generated.h"

/**
 * 
 */
UCLASS()
class BANKTANK_API UCoinListWidget : public UListViewBase, public IUserObjectListEntry
{
	GENERATED_BODY()

	UCoinListWidget(const FObjectInitializer& ObjectInitializer);

public:
	UFUNCTION(BlueprintCallable, meta = (BindWidget))
	int GetNumCoinsInLevel() const;
};
