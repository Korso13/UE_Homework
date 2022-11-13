// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUISlateWidgetStyle.h"

FMainUISlateStyle::FMainUISlateStyle()
{
}

FMainUISlateStyle::~FMainUISlateStyle()
{
}

const FName FMainUISlateStyle::TypeName(TEXT("FMainUISlateStyle"));

const FMainUISlateStyle& FMainUISlateStyle::GetDefault()
{
	static FMainUISlateStyle Default;
	return Default;
}

void FMainUISlateStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	OutBrushes.Add(&ImageBrush);
	TitleTextStyle.GetResources(OutBrushes);
	FSlateWidgetStyle::GetResources(OutBrushes);
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

