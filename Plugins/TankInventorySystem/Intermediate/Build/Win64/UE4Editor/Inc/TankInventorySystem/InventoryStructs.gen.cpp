// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TankInventorySystem/Public/InventoryStructs.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryStructs() {}
// Cross Module References
	TANKINVENTORYSYSTEM_API UEnum* Z_Construct_UEnum_TankInventorySystem_EInventoryClass();
	UPackage* Z_Construct_UPackage__Script_TankInventorySystem();
	TANKINVENTORYSYSTEM_API UEnum* Z_Construct_UEnum_TankInventorySystem_EEquipSlot();
	TANKINVENTORYSYSTEM_API UEnum* Z_Construct_UEnum_TankInventorySystem_EItemSubType();
	TANKINVENTORYSYSTEM_API UEnum* Z_Construct_UEnum_TankInventorySystem_EItemArchType();
	TANKINVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlotInfo();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	TANKINVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryItemInfo();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
// End Cross Module References
	static UEnum* EInventoryClass_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TankInventorySystem_EInventoryClass, Z_Construct_UPackage__Script_TankInventorySystem(), TEXT("EInventoryClass"));
		}
		return Singleton;
	}
	template<> TANKINVENTORYSYSTEM_API UEnum* StaticEnum<EInventoryClass>()
	{
		return EInventoryClass_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EInventoryClass(EInventoryClass_StaticEnum, TEXT("/Script/TankInventorySystem"), TEXT("EInventoryClass"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TankInventorySystem_EInventoryClass_Hash() { return 765408582U; }
	UEnum* Z_Construct_UEnum_TankInventorySystem_EInventoryClass()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TankInventorySystem();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EInventoryClass"), 0, Get_Z_Construct_UEnum_TankInventorySystem_EInventoryClass_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EInventoryClass::IC_CharInventory", (int64)EInventoryClass::IC_CharInventory },
				{ "EInventoryClass::IC_EquipInventory", (int64)EInventoryClass::IC_EquipInventory },
				{ "EInventoryClass::IC_Chest", (int64)EInventoryClass::IC_Chest },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IC_CharInventory.Name", "EInventoryClass::IC_CharInventory" },
				{ "IC_Chest.Name", "EInventoryClass::IC_Chest" },
				{ "IC_EquipInventory.Name", "EInventoryClass::IC_EquipInventory" },
				{ "ModuleRelativePath", "Public/InventoryStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TankInventorySystem,
				nullptr,
				"EInventoryClass",
				"EInventoryClass",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EEquipSlot_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TankInventorySystem_EEquipSlot, Z_Construct_UPackage__Script_TankInventorySystem(), TEXT("EEquipSlot"));
		}
		return Singleton;
	}
	template<> TANKINVENTORYSYSTEM_API UEnum* StaticEnum<EEquipSlot>()
	{
		return EEquipSlot_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EEquipSlot(EEquipSlot_StaticEnum, TEXT("/Script/TankInventorySystem"), TEXT("EEquipSlot"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TankInventorySystem_EEquipSlot_Hash() { return 488590633U; }
	UEnum* Z_Construct_UEnum_TankInventorySystem_EEquipSlot()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TankInventorySystem();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EEquipSlot"), 0, Get_Z_Construct_UEnum_TankInventorySystem_EEquipSlot_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EEquipSlot::EQ_NONE", (int64)EEquipSlot::EQ_NONE },
				{ "EEquipSlot::EQ_PrimaryCannon", (int64)EEquipSlot::EQ_PrimaryCannon },
				{ "EEquipSlot::EQ_SecondaryCannon", (int64)EEquipSlot::EQ_SecondaryCannon },
				{ "EEquipSlot::EQ_Armor", (int64)EEquipSlot::EQ_Armor },
				{ "EEquipSlot::EQ_PowerModule", (int64)EEquipSlot::EQ_PowerModule },
				{ "EEquipSlot::EQ_Consumable", (int64)EEquipSlot::EQ_Consumable },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "EQ_Armor.Name", "EEquipSlot::EQ_Armor" },
				{ "EQ_Consumable.Name", "EEquipSlot::EQ_Consumable" },
				{ "EQ_NONE.Name", "EEquipSlot::EQ_NONE" },
				{ "EQ_PowerModule.Name", "EEquipSlot::EQ_PowerModule" },
				{ "EQ_PrimaryCannon.Name", "EEquipSlot::EQ_PrimaryCannon" },
				{ "EQ_SecondaryCannon.Name", "EEquipSlot::EQ_SecondaryCannon" },
				{ "ModuleRelativePath", "Public/InventoryStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TankInventorySystem,
				nullptr,
				"EEquipSlot",
				"EEquipSlot",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EItemSubType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TankInventorySystem_EItemSubType, Z_Construct_UPackage__Script_TankInventorySystem(), TEXT("EItemSubType"));
		}
		return Singleton;
	}
	template<> TANKINVENTORYSYSTEM_API UEnum* StaticEnum<EItemSubType>()
	{
		return EItemSubType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EItemSubType(EItemSubType_StaticEnum, TEXT("/Script/TankInventorySystem"), TEXT("EItemSubType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TankInventorySystem_EItemSubType_Hash() { return 3671312661U; }
	UEnum* Z_Construct_UEnum_TankInventorySystem_EItemSubType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TankInventorySystem();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EItemSubType"), 0, Get_Z_Construct_UEnum_TankInventorySystem_EItemSubType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EItemSubType::EST_Undefined", (int64)EItemSubType::EST_Undefined },
				{ "EItemSubType::EST_Weapon", (int64)EItemSubType::EST_Weapon },
				{ "EItemSubType::EST_Armor", (int64)EItemSubType::EST_Armor },
				{ "EItemSubType::EST_Ammo", (int64)EItemSubType::EST_Ammo },
				{ "EItemSubType::EST_HPItem", (int64)EItemSubType::EST_HPItem },
				{ "EItemSubType::EST_EnginePowerModule", (int64)EItemSubType::EST_EnginePowerModule },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "EST_Ammo.Name", "EItemSubType::EST_Ammo" },
				{ "EST_Armor.Name", "EItemSubType::EST_Armor" },
				{ "EST_EnginePowerModule.Name", "EItemSubType::EST_EnginePowerModule" },
				{ "EST_HPItem.Name", "EItemSubType::EST_HPItem" },
				{ "EST_Undefined.Name", "EItemSubType::EST_Undefined" },
				{ "EST_Weapon.Name", "EItemSubType::EST_Weapon" },
				{ "ModuleRelativePath", "Public/InventoryStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TankInventorySystem,
				nullptr,
				"EItemSubType",
				"EItemSubType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EItemArchType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TankInventorySystem_EItemArchType, Z_Construct_UPackage__Script_TankInventorySystem(), TEXT("EItemArchType"));
		}
		return Singleton;
	}
	template<> TANKINVENTORYSYSTEM_API UEnum* StaticEnum<EItemArchType>()
	{
		return EItemArchType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EItemArchType(EItemArchType_StaticEnum, TEXT("/Script/TankInventorySystem"), TEXT("EItemArchType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TankInventorySystem_EItemArchType_Hash() { return 2658317865U; }
	UEnum* Z_Construct_UEnum_TankInventorySystem_EItemArchType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TankInventorySystem();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EItemArchType"), 0, Get_Z_Construct_UEnum_TankInventorySystem_EItemArchType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EItemArchType::ET_Undefined", (int64)EItemArchType::ET_Undefined },
				{ "EItemArchType::ET_Equippable", (int64)EItemArchType::ET_Equippable },
				{ "EItemArchType::ET_Consumable", (int64)EItemArchType::ET_Consumable },
				{ "EItemArchType::ET_Currency", (int64)EItemArchType::ET_Currency },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ET_Consumable.Name", "EItemArchType::ET_Consumable" },
				{ "ET_Currency.Name", "EItemArchType::ET_Currency" },
				{ "ET_Equippable.Name", "EItemArchType::ET_Equippable" },
				{ "ET_Undefined.Name", "EItemArchType::ET_Undefined" },
				{ "ModuleRelativePath", "Public/InventoryStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TankInventorySystem,
				nullptr,
				"EItemArchType",
				"EItemArchType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}

static_assert(std::is_polymorphic<FInventorySlotInfo>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FInventorySlotInfo cannot be polymorphic unless super FTableRowBase is polymorphic");

class UScriptStruct* FInventorySlotInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern TANKINVENTORYSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FInventorySlotInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventorySlotInfo, Z_Construct_UPackage__Script_TankInventorySystem(), TEXT("InventorySlotInfo"), sizeof(FInventorySlotInfo), Get_Z_Construct_UScriptStruct_FInventorySlotInfo_Hash());
	}
	return Singleton;
}
template<> TANKINVENTORYSYSTEM_API UScriptStruct* StaticStruct<FInventorySlotInfo>()
{
	return FInventorySlotInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FInventorySlotInfo(FInventorySlotInfo::StaticStruct, TEXT("/Script/TankInventorySystem"), TEXT("InventorySlotInfo"), false, nullptr, nullptr);
static struct FScriptStruct_TankInventorySystem_StaticRegisterNativesFInventorySlotInfo
{
	FScriptStruct_TankInventorySystem_StaticRegisterNativesFInventorySlotInfo()
	{
		UScriptStruct::DeferCppStructOps<FInventorySlotInfo>(FName(TEXT("InventorySlotInfo")));
	}
} ScriptStruct_TankInventorySystem_StaticRegisterNativesFInventorySlotInfo;
	struct Z_Construct_UScriptStruct_FInventorySlotInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_ItemId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ItemCount;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventorySlotInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::NewProp_ItemId_MetaData[] = {
		{ "Category", "ID" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventorySlotInfo, ItemId), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::NewProp_ItemId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::NewProp_ItemId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::NewProp_ItemCount_MetaData[] = {
		{ "Category", "Count" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::NewProp_ItemCount = { "ItemCount", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventorySlotInfo, ItemCount), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::NewProp_ItemCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::NewProp_ItemCount_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::NewProp_ItemId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::NewProp_ItemCount,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_TankInventorySystem,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"InventorySlotInfo",
		sizeof(FInventorySlotInfo),
		alignof(FInventorySlotInfo),
		Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FInventorySlotInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FInventorySlotInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_TankInventorySystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("InventorySlotInfo"), sizeof(FInventorySlotInfo), Get_Z_Construct_UScriptStruct_FInventorySlotInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FInventorySlotInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FInventorySlotInfo_Hash() { return 1604610661U; }

static_assert(std::is_polymorphic<FInventoryItemInfo>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FInventoryItemInfo cannot be polymorphic unless super FTableRowBase is polymorphic");

class UScriptStruct* FInventoryItemInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern TANKINVENTORYSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FInventoryItemInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventoryItemInfo, Z_Construct_UPackage__Script_TankInventorySystem(), TEXT("InventoryItemInfo"), sizeof(FInventoryItemInfo), Get_Z_Construct_UScriptStruct_FInventoryItemInfo_Hash());
	}
	return Singleton;
}
template<> TANKINVENTORYSYSTEM_API UScriptStruct* StaticStruct<FInventoryItemInfo>()
{
	return FInventoryItemInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FInventoryItemInfo(FInventoryItemInfo::StaticStruct, TEXT("/Script/TankInventorySystem"), TEXT("InventoryItemInfo"), false, nullptr, nullptr);
static struct FScriptStruct_TankInventorySystem_StaticRegisterNativesFInventoryItemInfo
{
	FScriptStruct_TankInventorySystem_StaticRegisterNativesFInventoryItemInfo()
	{
		UScriptStruct::DeferCppStructOps<FInventoryItemInfo>(FName(TEXT("InventoryItemInfo")));
	}
} ScriptStruct_TankInventorySystem_StaticRegisterNativesFInventoryItemInfo;
	struct Z_Construct_UScriptStruct_FInventoryItemInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_ItemId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxStack_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxStack;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ItemClass;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ItemArchType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemArchType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ItemArchType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ItemCategory_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemCategory_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ItemCategory;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_EquipSlot_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EquipSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_EquipSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[];
#endif
		static const UE4CodeGen_Private::FSoftObjectPropertyParams NewProp_Icon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FSoftObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Damage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Armor_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Armor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StatsBoost_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StatsBoost;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConsumableRestoreValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ConsumableRestoreValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventoryItemInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemId_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, ItemId), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, Name), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Name_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_MaxStack_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_MaxStack = { "MaxStack", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, MaxStack), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_MaxStack_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_MaxStack_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemClass_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemClass = { "ItemClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, ItemClass), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemClass_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemArchType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemArchType_MetaData[] = {
		{ "Category", "Types" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemArchType = { "ItemArchType", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, ItemArchType), Z_Construct_UEnum_TankInventorySystem_EItemArchType, METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemArchType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemArchType_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemCategory_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemCategory_MetaData[] = {
		{ "Category", "Types" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemCategory = { "ItemCategory", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, ItemCategory), Z_Construct_UEnum_TankInventorySystem_EItemSubType, METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemCategory_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemCategory_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_EquipSlot_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_EquipSlot_MetaData[] = {
		{ "Category", "Types" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_EquipSlot = { "EquipSlot", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, EquipSlot), Z_Construct_UEnum_TankInventorySystem_EEquipSlot, METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_EquipSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_EquipSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Icon_MetaData[] = {
		{ "Category", "Visual" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Icon_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Icon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "Visual" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, Mesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Mesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Mesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Damage_MetaData[] = {
		{ "Category", "Item stats" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, Damage), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Damage_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Damage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Armor_MetaData[] = {
		{ "Category", "Item stats" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Armor = { "Armor", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, Armor), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Armor_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Armor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_StatsBoost_MetaData[] = {
		{ "Category", "Item stats" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_StatsBoost = { "StatsBoost", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, StatsBoost), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_StatsBoost_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_StatsBoost_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ConsumableRestoreValue_MetaData[] = {
		{ "Category", "Item stats" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ConsumableRestoreValue = { "ConsumableRestoreValue", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventoryItemInfo, ConsumableRestoreValue), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ConsumableRestoreValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ConsumableRestoreValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_MaxStack,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemArchType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemArchType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemCategory_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ItemCategory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_EquipSlot_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_EquipSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Icon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Mesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Damage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_Armor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_StatsBoost,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::NewProp_ConsumableRestoreValue,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_TankInventorySystem,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"InventoryItemInfo",
		sizeof(FInventoryItemInfo),
		alignof(FInventoryItemInfo),
		Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FInventoryItemInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FInventoryItemInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_TankInventorySystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("InventoryItemInfo"), sizeof(FInventoryItemInfo), Get_Z_Construct_UScriptStruct_FInventoryItemInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FInventoryItemInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FInventoryItemInfo_Hash() { return 1361489655U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
