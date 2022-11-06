// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"


DECLARE_DELEGATE_OneParam(FOnRadioButtonSelected, int32)
DECLARE_EVENT(SSRadioButtons, FOnRadioButtonsRebuild)
/**
 * 
 */
class TANKOGEDDON_API SSRadioButtons : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSRadioButtons)
	{}

	SLATE_ATTRIBUTE(int32, ButtonCount)
	SLATE_ARGUMENT(int32, SelectedOnStartIndex)
	SLATE_EVENT(FOnRadioButtonSelected, OnRadioButtonSelected)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TSharedRef<SCheckBox> CreateRadioButton(int32 InIndex, FText ButtonCaption = FText::FromString(TEXT("Radio Button")));

	void RebuildRadioButtons(); 

	FOnRadioButtonSelected ButtonSelectedDelegate;

	FOnRadioButtonsRebuild OnRadioButtonsRebuild;

private:
	int32 SelectedButton;

	TAttribute<int32> ButtonCountAtt;

	TSharedPtr<SVerticalBox> ButtonHolder;

	void OnStateChanged(ECheckBoxState NewState, int32 InIndex);

	ECheckBoxState IsChecked(int32 InIndex) const;

	virtual int32 OnPaint
	(
		const FPaintArgs& Args,
		const FGeometry& AllottedGeometry,
		const FSlateRect& MyCullingRect,
		FSlateWindowElementList& OutDrawElements,
		int32 LayerId,
		const FWidgetStyle& InWidgetStyle,
		bool bParentEnabled
	) const;


	void SetButtonCaption(int32 InIndex, FText ButtonCaption);
	void RemoveRadioButton(int32 InIndex);
};
