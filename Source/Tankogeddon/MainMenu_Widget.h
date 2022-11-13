// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUISlateWidgetStyle.h"
#include "MainMenu_Widget.generated.h"

class UImage;
class URichTextBlock;

UENUM(BlueprintType)
enum class MMStyles : uint8
{
	default_style = 0,
	peaceful_style = 1
};

UCLASS(Abstract)
class TANKOGEDDON_API UMainMenu_Widget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (BindWidget))
	UImage* main_menu_back_pic;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget))
	URichTextBlock* HL_text;

	UPROPERTY(EditAnywhere, Category = "Appearance", Meta = (DisplayName = "Main Menu Style"))
	MMStyles MainMenuStyleSelector = MMStyles::default_style;

	UFUNCTION(BlueprintCallable)
	void SetNewMMStyle(MMStyles InStyle);

	virtual void NativeConstruct() override;

	virtual void NativePreConstruct() override;

private:
	FMainUISlateStyle MainMenuStyle;
};
