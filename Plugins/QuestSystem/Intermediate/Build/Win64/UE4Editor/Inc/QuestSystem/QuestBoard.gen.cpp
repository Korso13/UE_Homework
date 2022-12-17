// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystem/Public/QuestBoard.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestBoard() {}
// Cross Module References
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestBoard_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestBoard();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_QuestSystem();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_AQuest_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestListEntry_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestDescriptionWidget_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestManager_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UQuestBoard::execPickQuestForViewer)
	{
		P_GET_OBJECT(AQuest,Z_Param_InQuest);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PickQuestForViewer(Z_Param_InQuest);
		P_NATIVE_END;
	}
	void UQuestBoard::StaticRegisterNativesUQuestBoard()
	{
		UClass* Class = UQuestBoard::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PickQuestForViewer", &UQuestBoard::execPickQuestForViewer },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuestBoard_PickQuestForViewer_Statics
	{
		struct QuestBoard_eventPickQuestForViewer_Parms
		{
			AQuest* InQuest;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InQuest;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UQuestBoard_PickQuestForViewer_Statics::NewProp_InQuest = { "InQuest", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(QuestBoard_eventPickQuestForViewer_Parms, InQuest), Z_Construct_UClass_AQuest_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestBoard_PickQuestForViewer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestBoard_PickQuestForViewer_Statics::NewProp_InQuest,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestBoard_PickQuestForViewer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/QuestBoard.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestBoard_PickQuestForViewer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestBoard, nullptr, "PickQuestForViewer", nullptr, nullptr, sizeof(QuestBoard_eventPickQuestForViewer_Parms), Z_Construct_UFunction_UQuestBoard_PickQuestForViewer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestBoard_PickQuestForViewer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestBoard_PickQuestForViewer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestBoard_PickQuestForViewer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestBoard_PickQuestForViewer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestBoard_PickQuestForViewer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UQuestBoard_NoRegister()
	{
		return UQuestBoard::StaticClass();
	}
	struct Z_Construct_UClass_UQuestBoard_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestListEntryClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_QuestListEntryClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MainQuestsList_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MainQuestsList;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SideQuestsList_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SideQuestsList;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestDescription_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_QuestDescription;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestManager_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_QuestManager;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestBoard_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuestBoard_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestBoard_PickQuestForViewer, "PickQuestForViewer" }, // 1886673463
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestBoard_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "QuestBoard.h" },
		{ "ModuleRelativePath", "Public/QuestBoard.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestListEntryClass_MetaData[] = {
		{ "Category", "QuestBoard" },
		{ "ModuleRelativePath", "Public/QuestBoard.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestListEntryClass = { "QuestListEntryClass", nullptr, (EPropertyFlags)0x0024080000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestBoard, QuestListEntryClass), Z_Construct_UClass_UQuestListEntry_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestListEntryClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestListEntryClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestBoard_Statics::NewProp_MainQuestsList_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestBoard" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestBoard.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestBoard_Statics::NewProp_MainQuestsList = { "MainQuestsList", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestBoard, MainQuestsList), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestBoard_Statics::NewProp_MainQuestsList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestBoard_Statics::NewProp_MainQuestsList_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestBoard_Statics::NewProp_SideQuestsList_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestBoard" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestBoard.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestBoard_Statics::NewProp_SideQuestsList = { "SideQuestsList", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestBoard, SideQuestsList), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestBoard_Statics::NewProp_SideQuestsList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestBoard_Statics::NewProp_SideQuestsList_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestDescription_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestBoard" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestBoard.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestDescription = { "QuestDescription", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestBoard, QuestDescription), Z_Construct_UClass_UQuestDescriptionWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestDescription_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestDescription_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestManager_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestBoard.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestManager = { "QuestManager", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestBoard, QuestManager), Z_Construct_UClass_UQuestManager_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestManager_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestBoard_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestListEntryClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestBoard_Statics::NewProp_MainQuestsList,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestBoard_Statics::NewProp_SideQuestsList,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestDescription,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestBoard_Statics::NewProp_QuestManager,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestBoard_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestBoard>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UQuestBoard_Statics::ClassParams = {
		&UQuestBoard::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuestBoard_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestBoard_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UQuestBoard_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestBoard_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuestBoard()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UQuestBoard_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UQuestBoard, 887814325);
	template<> QUESTSYSTEM_API UClass* StaticClass<UQuestBoard>()
	{
		return UQuestBoard::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UQuestBoard(Z_Construct_UClass_UQuestBoard, &UQuestBoard::StaticClass, TEXT("/Script/QuestSystem"), TEXT("UQuestBoard"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestBoard);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
