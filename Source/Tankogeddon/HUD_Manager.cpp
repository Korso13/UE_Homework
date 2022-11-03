// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_Manager.h"
#include "Blueprint/UserWidget.h"

UUserWidget* AHUD_Manager::CreateWidgetByClass(const EWidgetIDs WidgetID, const TSubclassOf<UUserWidget> NewWidget)
{
	return ActiveWidgets.Add(WidgetID, CreateWidget(GetOwningPlayerController(), NewWidget));
}

UUserWidget* AHUD_Manager::ShowWidget(const EWidgetIDs WidgetID, const int32 ZOrder)
{
	if (ActiveWidgets.Find(WidgetID) == nullptr)
	{
		TSubclassOf<UUserWidget>* WidgetClass = WidgetClasses.Find(WidgetID);
		if (WidgetClass && *WidgetClass)
		{
			UUserWidget* NewWidget = CreateWidgetByClass(WidgetID, *WidgetClass);
			if (NewWidget != nullptr)
			{
				NewWidget->AddToViewport(ZOrder);
			}
			return NewWidget;
		}
	}
	
	return nullptr;
}

void AHUD_Manager::HideWidget(const EWidgetIDs WidgetID)
{
	//UUserWidget* WidgetToRemove = *(.Find(WidgetID));
	if (ActiveWidgets.Contains(WidgetID))
	{
		ActiveWidgets[WidgetID]->RemoveFromParent();
		ActiveWidgets.Remove(WidgetID);
	}
}
