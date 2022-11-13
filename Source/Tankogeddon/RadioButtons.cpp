// Fill out your copyright notice in the Description page of Project Settings.

#include "RadioButtons.h"
#include "SSRadioButtons.h"
#include "CustomCoreStyleLib.h"

TSharedRef<SWidget> URadioButtons::RebuildWidget()
{
	RadioButtonStyle = (RadioButtonStyleSelector == RBStyles::default_style) ?
		(FCustomCoreStyleLib::Get().GetWidgetStyle<FRadioButtonsStyle>("WS_RadioButton_Default")) :
		(FCustomCoreStyleLib::Get().GetWidgetStyle<FRadioButtonsStyle>("WS_RadioButton_Alternative"));

	RadioButtonWidget = SNew(SSRadioButtons)
	.ButtonCount_UObject(this, &URadioButtons::GetButtonCount)
	.ButtonCaptions_UObject(this, &URadioButtons::GetButtonCaptions)
	.SelectedOnStartIndex(ButtonSelectedOnStartIndex)
	.OnRadioButtonSelected_UObject(this, &URadioButtons::OnNewButtonSelected)
	.ButtonsStyle(&RadioButtonStyle);

	return RadioButtonWidget.ToSharedRef();
}

void URadioButtons::OnNewButtonSelected(int32 InIndex) const
{
	OnNewRadioButtonSelected.Broadcast(InIndex);
}

void URadioButtons::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	RadioButtonWidget.Reset();
}

#if WITH_EDITOR

const FText URadioButtons::GetPaletteCategory()
{
	return FText::FromString(TEXT("Custom Slate Widgets"));
}

#endif
