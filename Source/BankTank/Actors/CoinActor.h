#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ListViewBase.h"
#include "Classes/Components/SphereComponent.h"
#include "Classes/Components/AudioComponent.h"
#include "Classes/Engine/Texture2D.h"
#include "CoinActor.generated.h"

UCLASS()
class BANKTANK_API ACoinActor : public AActor, public IUserObjectListEntry
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACoinActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Levitate(float dTime);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void DestroyCoin();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coin Image")
	UTexture2D* actorImage;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* c_StaticMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	UAudioComponent* c_AudioComponent;

private:
	UPROPERTY()
	USphereComponent* c_SphereComponent;

private:
	float runningTime;
};
