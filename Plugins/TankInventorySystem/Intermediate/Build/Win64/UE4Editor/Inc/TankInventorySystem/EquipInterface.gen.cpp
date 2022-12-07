// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TankInventorySystem/Public/EquipInterface.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEquipInterface() {}
// Cross Module References
	TANKINVENTORYSYSTEM_API UClass* Z_Construct_UClass_UEquipInterface_NoRegister();
	TANKINVENTORYSYSTEM_API UClass* Z_Construct_UClass_UEquipInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_TankInventorySystem();
// End Cross Module References
	void UEquipInterface::StaticRegisterNativesUEquipInterface()
	{
	}
	UClass* Z_Construct_UClass_UEquipInterface_NoRegister()
	{
		return UEquipInterface::StaticClass();
	}
	struct Z_Construct_UClass_UEquipInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEquipInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_TankInventorySystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/EquipInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEquipInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IEquipInterface>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UEquipInterface_Statics::ClassParams = {
		&UEquipInterface::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UEquipInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEquipInterface()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UEquipInterface_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UEquipInterface, 494543907);
	template<> TANKINVENTORYSYSTEM_API UClass* StaticClass<UEquipInterface>()
	{
		return UEquipInterface::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UEquipInterface(Z_Construct_UClass_UEquipInterface, &UEquipInterface::StaticClass, TEXT("/Script/TankInventorySystem"), TEXT("UEquipInterface"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEquipInterface);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
