#include "TankProjectileActor.h"
// Sets default values
ATankProjectileActor::ATankProjectileActor()
{
	PrimaryActorTick.bCanEverTick = true;
	c_ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	c_StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	c_ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle System Component"));
	this->RootComponent = c_StaticMeshComponent;

	this->Tags.Add(FName("Projectile"));

}

// Called when the game starts or when spawned
void ATankProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	c_StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ATankProjectileActor::OnOverlapBegin);
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT("Tank Projectile created!"), true);
}


// Called every frame
void ATankProjectileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	c_StaticMeshComponent->AddWorldOffset(GetActorForwardVector() * BALL_SPEED);
}

void ATankProjectileActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap event called on %s"), *this->GetName());

	if (!c_ParticleSystemComponent->Template)
	{
		UE_LOG(LogTemp, Error, TEXT("No particle template defined for Particle System!"));
	}

	if (OtherActor)
	{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), c_ParticleSystemComponent->Template, this->GetActorTransform(), false);
			Destroy();
	}


}
