// Fill out your copyright notice in the Description page of Project Settings.


#include "SSRadioButtons.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSRadioButtons::Construct(const FArguments& InArgs)
{
	ButtonCountAtt = InArgs._ButtonCount;
	SelectedButton = InArgs._SelectedOnStartIndex;
	ButtonSelectedDelegate = InArgs._OnRadioButtonSelected;
	SSRadioButtons::OnRadioButtonsRebuild.AddRaw(this, &SSRadioButtons::RebuildRadioButtons);

	ChildSlot
	[
		SAssignNew(ButtonHolder, SVerticalBox)
		
	];

	for (size_t i = 0; i < ButtonCountAtt.Get(); i++)
	{
		ButtonHolder->AddSlot()
		[
			CreateRadioButton(i)
		];
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

TSharedRef<SCheckBox> SSRadioButtons::CreateRadioButton(int32 InIndex, FText ButtonCaption)
{
	return SNew(SCheckBox)
		.OnCheckStateChanged_Raw(this, &SSRadioButtons::OnStateChanged, InIndex)
		.IsChecked_Raw(this, &SSRadioButtons::IsChecked, InIndex)
		[
			SNew(STextBlock)
			.Text(ButtonCaption)
		];
}

void SSRadioButtons::RebuildRadioButtons()
{
	ButtonHolder->ClearChildren();
	for (size_t i = 0; i < ButtonCountAtt.Get(); i++)
	{
		ButtonHolder->AddSlot()
		[
			CreateRadioButton(i)
		];
	}
	SelectedButton = 0;
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
	return SCompoundWidget::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
}


//to be used later, maybe
void SSRadioButtons::SetButtonCaption(int32 InIndex, FText ButtonCaption)
{
	static_cast<STextBlock&>(ButtonHolder->GetChildren()->GetChildAt(InIndex).Get())
	.SetText(ButtonCaption);
}

void SSRadioButtons::RemoveRadioButton(int32 InIndex)
{
	ButtonHolder->RemoveSlot(ButtonHolder->GetChildren()->GetChildAt(InIndex));
}


