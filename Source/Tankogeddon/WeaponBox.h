// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Canon.h"
#include "Components/BoxComponent.h"
#include "WeaponBox.generated.h"

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cannon Type")
		TSubclassOf<ACanon> CanonClass;


public:	
	// Sets default values for this actor's properties
	AWeaponBox();
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
		FHitResult& SweepResult);
};
