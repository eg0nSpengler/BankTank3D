#include "CoinCountWidget.h"
#include "BankTankGameModeBase.h"


UCoinCountWidget::UCoinCountWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Super::NativeConstruct();

}

int UCoinCountWidget::GetNumCoinsInMap() const
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString("GetNumCoinsInMap called!"));
	}
	ABankTankGameModeBase* GMBase = Cast<ABankTankGameModeBase>(GetWorld()->GetAuthGameMode());
	return GMBase->GetNumCoinsInLevel();
}

void UCoinCountWidget::PostLoad()
{
	Super::PostLoad();
	
}

