#include "AIMonsterPawn.h"
#include "BankTankGameModeBase.h"

// Sets default values
AAIMonsterPawn::AAIMonsterPawn()
{		
	c_StaticMeshComponent= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	c_MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement Component"));
	c_HealthComponent = CreateDefaultSubobject<UHealthActorComponent>(TEXT("Health Component"));
	c_AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));

	c_AudioComponent->bStopWhenOwnerDestroyed = false;
	c_AudioComponent->bAutoActivate = false;
	c_AudioComponent->VolumeMultiplier = 5.0f;

	c_HealthComponent->SetHealth(5);
	
	c_MovementComponent->MaxSpeed = 600.0f;
	this->bUseControllerRotationYaw = true;
	this->Tags.Add(FName("AI Pawn"));
}

// Called when the game starts or when spawned
void AAIMonsterPawn::BeginPlay()
{
	Super::BeginPlay();
	if (!GetController())
	{
		UE_LOG(LogTemp, Error, TEXT("No controller assigned for %s!"), *this->GetName());
		return;
	}

	c_StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AAIMonsterPawn::OnOverlapBegin);
	c_StaticMeshComponent->OnComponentHit.AddDynamic(this, &AAIMonsterPawn::OnHit);
}

// Called every frame/
void AAIMonsterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAIMonsterPawn::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap event called on %s"), *this->GetName());

	if (OtherActor->ActorHasTag("Projectile"))
	{
		c_HealthComponent->TakeDamage(5);
		UE_LOG(LogTemp, Error, TEXT("%s now has %d health!"), *this->GetName(), c_HealthComponent->GetHealth());
	}

	if (c_HealthComponent->GetHealth() <= 0)
	{
		//c_AudioComponent->Play();
		ABankTankGameModeBase* GMBase = Cast<ABankTankGameModeBase>(GetWorld()->GetAuthGameMode());
		GMBase->RemovePawnFromList(this);

		Destroy();
	}

}

void AAIMonsterPawn::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("On hit delegate called"));
}

