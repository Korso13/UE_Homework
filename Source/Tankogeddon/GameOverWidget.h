// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidgetStyle.h"
#include "GameOverWidget.generated.h"

class UBorder;
class UImage;
class URichTextBlock;

UENUM(BlueprintType)
enum class GOStyles : uint8
{
	default_style = 0,
	Dont_Hurt_Me_style = 1
};

/**
 * 
 */
UCLASS()
class TANKOGEDDON_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget))
	UImage* background_image;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget))
	UBorder* img_border;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget))
	URichTextBlock* RichTextBlock_gameover;

	UPROPERTY(EditAnywhere, Category = "Appearance", Meta = (DisplayName = "Game Over Widget Style"))
	GOStyles GameOverStyleSelector = GOStyles::default_style;

	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;

private:
	FGameOverStyle GameOverWidgetStyle;
};
