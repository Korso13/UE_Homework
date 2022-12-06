// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryStructs.h"
#include "WeaponBox.generated.h"

class UBoxComponent;
class ACanon;

UCLASS()
class TANKOGEDDON_API AWeaponBox : public AActor
{
	GENERATED_BODY()
public:
	//meshes and components
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UBoxComponent* Collision;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UStaticMeshComponent* BoxMesh;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Depricated Cannon Type")
	TSubclassOf<ACanon> CanonClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cannon Type")
	FInventorySlotInfo WeaponBoxType;

public:	
	// Sets default values for this actor's properties
	AWeaponBox();
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
		FHitResult& SweepResult);
};
