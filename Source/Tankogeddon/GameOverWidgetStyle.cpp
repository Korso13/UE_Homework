// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidgetStyle.h"

FGameOverStyle::FGameOverStyle()
{
}

FGameOverStyle::~FGameOverStyle()
{
}

const FName FGameOverStyle::TypeName(TEXT("FGameOverStyle"));

const FGameOverStyle& FGameOverStyle::GetDefault()
{
	static FGameOverStyle Default;
	return Default;
}

void FGameOverStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	OutBrushes.Add(&ImageBrush);
	OutBrushes.Add(&BorderBrush);
	FSlateWidgetStyle::GetResources(OutBrushes);
	
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

