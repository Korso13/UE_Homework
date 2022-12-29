// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SaveManager.generated.h"

class UTankSaveGame;
class USaveGame;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSaveLoad, const FString, SlotName);

/**
 * 
 */
UCLASS()
class TANKOGEDDON_API USaveManager : public UObject
{
	GENERATED_BODY()

protected:

	void OnGameLoadedFunc(const FString& SlotName, const int32 UserIndex, USaveGame* SaveGame);

	void OnGameSavedFunc(const FString& SlotName, const int32 UserIndex, bool bSuccess);

	void UpateDynamicSaveData();
	
public:

	void Init();

	UPROPERTY(BlueprintReadWrite)
	UTankSaveGame* CurrentSave;

	UPROPERTY()
	TArray<AActor*> ProceduralySpawnedActors; //these are killed on load and only ones mentioned in Save File will be respawned

	UFUNCTION(BlueprintCallable)
	void SaveGame(const FString SlotName);

	UFUNCTION(BlueprintCallable)
	void LoadGame(const FString SlotName);

	UFUNCTION(BlueprintPure)
	bool IsSaveGameExist(const FString& SlotName) const;

	UPROPERTY(BlueprintAssignable)
	FOnGameSaveLoad OnGameLoaded;

	UPROPERTY(BlueprintAssignable)
	FOnGameSaveLoad OnGameSaved;

	
};
