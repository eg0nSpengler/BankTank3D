#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "CoinCountWidget.h"
#include "GunStatusWidget.h"
#include "ScoreWidget.h"
#include "BankTankHUD.generated.h"

UCLASS()
class BANKTANK_API ABankTankHUD : public AHUD
{
	GENERATED_BODY()

	ABankTankHUD(const FObjectInitializer& ObjectInitializer);

public:
	UFUNCTION(BlueprintCallable)
	virtual void DrawHUD() override;

private:
	UPROPERTY(EditAnywhere, Category = "Crosshair")
	UTexture2D* crosshairTexture;

	UPROPERTY()
	UCoinCountWidget* coinWidget;

	UPROPERTY()
	UGunStatusWidget* gunStatWidget;

	UPROPERTY()
	UScoreWidget* scoreWidget;

};
