// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystem/Public/Quest.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuest() {}
// Cross Module References
	QUESTSYSTEM_API UClass* Z_Construct_UClass_AQuest_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_AQuest();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_QuestSystem();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UObjective_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AQuest::execResetLocation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetLocation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AQuest::execTakeQuest)
	{
		P_GET_OBJECT(AActor,Z_Param_QuestTaker);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TakeQuest(Z_Param_QuestTaker);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AQuest::execOnObjectiveCompleted)
	{
		P_GET_OBJECT(UObjective,Z_Param_InObjective);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnObjectiveCompleted(Z_Param_InObjective);
		P_NATIVE_END;
	}
#if WITH_EDITOR
	DEFINE_FUNCTION(AQuest::execAddLocationObjective)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddLocationObjective();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AQuest::execAddInteractObjective)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddInteractObjective();
		P_NATIVE_END;
	}
#endif //WITH_EDITOR
	void AQuest::StaticRegisterNativesAQuest()
	{
		UClass* Class = AQuest::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
#if WITH_EDITOR
			{ "AddInteractObjective", &AQuest::execAddInteractObjective },
			{ "AddLocationObjective", &AQuest::execAddLocationObjective },
#endif // WITH_EDITOR
			{ "OnObjectiveCompleted", &AQuest::execOnObjectiveCompleted },
			{ "ResetLocation", &AQuest::execResetLocation },
			{ "TakeQuest", &AQuest::execTakeQuest },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
#if WITH_EDITOR
	struct Z_Construct_UFunction_AQuest_AddInteractObjective_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AQuest_AddInteractObjective_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AQuest_AddInteractObjective_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AQuest, nullptr, "AddInteractObjective", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x20020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AQuest_AddInteractObjective_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AQuest_AddInteractObjective_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AQuest_AddInteractObjective()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AQuest_AddInteractObjective_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_AQuest_AddLocationObjective_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AQuest_AddLocationObjective_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AQuest_AddLocationObjective_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AQuest, nullptr, "AddLocationObjective", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x20020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AQuest_AddLocationObjective_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AQuest_AddLocationObjective_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AQuest_AddLocationObjective()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AQuest_AddLocationObjective_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
	struct Z_Construct_UFunction_AQuest_OnObjectiveCompleted_Statics
	{
		struct Quest_eventOnObjectiveCompleted_Parms
		{
			UObjective* InObjective;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InObjective;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AQuest_OnObjectiveCompleted_Statics::NewProp_InObjective = { "InObjective", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Quest_eventOnObjectiveCompleted_Parms, InObjective), Z_Construct_UClass_UObjective_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AQuest_OnObjectiveCompleted_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AQuest_OnObjectiveCompleted_Statics::NewProp_InObjective,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AQuest_OnObjectiveCompleted_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AQuest_OnObjectiveCompleted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AQuest, nullptr, "OnObjectiveCompleted", nullptr, nullptr, sizeof(Quest_eventOnObjectiveCompleted_Parms), Z_Construct_UFunction_AQuest_OnObjectiveCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AQuest_OnObjectiveCompleted_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AQuest_OnObjectiveCompleted_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AQuest_OnObjectiveCompleted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AQuest_OnObjectiveCompleted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AQuest_OnObjectiveCompleted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AQuest_ResetLocation_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AQuest_ResetLocation_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AQuest_ResetLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AQuest, nullptr, "ResetLocation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AQuest_ResetLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AQuest_ResetLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AQuest_ResetLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AQuest_ResetLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AQuest_TakeQuest_Statics
	{
		struct Quest_eventTakeQuest_Parms
		{
			AActor* QuestTaker;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_QuestTaker;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AQuest_TakeQuest_Statics::NewProp_QuestTaker = { "QuestTaker", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Quest_eventTakeQuest_Parms, QuestTaker), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AQuest_TakeQuest_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AQuest_TakeQuest_Statics::NewProp_QuestTaker,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AQuest_TakeQuest_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AQuest_TakeQuest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AQuest, nullptr, "TakeQuest", nullptr, nullptr, sizeof(Quest_eventTakeQuest_Parms), Z_Construct_UFunction_AQuest_TakeQuest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AQuest_TakeQuest_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AQuest_TakeQuest_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AQuest_TakeQuest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AQuest_TakeQuest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AQuest_TakeQuest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AQuest_NoRegister()
	{
		return AQuest::StaticClass();
	}
	struct Z_Construct_UClass_AQuest_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestName_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_QuestName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestDescription_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_QuestDescription;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Objectives_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Objectives_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Objectives;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsTaken_MetaData[];
#endif
		static void NewProp_IsTaken_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsTaken;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsOrderedObjectives_MetaData[];
#endif
		static void NewProp_IsOrderedObjectives_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsOrderedObjectives;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsMainQuest_MetaData[];
#endif
		static void NewProp_IsMainQuest_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsMainQuest;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrerequisiteQuest_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PrerequisiteQuest;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AQuest_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AQuest_Statics::FuncInfo[] = {
#if WITH_EDITOR
		{ &Z_Construct_UFunction_AQuest_AddInteractObjective, "AddInteractObjective" }, // 2954408044
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_AQuest_AddLocationObjective, "AddLocationObjective" }, // 2482702987
#endif //WITH_EDITOR
		{ &Z_Construct_UFunction_AQuest_OnObjectiveCompleted, "OnObjectiveCompleted" }, // 311613859
		{ &Z_Construct_UFunction_AQuest_ResetLocation, "ResetLocation" }, // 1789417486
		{ &Z_Construct_UFunction_AQuest_TakeQuest, "TakeQuest" }, // 164421975
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuest_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Quest.h" },
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuest_Statics::NewProp_QuestName_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UClass_AQuest_Statics::NewProp_QuestName = { "QuestName", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AQuest, QuestName), METADATA_PARAMS(Z_Construct_UClass_AQuest_Statics::NewProp_QuestName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AQuest_Statics::NewProp_QuestName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuest_Statics::NewProp_QuestDescription_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UClass_AQuest_Statics::NewProp_QuestDescription = { "QuestDescription", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AQuest, QuestDescription), METADATA_PARAMS(Z_Construct_UClass_AQuest_Statics::NewProp_QuestDescription_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AQuest_Statics::NewProp_QuestDescription_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AQuest_Statics::NewProp_Objectives_Inner = { "Objectives", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UObjective_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuest_Statics::NewProp_Objectives_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AQuest_Statics::NewProp_Objectives = { "Objectives", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AQuest, Objectives), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AQuest_Statics::NewProp_Objectives_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AQuest_Statics::NewProp_Objectives_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuest_Statics::NewProp_IsTaken_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	void Z_Construct_UClass_AQuest_Statics::NewProp_IsTaken_SetBit(void* Obj)
	{
		((AQuest*)Obj)->IsTaken = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AQuest_Statics::NewProp_IsTaken = { "IsTaken", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AQuest), &Z_Construct_UClass_AQuest_Statics::NewProp_IsTaken_SetBit, METADATA_PARAMS(Z_Construct_UClass_AQuest_Statics::NewProp_IsTaken_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AQuest_Statics::NewProp_IsTaken_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuest_Statics::NewProp_IsOrderedObjectives_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	void Z_Construct_UClass_AQuest_Statics::NewProp_IsOrderedObjectives_SetBit(void* Obj)
	{
		((AQuest*)Obj)->IsOrderedObjectives = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AQuest_Statics::NewProp_IsOrderedObjectives = { "IsOrderedObjectives", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AQuest), &Z_Construct_UClass_AQuest_Statics::NewProp_IsOrderedObjectives_SetBit, METADATA_PARAMS(Z_Construct_UClass_AQuest_Statics::NewProp_IsOrderedObjectives_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AQuest_Statics::NewProp_IsOrderedObjectives_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuest_Statics::NewProp_IsMainQuest_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	void Z_Construct_UClass_AQuest_Statics::NewProp_IsMainQuest_SetBit(void* Obj)
	{
		((AQuest*)Obj)->IsMainQuest = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AQuest_Statics::NewProp_IsMainQuest = { "IsMainQuest", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AQuest), &Z_Construct_UClass_AQuest_Statics::NewProp_IsMainQuest_SetBit, METADATA_PARAMS(Z_Construct_UClass_AQuest_Statics::NewProp_IsMainQuest_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AQuest_Statics::NewProp_IsMainQuest_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AQuest_Statics::NewProp_PrerequisiteQuest_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AQuest_Statics::NewProp_PrerequisiteQuest = { "PrerequisiteQuest", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AQuest, PrerequisiteQuest), Z_Construct_UClass_AQuest_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AQuest_Statics::NewProp_PrerequisiteQuest_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AQuest_Statics::NewProp_PrerequisiteQuest_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AQuest_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuest_Statics::NewProp_QuestName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuest_Statics::NewProp_QuestDescription,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuest_Statics::NewProp_Objectives_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuest_Statics::NewProp_Objectives,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuest_Statics::NewProp_IsTaken,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuest_Statics::NewProp_IsOrderedObjectives,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuest_Statics::NewProp_IsMainQuest,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuest_Statics::NewProp_PrerequisiteQuest,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AQuest_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AQuest>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AQuest_Statics::ClassParams = {
		&AQuest::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AQuest_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AQuest_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AQuest_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AQuest_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AQuest()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AQuest_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AQuest, 3158962080);
	template<> QUESTSYSTEM_API UClass* StaticClass<AQuest>()
	{
		return AQuest::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AQuest(Z_Construct_UClass_AQuest, &AQuest::StaticClass, TEXT("/Script/QuestSystem"), TEXT("AQuest"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AQuest);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
