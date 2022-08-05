// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Test3P_Proj/Test3P_ProjGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTest3P_ProjGameMode() {}
// Cross Module References
	TEST3P_PROJ_API UClass* Z_Construct_UClass_ATest3P_ProjGameMode_NoRegister();
	TEST3P_PROJ_API UClass* Z_Construct_UClass_ATest3P_ProjGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Test3P_Proj();
// End Cross Module References
	void ATest3P_ProjGameMode::StaticRegisterNativesATest3P_ProjGameMode()
	{
	}
	UClass* Z_Construct_UClass_ATest3P_ProjGameMode_NoRegister()
	{
		return ATest3P_ProjGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATest3P_ProjGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATest3P_ProjGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Test3P_Proj,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATest3P_ProjGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Test3P_ProjGameMode.h" },
		{ "ModuleRelativePath", "Test3P_ProjGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATest3P_ProjGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATest3P_ProjGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATest3P_ProjGameMode_Statics::ClassParams = {
		&ATest3P_ProjGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATest3P_ProjGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATest3P_ProjGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATest3P_ProjGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATest3P_ProjGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATest3P_ProjGameMode, 3916682376);
	template<> TEST3P_PROJ_API UClass* StaticClass<ATest3P_ProjGameMode>()
	{
		return ATest3P_ProjGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATest3P_ProjGameMode(Z_Construct_UClass_ATest3P_ProjGameMode, &ATest3P_ProjGameMode::StaticClass, TEXT("/Script/Test3P_Proj"), TEXT("ATest3P_ProjGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATest3P_ProjGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
