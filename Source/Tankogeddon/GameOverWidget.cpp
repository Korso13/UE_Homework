// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include "CustomCoreStyleLib.h"
#include "Components/Image.h"
#include "Components/RichTextBlock.h"
#include "Components/border.h"


void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (GameOverStyleSelector == GOStyles::default_style)
	{
		GameOverWidgetStyle = FCustomCoreStyleLib::Get().GetWidgetStyle<FGameOverStyle>("WS_GameOver_default");
		RichTextBlock_gameover->SetText(FText::FromString("<DefaultStyle>GAME OVER !</>"));
	}
	else if (GameOverStyleSelector == GOStyles::Dont_Hurt_Me_style)
	{
		GameOverWidgetStyle = FCustomCoreStyleLib::Get().GetWidgetStyle<FGameOverStyle>("WS_GameOver_peaceful");
		RichTextBlock_gameover->SetText(FText::FromString("<Consoling>Don't worry! You'll get them next time!</>"));
	}

	background_image->SetBrush(GameOverWidgetStyle.ImageBrush);
	img_border->SetBrush(GameOverWidgetStyle.BorderBrush);
	img_border->SetBrushColor(GameOverWidgetStyle.BorderColor);

	this->RebuildWidget();
}

void UGameOverWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (GameOverStyleSelector == GOStyles::default_style)
	{
		GameOverWidgetStyle = FCustomCoreStyleLib::Get().GetWidgetStyle<FGameOverStyle>("WS_GameOver_default");
		RichTextBlock_gameover->SetText(FText::FromString("<DefaultStyle>GAME OVER !</>"));
	}
	else if (GameOverStyleSelector == GOStyles::Dont_Hurt_Me_style)
	{
		GameOverWidgetStyle = FCustomCoreStyleLib::Get().GetWidgetStyle<FGameOverStyle>("WS_GameOver_peaceful");
		RichTextBlock_gameover->SetText(FText::FromString("<Consoling>Don't worry! You'll get them next time!</>"));
	}

	background_image->SetBrush(GameOverWidgetStyle.ImageBrush);
	img_border->SetBrush(GameOverWidgetStyle.BorderBrush);
	img_border->SetBrushColor(GameOverWidgetStyle.BorderColor);

}
