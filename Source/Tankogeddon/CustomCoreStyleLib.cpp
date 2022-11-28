// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomCoreStyleLib.h"
#include "Slate/SlateGameResources.h"
//#include "Engine/GameInstance.h"
//#include "Kismet/GameplayStatics.h"

TSharedPtr<ISlateStyle> FCustomCoreStyleLib::StyleLibPtr;

TSharedPtr<ISlateStyle> CreateStyleLib()
{
	const FString PathToContent("/Game/UI_Styles");
	TSharedPtr<ISlateStyle> Library = FSlateGameResources::New(FName("Custom_Core_Style_Library"), PathToContent, PathToContent);

	//UGameplayStatics::GetGameInstance(UGameInstance::GetWorld())

	return Library;
}

void FCustomCoreStyleLib::Initialize()
{
	Shutdown();

	StyleLibPtr = CreateStyleLib();
	FSlateStyleRegistry::RegisterSlateStyle(*StyleLibPtr);
}

void FCustomCoreStyleLib::Shutdown()
{
	if (StyleLibPtr.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleLibPtr);
		StyleLibPtr.Reset();
	}
}

const ISlateStyle& FCustomCoreStyleLib::Get()
{
	if (!StyleLibPtr.IsValid())
	{
		Initialize();
	}
	return *StyleLibPtr;
}
