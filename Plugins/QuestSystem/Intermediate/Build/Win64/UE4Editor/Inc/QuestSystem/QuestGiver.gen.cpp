// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystem/Public/QuestGiver.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestGiver() {}
// Cross Module References
	QUESTSYSTEM_API UClass* Z_Construct_UClass_AQuestGiver_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_AQuestGiver();
	INTERACTIONSUBSYSTEM_API UClass* Z_Construct_UClass_ABaseInteractionActor();
	UPackage* Z_Construct_UPackage__Script_QuestSystem();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestDialogueWidget_NoRegister();
// End Cross Module References
	void AQuestGiver::StaticRegisterNativesAQuestGiver()
	{
	}
	UClass* Z_Construct_UClass_AQuestGiver_NoRegister()
	{
		return AQuestGiver::StaticClass();
	}
	struct Z_Construct_UClass_AQuestGiver_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SceneComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SceneComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestAvailableSign_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_QuestAvailableSign;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestSignWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_QuestSignWidgetClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestDialogueWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_QuestDialogueWidgetClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AQuestGiver_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABaseInteractionActor,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuestGiver_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "QuestGiver.h" },
		{ "ModuleRelativePath", "Public/QuestGiver.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuestGiver_Statics::NewProp_SceneComponent_MetaData[] = {
		{ "Category", "QuestGiver" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestGiver.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AQuestGiver_Statics::NewProp_SceneComponent = { "SceneComponent", nullptr, (EPropertyFlags)0x002008000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AQuestGiver, SceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AQuestGiver_Statics::NewProp_SceneComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AQuestGiver_Statics::NewProp_SceneComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestAvailableSign_MetaData[] = {
		{ "Category", "QuestGiver" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestGiver.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestAvailableSign = { "QuestAvailableSign", nullptr, (EPropertyFlags)0x002008000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AQuestGiver, QuestAvailableSign), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestAvailableSign_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestAvailableSign_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestSignWidgetClass_MetaData[] = {
		{ "Category", "QuestGiver" },
		{ "DeprecatedProperty", "" },
		{ "ModuleRelativePath", "Public/QuestGiver.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestSignWidgetClass = { "QuestSignWidgetClass", nullptr, (EPropertyFlags)0x0024080000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AQuestGiver, QuestSignWidgetClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestSignWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestSignWidgetClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestDialogueWidgetClass_MetaData[] = {
		{ "Category", "QuestGiver" },
		{ "ModuleRelativePath", "Public/QuestGiver.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestDialogueWidgetClass = { "QuestDialogueWidgetClass", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AQuestGiver, QuestDialogueWidgetClass), Z_Construct_UClass_UQuestDialogueWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestDialogueWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestDialogueWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AQuestGiver_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuestGiver_Statics::NewProp_SceneComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestAvailableSign,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestSignWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuestGiver_Statics::NewProp_QuestDialogueWidgetClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AQuestGiver_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AQuestGiver>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AQuestGiver_Statics::ClassParams = {
		&AQuestGiver::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AQuestGiver_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AQuestGiver_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AQuestGiver_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AQuestGiver_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AQuestGiver()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AQuestGiver_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AQuestGiver, 173321085);
	template<> QUESTSYSTEM_API UClass* StaticClass<AQuestGiver>()
	{
		return AQuestGiver::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AQuestGiver(Z_Construct_UClass_AQuestGiver, &AQuestGiver::StaticClass, TEXT("/Script/QuestSystem"), TEXT("AQuestGiver"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AQuestGiver);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
