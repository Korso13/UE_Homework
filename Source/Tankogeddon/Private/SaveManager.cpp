// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManager.h"
#include "GameFramework/SaveGame.h"
#include "TankSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Tankogeddon/Base_Pawn.h"
#include "Tankogeddon/TankFactory.h"
#include "TankWithInventory.h"
#include "Tankogeddon/EnemyTankAIController.h"

void USaveManager::OnGameLoadedFunc(const FString& SlotName, const int32 UserIndex, USaveGame* SaveGame)
{
	CurrentSave = Cast<UTankSaveGame>(SaveGame);
	if (OnGameLoaded.IsBound())
	{
		OnGameLoaded.Broadcast(SlotName);
	}

	//Starting to restore game state from loaded save file
	if(UGameplayStatics::GetCurrentLevelName(GetWorld()) != CurrentSave->CurrentLevel)
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName{CurrentSave->CurrentLevel});
	}

	//restoring player tank's state
	if(ATankWithInventory* PlayerTank = Cast<ATankWithInventory>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()))
	{
		PlayerTank->LoadState(CurrentSave->TankPawnState);
	}
	
	//copying TMap with pawns to avoid changes to it during for-ranged cycle. Clearing original TMap as well
	auto PawnsToRestore = CurrentSave->EnemyPawns; 
	CurrentSave->EnemyPawns.Empty();
	//restoring enemy pawns
	for(auto [PawnName, Pawn] : PawnsToRestore)
	{
		if(Pawn.SavedPawn)
		{
			FString NameOld = Pawn.SavedPawn->GetName();
			Pawn.SavedPawn->Destroy();
			Pawn.SavedPawn->DisableComponentsSimulatePhysics();
			Pawn.SavedPawn->SetActorEnableCollision(false);
			Pawn.SavedPawn->SetHidden(true);
		}

		if(!Pawn.IsDead)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			Pawn.SavedPawn = GetWorld()->SpawnActor<ABase_Pawn>(Pawn.PawnClass, Pawn.PawnLocation, Pawn.PawnRotation, SpawnParams);
		}
		
		if(Pawn.SavedPawn) //pawn is and should be alive, restoring previous state
		{
			FString NameNew = Pawn.SavedPawn->GetName();
			Pawn.SavedPawn->LoadState(Pawn);
		}
		CurrentSave->EnemyPawns.Remove(PawnName); //removing records of no longer valid old pawns. New ones have already registered
	}

	//copying TMap with buildings to avoid changes to it during for-ranged cycle. Clearing original TMap as well
	auto BuildingsToRestore = CurrentSave->Buildings;
	CurrentSave->Buildings.Empty();

	//restoring interactive Actor-buildings (Only TankFactory for now, TODO: add satellite stations, depots, pickups (preferably via an interface)
	for(auto [BuildingName, Building] : BuildingsToRestore)
	{
		if(Building.SavedBuilding)
		{
			Building.SavedBuilding->Destroy();
			Building.SavedBuilding->DisableComponentsSimulatePhysics();
			Building.SavedBuilding->SetActorEnableCollision(false);
			Building.SavedBuilding->SetHidden(true);
		}

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		Building.SavedBuilding = GetWorld()->SpawnActor<AActor>(Building.BuildingClass, Building.BuildingLocation, Building.BuildingRotation, SpawnParams);
		
		//restoring tank factory TODO: remake via interface for all buildings
		if(Building.SavedBuilding)
		{
			Cast<ATankFactory>(Building.SavedBuilding)->LoadState(Building);
		}
		CurrentSave->Buildings.Remove(BuildingName); //removing old instances of Buildings
	}
}

void USaveManager::OnGameSavedFunc(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
	if (OnGameSaved.IsBound() && bSuccess)
	{
		OnGameSaved.Broadcast(SlotName);
	}
	else if(!bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("Save failed"));
	}
}

void USaveManager::UpateDynamicSaveData()
{
	if(!CurrentSave)
	{
		return;
	}

	ATankWithInventory* PlayerPawn = Cast<ATankWithInventory>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());
	CurrentSave->TankPawnState.PawnLocation = PlayerPawn->GetActorLocation();
	CurrentSave->TankPawnState.PawnRotation = PlayerPawn->GetActorRotation();
	CurrentSave->TankPawnState.PlayerTotalScore = PlayerPawn->GetTotalScore();

	for(auto& [PawnName, Pawn ]: CurrentSave->EnemyPawns)
	{
		if(Pawn.SavedPawn && !Pawn.IsDead)
		{
			Pawn.PawnLocation = Pawn.SavedPawn->GetActorLocation();
			Pawn.PawnRotation = Pawn.SavedPawn->GetActorRotation();
		}

		if(Pawn.SavedPawn)
		{
			Pawn = Pawn.SavedPawn->GetPawnState();
		}

		if(!Pawn.SavedPawn)
			Pawn.IsDead = true;
	}

	for(auto& [BuildingName, Building ]: CurrentSave->Buildings)
	{
		if(Building.SavedBuilding)
		{
			auto TankFactory = Cast<ATankFactory>(Building.SavedBuilding);
			if(TankFactory)
			{
				Building = TankFactory->GetBuildingState();
			}
		}
	}

	CurrentSave->CurrentLevel = UGameplayStatics::GetCurrentLevelName(GetWorld());
}

void USaveManager::Init()
{
	CurrentSave = Cast<UTankSaveGame>(UGameplayStatics::CreateSaveGameObject(UTankSaveGame::StaticClass()));
}

void USaveManager::SaveGame(const FString SlotName)
{
	FAsyncSaveGameToSlotDelegate AsyncSaveDelegate;
	AsyncSaveDelegate.BindUObject(this, &USaveManager::OnGameSavedFunc);
	UpateDynamicSaveData();
	
	UGameplayStatics::AsyncSaveGameToSlot(CurrentSave, SlotName, 0, AsyncSaveDelegate);
}

void USaveManager::LoadGame(const FString SlotName)
{
	if(!IsSaveGameExist(SlotName))
	{
		return;
	}

	FAsyncLoadGameFromSlotDelegate AsyncLoadDelegate;
	AsyncLoadDelegate.BindUObject(this, &USaveManager::OnGameLoadedFunc);

	UGameplayStatics::AsyncLoadGameFromSlot(SlotName, 0, AsyncLoadDelegate);
}

bool USaveManager::IsSaveGameExist(const FString& SlotName) const
{
	return UGameplayStatics::DoesSaveGameExist(SlotName, 0);
}
