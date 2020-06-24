


#include "CoinListWidget.h"
#include "BankTankGameModeBase.h"
UCoinListWidget::UCoinListWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

int UCoinListWidget::GetNumCoinsInLevel() const
{
	ABankTankGameModeBase* GMBase = Cast<ABankTankGameModeBase>(GetWorld()->GetAuthGameMode());
	return GMBase->GetNumCoinsInLevel();
}
