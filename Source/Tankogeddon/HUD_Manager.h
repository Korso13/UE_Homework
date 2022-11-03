// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD_Manager.generated.h"

/**
 * 
 */

UENUM()
enum class EWidgetIDs : uint8
{
	Widget_MainMenu = 0,
	Widget_GameOver = 1,
	Widget_PlayerStatus = 2,
	Widget_PauseMenu = 3,
	Widget_MapOverlay = 4
};

UCLASS(ABSTRACT)
class TANKOGEDDON_API AHUD_Manager : public AHUD
{
	GENERATED_BODY()

protected:
	UUserWidget* CreateWidgetByClass(const EWidgetIDs WidgetID, const TSubclassOf<UUserWidget> NewWidget);

public:
	UPROPERTY(EditAnywhere)
	TMap<EWidgetIDs, TSubclassOf<UUserWidget>> WidgetClasses;

	UPROPERTY(EditAnywhere)
	TMap<EWidgetIDs, UUserWidget*> ActiveWidgets;
	
	UFUNCTION(BlueprintPure)
	TMap<EWidgetIDs, UUserWidget*> GetActiveWidgets() const { return ActiveWidgets; }

	UFUNCTION(BlueprintCallable)
	UUserWidget* ShowWidget(const EWidgetIDs WidgetID, const int32 ZOrder = 0);

	UFUNCTION(BlueprintCallable)
	void HideWidget(const EWidgetIDs WidgetID);
};
