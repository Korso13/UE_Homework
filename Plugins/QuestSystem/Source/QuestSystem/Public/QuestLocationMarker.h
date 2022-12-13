// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestLocationMarker.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnLocationReached, AActor* /*Location Marker actor*/, AActor* /*Overlapped actor*/);

class UBoxComponent;

UCLASS()
class QUESTSYSTEM_API AQuestLocationMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestLocationMarker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBoxComponent* DetectionCube;

public:	
	// Called every frame
	/*virtual void Tick(float DeltaTime) override;*/

	FOnLocationReached OnLocationReached;

	UFUNCTION()
void OnCompBeginOverlap(UPrimitiveComponent*  OverlappedComponent,
   AActor* OtherActor, UPrimitiveComponent* OtherComp,
   int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
