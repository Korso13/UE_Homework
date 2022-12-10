// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TANKINVENTORYSYSTEM_InventoryStructs_generated_h
#error "InventoryStructs.generated.h already included, missing '#pragma once' in InventoryStructs.h"
#endif
#define TANKINVENTORYSYSTEM_InventoryStructs_generated_h

#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryStructs_h_102_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FInventorySlotInfo_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> TANKINVENTORYSYSTEM_API UScriptStruct* StaticStruct<struct FInventorySlotInfo>();

#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryStructs_h_57_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FInventoryItemInfo_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> TANKINVENTORYSYSTEM_API UScriptStruct* StaticStruct<struct FInventoryItemInfo>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryStructs_h


#define FOREACH_ENUM_EINVENTORYCLASS(op) \
	op(EInventoryClass::IC_CharInventory) \
	op(EInventoryClass::IC_EquipInventory) \
	op(EInventoryClass::IC_Chest) 

enum class EInventoryClass : uint8;
template<> TANKINVENTORYSYSTEM_API UEnum* StaticEnum<EInventoryClass>();

#define FOREACH_ENUM_EEQUIPSLOT(op) \
	op(EEquipSlot::EQ_NONE) \
	op(EEquipSlot::EQ_PrimaryCannon) \
	op(EEquipSlot::EQ_SecondaryCannon) \
	op(EEquipSlot::EQ_Armor) \
	op(EEquipSlot::EQ_PowerModule) \
	op(EEquipSlot::EQ_Consumable) 

enum class EEquipSlot : uint8;
template<> TANKINVENTORYSYSTEM_API UEnum* StaticEnum<EEquipSlot>();

#define FOREACH_ENUM_EITEMSUBTYPE(op) \
	op(EItemSubType::EST_Undefined) \
	op(EItemSubType::EST_Weapon) \
	op(EItemSubType::EST_Armor) \
	op(EItemSubType::EST_Ammo) \
	op(EItemSubType::EST_HPItem) \
	op(EItemSubType::EST_EnginePowerModule) 

enum class EItemSubType : uint8;
template<> TANKINVENTORYSYSTEM_API UEnum* StaticEnum<EItemSubType>();

#define FOREACH_ENUM_EITEMARCHTYPE(op) \
	op(EItemArchType::ET_Undefined) \
	op(EItemArchType::ET_Equippable) \
	op(EItemArchType::ET_Consumable) \
	op(EItemArchType::ET_Currency) 

enum class EItemArchType : uint8;
template<> TANKINVENTORYSYSTEM_API UEnum* StaticEnum<EItemArchType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
