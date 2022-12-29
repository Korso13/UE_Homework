// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameInstance.h"
#include "CustomCoreStyleLib.h"
#include "SaveManager.h"
#include "Kismet/GameplayStatics.h"

void UTankGameInstance::Shutdown()
{
	FCustomCoreStyleLib::Shutdown();

	//Super::Shutdown();
}

void UTankGameInstance::OnStart()
{
	FCustomCoreStyleLib::Initialize();
	FCustomCoreStyleLib::Get();

	Super::OnStart();
}

void UTankGameInstance::Init()
{
	Super::Init();

	SaveManager = NewObject<USaveManager>(this);
	if(SaveManager)
	{
		SaveManager->Init();
	}
}

USaveManager* UTankGameInstance::GetSaveManager(UObject* WorldContextObject)
{
	auto* MyInstance = Cast<UTankGameInstance>(UGameplayStatics::GetGameInstance(WorldContextObject));
	return MyInstance ? MyInstance->SaveManager : nullptr;
}
