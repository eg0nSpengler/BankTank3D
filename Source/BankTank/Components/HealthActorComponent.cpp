// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthActorComponent.h"

// Sets default values for this component's properties
UHealthActorComponent::UHealthActorComponent() : _actorHealth()
{

}


// Called when the game starts
void UHealthActorComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UHealthActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

int UHealthActorComponent::GetHealth()
{
	return _actorHealth;
}

void UHealthActorComponent::SetHealth(int hp)
{
	_actorHealth = hp;
}

void UHealthActorComponent::TakeDamage(int dmg)
{
	if (_actorHealth <= 0)
	{
		return;
	}
	else
	{
		_actorHealth -= dmg;
	}
}

