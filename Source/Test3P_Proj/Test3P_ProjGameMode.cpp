// Copyright Epic Games, Inc. All Rights Reserved.

#include "Test3P_ProjGameMode.h"
#include "Test3P_ProjCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATest3P_ProjGameMode::ATest3P_ProjGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
