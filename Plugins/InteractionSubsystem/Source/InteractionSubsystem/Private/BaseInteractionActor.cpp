// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInteractionActor.h"

// Sets default values
ABaseInteractionActor::ABaseInteractionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseInteractionActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseInteractionActor::OnInteractionFinished(AActor* InteractionInstigator)
{
	NotifyInteractionFinished(this, InteractionInstigator);
}

// Called every frame
void ABaseInteractionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseInteractionActor::Interact_Implementation(AActor* InteractionInstigator)
{
	/*IInteractableActor::Interact_Implementation(InteractionInstigator);*/
	//TODO add your interaction mechanics here
}

