// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableActor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractableActor : public UInterface
{
	GENERATED_BODY()
};

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnInteractionFinished, AActor* /*Interactable actor*/, AActor* /*Interaction instigator*/);

/**
 * 
 */
class INTERACTIONSUBSYSTEM_API IInteractableActor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Interact(AActor* Instigator);

	UFUNCTION()
	virtual void Interact_Implementation(AActor* InteractionInstigator) {};

	virtual void NotifyInteractionFinished(AActor* InteractableActor, AActor* InteractionInstigator)
	{
		if (OnInteractionFinished.IsBound())
			OnInteractionFinished.Broadcast(InteractableActor, InteractionInstigator);
	}
	
	FOnInteractionFinished OnInteractionFinished;
};
