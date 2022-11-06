// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "RadioButtons.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewRadioButtonSelected, int32, Index);

class SSRadioButtons;

UCLASS()
class TANKOGEDDON_API URadioButtons : public UWidget
{
	GENERATED_BODY()

private:
	TSharedPtr<SSRadioButtons> RadioButtonWidget;
protected:
	TSharedRef<SWidget> RebuildWidget();

	UPROPERTY(BlueprintAssignable)
	FOnNewRadioButtonSelected OnNewRadioButtonSelected;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Radio Button Settings")
	int32 ButtonSelectedOnStartIndex;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Radio Button Settings")
	int32 ButtonCount;

	void OnNewButtonSelected(int32 InIndex) const;

	virtual const FText GetPaletteCategory() override;
public:
	void ReleaseSlateResources(bool bReleaseChildren);

	int32 GetButtonCount() const { return ButtonCount; };
};
