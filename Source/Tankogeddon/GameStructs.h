// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameStructs.generated.h"

/**
 * 
 */


UENUM(BlueprintType)
enum class CanonType : uint8 {
	ProjectileCanon = 0,
	LaserCanon = 1
};

UENUM()
enum class FireType : uint8 {
	Primary = 0,
	Secondary = 1
};

UCLASS()
class TANKOGEDDON_API UGameStructs : public UObject
{
	GENERATED_BODY()
	
};
