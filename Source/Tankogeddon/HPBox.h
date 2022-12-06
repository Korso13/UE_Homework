// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base_Consumable.h"
#include "InventoryStructs.h"
#include "HPBox.generated.h"

class UBoxComponent;
/**
 * 
 */
UCLASS()
class TANKOGEDDON_API AHPBox : public ABase_Consumable
{
	GENERATED_BODY()
	
public:
	AHPBox();
	
	//meshes and components
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UBoxComponent* Collision;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UStaticMeshComponent* BoxMesh;

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	FInventorySlotInfo HPBoxType;

	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
		FHitResult& SweepResult) override;

public:
	virtual void UseConsumable() override;

};
