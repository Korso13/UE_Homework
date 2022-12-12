// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"

#include "InteractableActor.h"
#include "Blueprint/UserWidget.h"

// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UInteractionComponent::OnInteractionCompBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UInteractionComponent::OnInteractionCompEndOverlap);
}


// Called every frame
void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInteractionComponent::Interact() //must be bound to a key either via character's code, or via blueprint
{
	if(InteractionActor)
		IInteractableActor::Execute_Interact(InteractionActor, GetOwner());
}

void UInteractionComponent::OnInteractionCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(!OtherActor->Implements<UInteractableActor>())
		return;

	InteractionActor = OtherActor;
	//TODO add InteractionActor nullptr checks. If false add distance checks for InteractionActor and Other Actor - in form of separate function and write to InteractionActor the one that is closest. Add this func's call to tick with condition check (pass array of candidates. added in BeginOverlap, remove on EndOverlap)
	
	if(!InteractTooltip && InteractTooltipClass)
	{
		InteractTooltip = CreateWidget<UUserWidget>(GetWorld(), InteractTooltipClass);
	}

	if(InteractTooltip && !InteractTooltip->IsInViewport())
	{
		InteractTooltip->AddToViewport();
	}
}

void UInteractionComponent::OnInteractionCompEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor == InteractionActor)
	{
		InteractionActor = nullptr;
		if(InteractTooltip)
		{
			InteractTooltip->RemoveFromViewport();
		}
	}
}

