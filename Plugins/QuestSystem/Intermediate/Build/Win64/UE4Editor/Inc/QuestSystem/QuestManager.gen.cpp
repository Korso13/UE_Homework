// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystem/Public/QuestManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestManager() {}
// Cross Module References
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestManager_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestManager();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_QuestSystem();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UCurrentObjectivesWidget_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestBoard_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_AQuest_NoRegister();
// End Cross Module References
	void UQuestManager::StaticRegisterNativesUQuestManager()
	{
	}
	UClass* Z_Construct_UClass_UQuestManager_NoRegister()
	{
		return UQuestManager::StaticClass();
	}
	struct Z_Construct_UClass_UQuestManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActiveQuestWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActiveQuestWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestBoardWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_QuestBoardWidgetClass;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TakenQuests_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TakenQuests_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TakenQuests;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActiveQuest_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActiveQuest;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestBoardWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_QuestBoardWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentObjectivesWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_CurrentObjectivesWidgetClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestManager_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "QuestManager.h" },
		{ "ModuleRelativePath", "Public/QuestManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestManager_Statics::NewProp_ActiveQuestWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestManager_Statics::NewProp_ActiveQuestWidget = { "ActiveQuestWidget", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestManager, ActiveQuestWidget), Z_Construct_UClass_UCurrentObjectivesWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestManager_Statics::NewProp_ActiveQuestWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestManager_Statics::NewProp_ActiveQuestWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestManager_Statics::NewProp_QuestBoardWidgetClass_MetaData[] = {
		{ "Category", "QuestManager" },
		{ "ModuleRelativePath", "Public/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UQuestManager_Statics::NewProp_QuestBoardWidgetClass = { "QuestBoardWidgetClass", nullptr, (EPropertyFlags)0x0024080000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestManager, QuestBoardWidgetClass), Z_Construct_UClass_UQuestBoard_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UQuestManager_Statics::NewProp_QuestBoardWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestManager_Statics::NewProp_QuestBoardWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuests_Inner = { "TakenQuests", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AQuest_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuests_MetaData[] = {
		{ "ModuleRelativePath", "Public/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuests = { "TakenQuests", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestManager, TakenQuests), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuests_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuests_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestManager_Statics::NewProp_ActiveQuest_MetaData[] = {
		{ "ModuleRelativePath", "Public/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestManager_Statics::NewProp_ActiveQuest = { "ActiveQuest", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestManager, ActiveQuest), Z_Construct_UClass_AQuest_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestManager_Statics::NewProp_ActiveQuest_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestManager_Statics::NewProp_ActiveQuest_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestManager_Statics::NewProp_QuestBoardWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestManager_Statics::NewProp_QuestBoardWidget = { "QuestBoardWidget", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestManager, QuestBoardWidget), Z_Construct_UClass_UQuestBoard_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestManager_Statics::NewProp_QuestBoardWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestManager_Statics::NewProp_QuestBoardWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestManager_Statics::NewProp_CurrentObjectivesWidgetClass_MetaData[] = {
		{ "Category", "QuestManager" },
		{ "ModuleRelativePath", "Public/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UQuestManager_Statics::NewProp_CurrentObjectivesWidgetClass = { "CurrentObjectivesWidgetClass", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestManager, CurrentObjectivesWidgetClass), Z_Construct_UClass_UCurrentObjectivesWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UQuestManager_Statics::NewProp_CurrentObjectivesWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestManager_Statics::NewProp_CurrentObjectivesWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestManager_Statics::NewProp_ActiveQuestWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestManager_Statics::NewProp_QuestBoardWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuests_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuests,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestManager_Statics::NewProp_ActiveQuest,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestManager_Statics::NewProp_QuestBoardWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestManager_Statics::NewProp_CurrentObjectivesWidgetClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UQuestManager_Statics::ClassParams = {
		&UQuestManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UQuestManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestManager_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UQuestManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuestManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UQuestManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UQuestManager, 1229835474);
	template<> QUESTSYSTEM_API UClass* StaticClass<UQuestManager>()
	{
		return UQuestManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UQuestManager(Z_Construct_UClass_UQuestManager, &UQuestManager::StaticClass, TEXT("/Script/QuestSystem"), TEXT("UQuestManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
