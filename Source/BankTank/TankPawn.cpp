
#include "TankPawn.h"
#include "BankTankGameModeBase.h"
ATankPawn::ATankPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	c_InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("Input Component"));
	c_StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	c_FloatingPawnComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Component"));
	c_CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component")); 
	c_HealthComponent = CreateDefaultSubobject<UHealthActorComponent>(TEXT("Health Component"));
	c_AudioComponent_Gun = CreateDefaultSubobject<UAudioComponent>(TEXT("Gun Audio Component"));
	c_AudioComponent_Afterburner = CreateDefaultSubobject<UAudioComponent>(TEXT("Afterburner Audio Component"));

	c_CameraComponent->AttachToComponent(this->c_StaticMeshComponent, FAttachmentTransformRules::KeepWorldTransform, NAME_None);

	c_AudioComponent_Gun->bAutoActivate = false;
	c_AudioComponent_Afterburner->bAutoActivate = false;

	this->RootComponent = c_StaticMeshComponent;
	this->Tags.Add("Player");

	bIsAfterburnerActive = false;
	bIsMoving = false;
	bIsWeaponCharging = false;
	gunChargeAmount = 0.0f;
	timeSinceLastShot = 0.0f;

}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();
	c_StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ATankPawn::OnOverlapBegin);

	timeSinceLastShot = reloadTime;
	gunStatus = GUN_STATUS::READY;

	auto funcName = GET_FUNCTION_NAME_CHECKED(ATankPawn, GunStatusToFString);
	auto funcName2 = GET_FUNCTION_NAME_CHECKED(ATankPawn, UpdateGunStatus);
	OnGunStatusUpdate.BindUFunction(this, funcName);
	OnGunReady.BindUFunction(this, funcName2);

}

void ATankPawn::MoveForward(float value)
{
	if (value != 0.0f && bIsMoving == false)
	{
		AddMovementInput(c_CameraComponent->GetForwardVector() * value);
		bIsMoving = true;
	}
	else
	{
		bIsMoving = false;
	}
}

void ATankPawn::TurnLeft(float value)
{
	if (value != 0.0f && bIsMoving == false)
	{
		AddActorLocalRotation(FRotator(0.0f, value, 0.0f));
		bIsMoving = true;
	}
	else
	{
		bIsMoving = false;
	}
}


void ATankPawn::OnFireWeaponBegin()
{
	c_AudioComponent_Gun->Sound = GunFireAudio;

	if (!c_AudioComponent_Gun->Sound)
	{
		UE_LOG(LogTemp, Error, TEXT("No sound set for OnFireWeaponBegin!"));
		UE_LOG(LogTemp, Error, TEXT("OnFireWeaponBegin failed to fire!"));
		return;
	}

	if (IsGunReady() == true)
	{
		auto camLoc = c_CameraComponent->GetComponentLocation();
		auto camRot = c_CameraComponent->GetComponentRotation();
		c_AudioComponent_Gun->SetPitchMultiplier(FMath::RandRange(1.0f, 1.1f));
		c_AudioComponent_Gun->Play(0.0f);

		GWorld->SpawnActor(ProjectileActor, &camLoc, &camRot);

		ResetGunStatus();
	}
	else
	{
		return;
	}	
}

void ATankPawn::OnFireWeaponEnd()
{

}

void ATankPawn::OnChargeWeaponBegin()
{
	bIsWeaponCharging = true;
}

void ATankPawn::OnChargeWeaponEnd()
{
	gunChargeAmount = 0.0f;
	bIsWeaponCharging = false;
}

void ATankPawn::DelegateTestFunc()
{
	UE_LOG(LogTemp, Error, TEXT("WORK YOU FUCKING SUCKING PIECE OF FUCKING SHIT FUCKING FUCKING STUPID ASS FUCKING FUCKING BAD TERRIBLE FUCKING ENGINE FUCK"));
}

void ATankPawn::OnUseAfterburnerBegin()
{
	bIsAfterburnerActive = true;
	c_AudioComponent_Afterburner->Play(0.0f);
}

void ATankPawn::OnUseAfterburnerEnd()
{
	bIsAfterburnerActive = false;
	c_AudioComponent_Afterburner->Stop();
}

// Called every frame
void ATankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	timeSinceLastShot += DeltaTime;

	auto camVec = c_CameraComponent->GetForwardVector();

	if (bIsWeaponCharging == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun Charge amount is %f"), gunChargeAmount);
		gunChargeAmount++;
		if (gunChargeAmount >= maxChargeAmount)
		{
			gunChargeAmount = maxChargeAmount;
		}
	}

	if (bIsAfterburnerActive == true)
	{
		this->AddActorWorldOffset(camVec * afterburnerSpeed, true, nullptr, ETeleportType::None);
	}

}

// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ATankPawn::MoveForward);
	PlayerInputComponent->BindAxis("TurnLeft", this, &ATankPawn::TurnLeft);
	PlayerInputComponent->BindAction("UseAfterburner", EInputEvent::IE_Pressed, this, &ATankPawn::OnUseAfterburnerBegin);
	PlayerInputComponent->BindAction("UseAfterburner", EInputEvent::IE_Released, this, &ATankPawn::OnUseAfterburnerEnd);
	PlayerInputComponent->BindAction("FireWeapon", EInputEvent::IE_Pressed, this, &ATankPawn::OnFireWeaponBegin);
	PlayerInputComponent->BindAction("FireWeapon", EInputEvent::IE_Released, this, &ATankPawn::OnFireWeaponEnd);
	PlayerInputComponent->BindAction("ChargeWeapon", EInputEvent::IE_Pressed, this, &ATankPawn::OnChargeWeaponBegin);
	PlayerInputComponent->BindAction("ChargeWeapon", EInputEvent::IE_Released, this, &ATankPawn::OnChargeWeaponEnd);
}

void ATankPawn::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("AI Pawn"))
	{
		c_HealthComponent->TakeDamage(2);
	}
}

void ATankPawn::UpdateGunStatus()
{
	if (timeSinceLastShot >= reloadTime)
	{
		gunStatus = GUN_STATUS::READY;
	}
}

void ATankPawn::ResetGunStatus()
{
	timeSinceLastShot = 0.0f;
	gunStatus = GUN_STATUS::REARMING;
	GetWorld()->GetTimerManager().SetTimer(ReloadTimerHandle, this, &ATankPawn::UpdateGunStatus, reloadTime, false);
}

bool ATankPawn::IsGunReady()
{
	if (timeSinceLastShot >= reloadTime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

FString ATankPawn::GunStatusToFString()
{
	switch (gunStatus)
	{
	case GUN_STATUS::READY:
		return "GUN READY";
		break;

	case GUN_STATUS::REARMING:
		return "REARMING";
		break;

	case GUN_STATUS::CHARGING:
		return "CHARGING";
		break;

	case GUN_STATUS::MAX_POWER:
		return "MAX POWER";
		break;

	default:
		break;
	}
	return "UNKNOWN";
}
