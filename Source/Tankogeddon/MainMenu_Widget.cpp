// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu_Widget.h"
#include "CustomCoreStyleLib.h"
#include "MainUISlateWidgetStyle.h"
#include "Components/Image.h"
#include "Components/RichTextBlock.h"

void UMainMenu_Widget::SetNewMMStyle(MMStyles InStyle)
{
	MainMenuStyleSelector = InStyle;
	this->NativeConstruct();
}

void UMainMenu_Widget::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (MainMenuStyleSelector == MMStyles::default_style)
	{
		MainMenuStyle = FCustomCoreStyleLib::Get().GetWidgetStyle<FMainUISlateStyle>("WS_MainMenu_default");
		HL_text->SetText(FText::FromString("<HeadlineT1>Tankogeddon</>"));
	}
	else if (MainMenuStyleSelector == MMStyles::peaceful_style)
	{
		MainMenuStyle = FCustomCoreStyleLib::Get().GetWidgetStyle<FMainUISlateStyle>("WS_MainMenu_peaceful");
		HL_text->SetText(FText::FromString("<peaceful>Tanks and Hugs</>"));
	}

	HL_text->SetDefaultTextStyle(MainMenuStyle.TitleTextStyle);
	main_menu_back_pic->SetBrush(MainMenuStyle.ImageBrush);
	
	this->RebuildWidget();
}

void UMainMenu_Widget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (MainMenuStyleSelector == MMStyles::default_style)
	{
		MainMenuStyle = FCustomCoreStyleLib::Get().GetWidgetStyle<FMainUISlateStyle>("WS_MainMenu_default");
		HL_text->SetText(FText::FromString("<HeadlineT1>Tankogeddon</>"));
	}
	else if (MainMenuStyleSelector == MMStyles::peaceful_style)
	{
		MainMenuStyle = FCustomCoreStyleLib::Get().GetWidgetStyle<FMainUISlateStyle>("WS_MainMenu_peaceful");
		HL_text->SetText(FText::FromString("<peaceful>Tanks and Hugs</>"));
	}

	HL_text->SetDefaultTextStyle(MainMenuStyle.TitleTextStyle);
	main_menu_back_pic->SetBrush(MainMenuStyle.ImageBrush);
}
