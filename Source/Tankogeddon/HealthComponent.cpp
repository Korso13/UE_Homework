// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	CurrentHP = MaxHP;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CurrentHP = MaxHP;

}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakeDamage(FDamageInfo Damage)
{
	float PreviousHP = CurrentHP;
	CurrentHP -= Damage.DamageValue;
	if (CurrentHP < 0)
		CurrentHP = 0;
	if(CurrentHP != PreviousHP)
	{
		OnDamage.Broadcast(Damage);
		if (CurrentHP <= 0)
			OnDeath.Broadcast();
	}
}

float UHealthComponent::GetHealth() const
{
	return CurrentHP;
}

