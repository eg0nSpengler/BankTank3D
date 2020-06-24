// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalTriggerBox.h"

void APortalTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5.0f);
	c_StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &APortalTriggerBox::OnOverlapBegin);
}

APortalTriggerBox::APortalTriggerBox()
{
	c_StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	c_AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
	c_AudioComponent->bAutoActivate = false;
}

void APortalTriggerBox::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor)
	{
		return;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, *OtherActor->GetName());		
		c_AudioComponent->Play();
	}
}

void APortalTriggerBox::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void APortalTriggerBox::PostActorCreated()
{
	Super::PostActorCreated();
}

