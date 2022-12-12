// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Components/ActorComponent.h"
#include "Components/SphereComponent.h"
#include "InteractionComponent.generated.h"


UCLASS( ClassGroup = "Collision", meta = (DisplayName = "Interaction Collision", BlueprintSpawnableComponent) )
class INTERACTIONSUBSYSTEM_API UInteractionComponent : public USphereComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> InteractTooltipClass;

	UPROPERTY()
	UUserWidget* InteractTooltip;

	UPROPERTY()
	AActor* InteractionActor;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Interact();

	UFUNCTION()
	void OnInteractionCompBeginOverlap(UPrimitiveComponent*  OverlappedComponent,
	   AActor* OtherActor, UPrimitiveComponent* OtherComp,
	   int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);


	UFUNCTION()
	void OnInteractionCompEndOverlap(UPrimitiveComponent* OverlappedComponent,
		 AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
