// Fill out your copyright notice in the Description page of Project Settings.


#include "SSRadioButtons.h"
#include "SlateOptMacros.h"
#include "Templates/SharedPointer.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSRadioButtons::Construct(const FArguments& InArgs)
{
	ButtonCountAtt = InArgs._ButtonCount;
	InButtonCaptions = InArgs._ButtonCaptions;
	ButtonCaptions = InButtonCaptions.Get(); //getting starting list of button captions
	SelectedButton = InArgs._SelectedOnStartIndex;
	ButtonSelectedDelegate = InArgs._OnRadioButtonSelected;
	RadioButtonsStyle = InArgs._ButtonsStyle;
	SSRadioButtons::OnRadioButtonsRebuild.AddRaw(this, &SSRadioButtons::RebuildRadioButtons);
	SSRadioButtons::OnButtonsCaptionsChanged.AddRaw(this, &SSRadioButtons::UpdateCaptionsList);
	ChildSlot
	[
		SAssignNew(ButtonHolder, SVerticalBox)
		
	];

	for (size_t i = 0; i < ButtonCountAtt.Get(); i++)
	{
		ButtonHolder->AddSlot()
		[
			CreateRadioButton(i, FText::FromString( (i < ButtonCaptions.Num()) ? (ButtonCaptions[i]) : ("Option")))
		];
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

TSharedRef<SCheckBox> SSRadioButtons::CreateRadioButton(int32 InIndex, FText ButtonCaption)
{
	return SNew(SCheckBox)
		.OnCheckStateChanged_Raw(this, &SSRadioButtons::OnStateChanged, InIndex)
		.IsChecked_Raw(this, &SSRadioButtons::IsChecked, InIndex)
		.Style(&RadioButtonsStyle->CheckBoxStyle)
		[
			SNew(STextBlock)
			.Text(ButtonCaption)
			.TextStyle(&RadioButtonsStyle->TextStyle)
		];
}

void SSRadioButtons::RebuildRadioButtons()
{
	ButtonHolder->ClearChildren();
	for (size_t i = 0; i < ButtonCountAtt.Get(); i++)
	{
		ButtonHolder->AddSlot()
		[
			CreateRadioButton(i, FText::FromString((i < ButtonCaptions.Num()) ? (ButtonCaptions[i]) : ("Option")))
		];
	}
	SelectedButton = 0;
}

void SSRadioButtons::UpdateCaptionsList()
{
	ButtonCaptions.Reset();
	ButtonCaptions = InButtonCaptions.Get();
	OnRadioButtonsRebuild.Broadcast();
}

void SSRadioButtons::OnStateChanged(ECheckBoxState NewState, int32 InIndex)
{
	if (NewState == ECheckBoxState::Checked)
	{
		SelectedButton = InIndex;
		ButtonSelectedDelegate.ExecuteIfBound(InIndex);
	}
}

ECheckBoxState SSRadioButtons::IsChecked(int32 InIndex) const
{
	return InIndex == SelectedButton ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

int32 SSRadioButtons::OnPaint
(
	const FPaintArgs& Args,
	const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect,
	FSlateWindowElementList& OutDrawElements,
	int32 LayerId,
	const FWidgetStyle& InWidgetStyle,
	bool bParentEnabled
) const 
{
	if (ButtonHolder->NumSlots() != ButtonCountAtt.Get())
		OnRadioButtonsRebuild.Broadcast();
	if (InButtonCaptions.Get() != ButtonCaptions)
		OnButtonsCaptionsChanged.Broadcast();
	return SCompoundWidget::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
}
