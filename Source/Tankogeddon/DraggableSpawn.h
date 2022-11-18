// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base_Pawn.h"
#include "TankPlayerController.h"
//#include "SpawnerPanel.h" 
#include "Blueprint/UserWidget.h"
#include "DraggableSpawn.generated.h"

class UImage;
class UTextBlock;
class USpawnerPanel;

/**
 * 
 */
UCLASS()
class TANKOGEDDON_API UDraggableSpawn : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	virtual void NativeTick(const FGeometry& InGeometry, float DeltaTime) override;

	void OnMouseButtonUp();

	UFUNCTION()
	void RestoreVisuals();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	UImage* TurretIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	UTextBlock* TurretCostWidget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner Settings")
	TSubclassOf<ABase_Pawn> TurretClass;

protected:
	UPROPERTY()
	ABase_Pawn* Turret = nullptr;

	UPROPERTY()
	ATankPlayerController* PlayerController;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawner Settings")
	int32 TurretCost;

private:
	UPROPERTY()
	USpawnerPanel* Spawner;

};
