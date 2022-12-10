// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryStructs.h"
#include "BaseLootContainer.generated.h"

class UBoxComponent;
class UInventoryComponent;
class UWidgetComponent;
class UUserWidget;
class ATankWithInventory;

UCLASS()
class TANKINVENTORYSYSTEM_API ABaseLootContainer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseLootContainer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//meshes and components
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UBoxComponent* Collision;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UStaticMeshComponent* BoxMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInventoryComponent* Inventory;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Container")
	UDataTable* ContainerContents;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Components")
	UWidgetComponent* ButtonTooltip;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Widget Settings")
	TSubclassOf<UUserWidget> ButtonTooltipClass;

	UPROPERTY()
	APawn* ActorInRange;

	void OpenContainer();


public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void CloseContainer();

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
		FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnComponentEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UInventoryComponent* GetInventory() const { return Inventory; }


};
