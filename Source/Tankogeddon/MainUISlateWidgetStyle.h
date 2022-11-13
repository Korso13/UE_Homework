// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "MainUISlateWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct TANKOGEDDON_API FMainUISlateStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FMainUISlateStyle();
	virtual ~FMainUISlateStyle();

	UPROPERTY(EditAnywhere, Category = "Appearance")
	FSlateBrush ImageBrush;

	UPROPERTY(EditAnywhere, Category = "Appearance")
	FTextBlockStyle TitleTextStyle;

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMainUISlateStyle& GetDefault();
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class UMainUISlateWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FMainUISlateStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
