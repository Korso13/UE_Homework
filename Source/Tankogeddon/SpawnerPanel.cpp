// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerPanel.h"
#include "TankPlayerController.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "Animation/WidgetAnimation.h"
#include "Kismet/GameplayStatics.h"

void USpawnerPanel::NativeConstruct()
{
	bMenuOpen = false;
	BuildingNanitesIndicator->SetText(FText::FromString(FString::Printf(TEXT("%d"), BuldingNaniteCount)));

	Cast<ATankPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->InputComponent->
		BindKey(EKeys::H, EInputEvent::IE_Pressed, this, &USpawnerPanel::SwitchMenu);
	OnCloseMenuAnimEnded.BindDynamic(this, &USpawnerPanel::HideMenu);
	BindToAnimationFinished(OpenCloseMenuAnim, OnCloseMenuAnimEnded);
}

void USpawnerPanel::SwitchMenu()
{
	if (SpawnList)
	{
		if (bMenuOpen)
		{
			bMenuOpen = false;
			if(OpenCloseMenuAnim)
				PlayAnimation(OpenCloseMenuAnim, 0.0f, 1, EUMGSequencePlayMode::Reverse, 1.0f, false);
		}
		else
		{
			SpawnList->SetVisibility(ESlateVisibility::Visible);
			bMenuOpen = true;
			if (OpenCloseMenuAnim)
				PlayAnimation(OpenCloseMenuAnim, 0.0f, 1, EUMGSequencePlayMode::Forward, 1.0f, false);
		}
	}
}

void USpawnerPanel::HideMenu()
{
	if(!bMenuOpen)
		SpawnList->SetVisibility(ESlateVisibility::Hidden);
}

void USpawnerPanel::SetNaniteCount(int32 InCount)
{
	BuldingNaniteCount = InCount;
	BuildingNanitesIndicator->SetText(FText::FromString(FString::Printf(TEXT("%d"), BuldingNaniteCount)));
}

