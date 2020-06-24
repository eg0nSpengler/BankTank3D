#pragma once
#include "CoreMinimal.h"
#include "BaseWidget.h"
#include "UMG/Public/Components/TextBlock.h"
#include "CoinCountWidget.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCoinRemoved);

UCLASS()
class BANKTANK_API UCoinCountWidget : public UBaseWidget
{
	GENERATED_BODY()

	UCoinCountWidget(const FObjectInitializer& ObjectInitializer);

public:
	UFUNCTION(BlueprintCallable)
	int GetNumCoinsInMap() const;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CoinCountText;

private:
	UPROPERTY(BlueprintAssignable)
	FOnCoinRemoved OnCoinRemoved;

	virtual void PostLoad() override;


};
