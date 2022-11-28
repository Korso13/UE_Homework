// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpawnerPanel.generated.h"

class UVerticalBox;
class UImage;
class UTextBlock;

/**
 * 
 */
UCLASS()
class TANKOGEDDON_API USpawnerPanel : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(BindWidget))
	UVerticalBox* SpawnList;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	UImage* MenuIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* OpenCloseMenuAnim;
		
	UPROPERTY(meta = (BindWidget))
	UTextBlock* BuildingNanitesIndicator;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 BuldingNaniteCount;

	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void SwitchMenu();

	UFUNCTION()
	void HideMenu();

	bool bMenuOpen;

	FWidgetAnimationDynamicEvent OnCloseMenuAnimEnded;

public:
	UFUNCTION(BlueprintCallable)
	int32 GetNantiteCount() const { return BuldingNaniteCount; };

	UFUNCTION(BlueprintCallable)
	void SetNaniteCount(int32 InCount);
};
