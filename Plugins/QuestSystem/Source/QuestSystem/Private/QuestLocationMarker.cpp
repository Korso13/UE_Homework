// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestLocationMarker.h"

#include "Components/BoxComponent.h"

// Sets default values
AQuestLocationMarker::AQuestLocationMarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DetectionCube = CreateDefaultSubobject<UBoxComponent>("Detection_Cube");
	DetectionCube->OnComponentBeginOverlap.AddDynamic(this, &AQuestLocationMarker::OnCompBeginOverlap);
}

// Called when the game starts or when spawned
void AQuestLocationMarker::BeginPlay()
{
	Super::BeginPlay();
	
}

void AQuestLocationMarker::OnCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OnLocationReached.IsBound())
		OnLocationReached.Broadcast(this, OtherActor);
}

// Called every frame
/*
void AQuestLocationMarker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/

