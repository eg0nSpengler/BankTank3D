#include "BankTankHUD.h"

ABankTankHUD::ABankTankHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	coinWidget = CreateWidget<UCoinCountWidget>(GetWorld());
	gunStatWidget = CreateWidget<UGunStatusWidget>(GetWorld());
	scoreWidget = CreateWidget<UScoreWidget>(GetWorld());
}

void ABankTankHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!crosshairTexture)
	{
		UE_LOG(LogTemp, Error, TEXT("No crosshair texture defined in BankTankHUD!"));
		return;
	}
	
	auto screenX = Canvas->SizeX / 2;
	auto screenY = Canvas->SizeY / 2;

	
	if (!coinWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("No valid coinWidget!"));
		return;
	}
	
	//auto coinText = FString::FromInt(coinWidget->GetNumCoinsInMap());
	//auto scoreText = FString::FromInt(scoreWidget->GetScore());
	//auto gunText = gunStatWidget->GetGunStatus();

	//DrawText(coinText, FLinearColor::Green, screenX + 10, screenY - 10, nullptr, 5.0f);
	//DrawText(gunText, FLinearColor::Blue, screenX - 20.0f, screenY - 20.0f, NULL, 2.0f);
	//DrawText(scoreText, FLinearColor::Green, screenX - 40.0f, screenY - 40.0f, NULL, 2.0f);
}
