// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "InventoryStructs.h"
//#include "../Base_Pawn.h"

#include "TankSaveGame.generated.h"

class ABase_Pawn;

USTRUCT(BlueprintType)
struct FPawnState
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	FVector PawnLocation;
	
	UPROPERTY(BlueprintReadWrite)
	FRotator PawnRotation;

	UPROPERTY(BlueprintReadWrite)
	float PawnHP;

	UPROPERTY(BlueprintReadWrite)
	int32 PawnAmmoPrimary;

	UPROPERTY(BlueprintReadWrite)
	int32 PawnAmmoSecondary = 0; //for main character only

	UPROPERTY(BlueprintReadWrite)
	int32 PlayerTotalScore; //for player character only

	// call LoadInventory() (through GetInventoryManager() fields) in respective inventories on load game after nulling Starting Loadout!
	TMap<int32, FInventorySlotInfo> InventoryContents;  //for main character only
	TMap<int32, FInventorySlotInfo> EquipInventoryContents; //for main character only
	
	UPROPERTY(BlueprintReadWrite)
	bool IsAI = false;

	//AI pawn-related fields:
	UPROPERTY(BlueprintReadWrite)
	bool IsDead = false; //needed for loads for earlier save (or level start) into the same level but with some enemies already killed

	UPROPERTY(BlueprintReadWrite)
	ABase_Pawn* SavedPawn; //if not valid on load, spawn anew and write into this var

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<ABase_Pawn> PawnClass; //in case need to respawn non-existing pawn

	UPROPERTY(BlueprintReadWrite)
	FName AIPawnPatrollingPointTag; //in case need to respawn non-existing pawn

	UPROPERTY(BlueprintReadWrite)
	int32 PawnCurrentWaypointIndex = 0;
};

USTRUCT(BlueprintType)
struct FBuildingState //such as TankFactories and Satellite stations
{
	GENERATED_BODY()

	//general data
	UPROPERTY()
	AActor* SavedBuilding;

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<AActor> BuildingClass;

	UPROPERTY(BlueprintReadWrite)
	FVector BuildingLocation;
	
	UPROPERTY(BlueprintReadWrite)
	FRotator BuildingRotation;

	UPROPERTY(BlueprintReadWrite)
	bool IsDestroyed = false;

	UPROPERTY(BlueprintReadWrite)
	bool IsEnemy;

	UPROPERTY(BlueprintReadWrite)
	TArray<FName> ActorTags;

	//TankFactory-related data:
	UPROPERTY(BlueprintReadWrite)
	float BuildingHP;

	UPROPERTY(BlueprintReadWrite)
	FString PatrollingPointTag;

	UPROPERTY(BlueprintReadWrite)
	int32 CurrentPatrollingID = 0;

	UPROPERTY()
	FTimerHandle SpawnTimer;

};

/**
 * 
 */
UCLASS()
class TANKOGEDDON_API UTankSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	//Level name
	UPROPERTY(BlueprintReadWrite)
	FString CurrentLevel; 

	//Player tank save data:
	UPROPERTY(BlueprintReadWrite)
	FPawnState TankPawnState;
	
	//Enemies save data:
	UPROPERTY(BlueprintReadWrite)
	TMap<FString /*Object name*/, FPawnState> EnemyPawns;

	//Interactive Buildings (such as TankFactories and Satellite stations) save data:
	UPROPERTY(BlueprintReadWrite)
	TMap<FString /*Object name*/, FBuildingState> Buildings;
	
};
