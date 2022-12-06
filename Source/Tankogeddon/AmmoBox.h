// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base_Consumable.h"
#include "InventoryStructs.h"
#include "AmmoBox.generated.h"

class UBoxComponent;

UCLASS()
class TANKOGEDDON_API AAmmoBox : public ABase_Consumable
{
	GENERATED_BODY()

public:
	//meshes and components
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UBoxComponent* Collision;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UStaticMeshComponent* BoxMesh;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Depricated Components")
	int32 AmmoRefillCount = 30;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	FInventorySlotInfo AmmoBoxType;

public:	
	// Sets default values for this actor's properties
	AAmmoBox();
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
	FHitResult& SweepResult) override;

public:
	virtual void UseConsumable() override;
};
