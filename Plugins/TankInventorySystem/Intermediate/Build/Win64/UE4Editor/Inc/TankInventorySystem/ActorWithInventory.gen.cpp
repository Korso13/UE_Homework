// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TankInventorySystem/Public/ActorWithInventory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActorWithInventory() {}
// Cross Module References
	TANKINVENTORYSYSTEM_API UClass* Z_Construct_UClass_UActorWithInventory_NoRegister();
	TANKINVENTORYSYSTEM_API UClass* Z_Construct_UClass_UActorWithInventory();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_TankInventorySystem();
// End Cross Module References
	void UActorWithInventory::StaticRegisterNativesUActorWithInventory()
	{
	}
	UClass* Z_Construct_UClass_UActorWithInventory_NoRegister()
	{
		return UActorWithInventory::StaticClass();
	}
	struct Z_Construct_UClass_UActorWithInventory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UActorWithInventory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_TankInventorySystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorWithInventory_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ActorWithInventory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UActorWithInventory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IActorWithInventory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UActorWithInventory_Statics::ClassParams = {
		&UActorWithInventory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UActorWithInventory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UActorWithInventory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UActorWithInventory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UActorWithInventory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UActorWithInventory, 1054104760);
	template<> TANKINVENTORYSYSTEM_API UClass* StaticClass<UActorWithInventory>()
	{
		return UActorWithInventory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UActorWithInventory(Z_Construct_UClass_UActorWithInventory, &UActorWithInventory::StaticClass, TEXT("/Script/TankInventorySystem"), TEXT("UActorWithInventory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UActorWithInventory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
