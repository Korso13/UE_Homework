// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TankGameInstance.generated.h"

class UDataTable;
class USaveManager;

UENUM(BlueprintType)
enum class EMenuStyle : uint8
{
	MS_Default,
	MS_Peaceful
};

USTRUCT(Blueprintable)
struct FGameSettings
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EMenuStyle MenuStyle = EMenuStyle::MS_Default;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* StartingLoadout;
};

/**
 * 
 */
UCLASS()
class TANKOGEDDON_API UTankGameInstance : public UGameInstance
{
	GENERATED_BODY()

	virtual void Shutdown() override;

	virtual void OnStart() override;

	virtual void Init() override;

	UPROPERTY()
	USaveManager* SaveManager;
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameSettings GameSettings;

	UFUNCTION(BlueprintPure, meta=(WorldContext=WorldContextObject)) 
	static USaveManager* GetSaveManager(UObject* WorldContextObject);
};
