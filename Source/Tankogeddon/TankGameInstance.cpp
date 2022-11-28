// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameInstance.h"
#include "CustomCoreStyleLib.h"

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
