// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "RadioButtonsWidgetStyle.h"


DECLARE_DELEGATE_OneParam(FOnRadioButtonSelected, int32)
DECLARE_EVENT(SSRadioButtons, FOnRadioButtonsRebuild)
DECLARE_EVENT(SSRadioButtons, FOnButtonsCaptionsChanged)
/**
 * 
 */
class TANKOGEDDON_API SSRadioButtons : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSRadioButtons)
	{}

	SLATE_ATTRIBUTE(int32, ButtonCount)
	SLATE_ATTRIBUTE(TArray<FString>, ButtonCaptions)
	SLATE_ARGUMENT(int32, SelectedOnStartIndex)
	SLATE_EVENT(FOnRadioButtonSelected, OnRadioButtonSelected)
	SLATE_STYLE_ARGUMENT(FRadioButtonsStyle, ButtonsStyle)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TSharedRef<SCheckBox> CreateRadioButton(int32 InIndex, FText ButtonCaption = FText::FromString(TEXT("Radio Button")));

	void RebuildRadioButtons(); 

	void UpdateCaptionsList();

	FOnRadioButtonSelected ButtonSelectedDelegate;

	FOnRadioButtonsRebuild OnRadioButtonsRebuild;

	FOnButtonsCaptionsChanged OnButtonsCaptionsChanged;

private:
	int32 SelectedButton;

	TAttribute<int32> ButtonCountAtt;

	TAttribute<TArray<FString>> InButtonCaptions;

	TArray<FString> ButtonCaptions;

	TSharedPtr<SVerticalBox> ButtonHolder;

	const FRadioButtonsStyle* RadioButtonsStyle = nullptr;

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
};
