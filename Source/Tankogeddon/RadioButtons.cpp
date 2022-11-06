// Fill out your copyright notice in the Description page of Project Settings.


#include "RadioButtons.h"
#include "SSRadioButtons.h"

TSharedRef<SWidget> URadioButtons::RebuildWidget()
{
	RadioButtonWidget = SNew(SSRadioButtons)
	.ButtonCount_UObject(this, &URadioButtons::GetButtonCount)
	.SelectedOnStartIndex(ButtonSelectedOnStartIndex)
	.OnRadioButtonSelected_UObject(this, &URadioButtons::OnNewButtonSelected);
	
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
