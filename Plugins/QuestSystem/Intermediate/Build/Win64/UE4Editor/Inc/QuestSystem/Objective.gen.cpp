// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystem/Public/Objective.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjective() {}
// Cross Module References
	QUESTSYSTEM_API UEnum* Z_Construct_UEnum_QuestSystem_EObjectiveType();
	UPackage* Z_Construct_UPackage__Script_QuestSystem();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UObjective_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UObjective();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UInteractionObjective_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UInteractionObjective();
	INTERACTIONSUBSYSTEM_API UClass* Z_Construct_UClass_ABaseInteractionActor_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_ULocationObjective_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_ULocationObjective();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	static UEnum* EObjectiveType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_QuestSystem_EObjectiveType, Z_Construct_UPackage__Script_QuestSystem(), TEXT("EObjectiveType"));
		}
		return Singleton;
	}
	template<> QUESTSYSTEM_API UEnum* StaticEnum<EObjectiveType>()
	{
		return EObjectiveType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EObjectiveType(EObjectiveType_StaticEnum, TEXT("/Script/QuestSystem"), TEXT("EObjectiveType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_QuestSystem_EObjectiveType_Hash() { return 379540528U; }
	UEnum* Z_Construct_UEnum_QuestSystem_EObjectiveType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_QuestSystem();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EObjectiveType"), 0, Get_Z_Construct_UEnum_QuestSystem_EObjectiveType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EObjectiveType::OT_Location", (int64)EObjectiveType::OT_Location },
				{ "EObjectiveType::OT_Interaction", (int64)EObjectiveType::OT_Interaction },
				{ "EObjectiveType::OT_Extended", (int64)EObjectiveType::OT_Extended },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Objective.h" },
				{ "OT_Extended.Name", "EObjectiveType::OT_Extended" },
				{ "OT_Interaction.Name", "EObjectiveType::OT_Interaction" },
				{ "OT_Location.Name", "EObjectiveType::OT_Location" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_QuestSystem,
				nullptr,
				"EObjectiveType",
				"EObjectiveType",
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
	void UObjective::StaticRegisterNativesUObjective()
	{
	}
	UClass* Z_Construct_UClass_UObjective_NoRegister()
	{
		return UObjective::StaticClass();
	}
	struct Z_Construct_UClass_UObjective_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ObjectiveType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectiveType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ObjectiveType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectiveDescription_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_ObjectiveDescription;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCanBeCompleted_MetaData[];
#endif
		static void NewProp_bCanBeCompleted_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCanBeCompleted;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsCompleted_MetaData[];
#endif
		static void NewProp_bIsCompleted_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsCompleted;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjective_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjective_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Objective.h" },
		{ "ModuleRelativePath", "Public/Objective.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveType_MetaData[] = {
		{ "Category", "Objective" },
		{ "ModuleRelativePath", "Public/Objective.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveType = { "ObjectiveType", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjective, ObjectiveType), Z_Construct_UEnum_QuestSystem_EObjectiveType, METADATA_PARAMS(Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveDescription_MetaData[] = {
		{ "Category", "Objective" },
		{ "ModuleRelativePath", "Public/Objective.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveDescription = { "ObjectiveDescription", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjective, ObjectiveDescription), METADATA_PARAMS(Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveDescription_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveDescription_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjective_Statics::NewProp_bCanBeCompleted_MetaData[] = {
		{ "Category", "Objective" },
		{ "ModuleRelativePath", "Public/Objective.h" },
	};
#endif
	void Z_Construct_UClass_UObjective_Statics::NewProp_bCanBeCompleted_SetBit(void* Obj)
	{
		((UObjective*)Obj)->bCanBeCompleted = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UObjective_Statics::NewProp_bCanBeCompleted = { "bCanBeCompleted", nullptr, (EPropertyFlags)0x0020080000020001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UObjective), &Z_Construct_UClass_UObjective_Statics::NewProp_bCanBeCompleted_SetBit, METADATA_PARAMS(Z_Construct_UClass_UObjective_Statics::NewProp_bCanBeCompleted_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjective_Statics::NewProp_bCanBeCompleted_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjective_Statics::NewProp_bIsCompleted_MetaData[] = {
		{ "Category", "Objective" },
		{ "ModuleRelativePath", "Public/Objective.h" },
	};
#endif
	void Z_Construct_UClass_UObjective_Statics::NewProp_bIsCompleted_SetBit(void* Obj)
	{
		((UObjective*)Obj)->bIsCompleted = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UObjective_Statics::NewProp_bIsCompleted = { "bIsCompleted", nullptr, (EPropertyFlags)0x0020080000020001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UObjective), &Z_Construct_UClass_UObjective_Statics::NewProp_bIsCompleted_SetBit, METADATA_PARAMS(Z_Construct_UClass_UObjective_Statics::NewProp_bIsCompleted_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjective_Statics::NewProp_bIsCompleted_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UObjective_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjective_Statics::NewProp_ObjectiveDescription,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjective_Statics::NewProp_bCanBeCompleted,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjective_Statics::NewProp_bIsCompleted,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjective_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjective>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjective_Statics::ClassParams = {
		&UObjective::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UObjective_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UObjective_Statics::PropPointers),
		0,
		0x001000A1u,
		METADATA_PARAMS(Z_Construct_UClass_UObjective_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjective_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjective()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjective_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjective, 3587477627);
	template<> QUESTSYSTEM_API UClass* StaticClass<UObjective>()
	{
		return UObjective::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjective(Z_Construct_UClass_UObjective, &UObjective::StaticClass, TEXT("/Script/QuestSystem"), TEXT("UObjective"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjective);
	void UInteractionObjective::StaticRegisterNativesUInteractionObjective()
	{
	}
	UClass* Z_Construct_UClass_UInteractionObjective_NoRegister()
	{
		return UInteractionObjective::StaticClass();
	}
	struct Z_Construct_UClass_UInteractionObjective_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InteractionObjectiveActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InteractionObjectiveActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInteractionObjective_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObjective,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInteractionObjective_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Objective.h" },
		{ "ModuleRelativePath", "Public/Objective.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInteractionObjective_Statics::NewProp_InteractionObjectiveActor_MetaData[] = {
		{ "Category", "InteractionObjective" },
		{ "Comment", "/*, meta=(AllowedClasses=\"ABaseInteractionActor\")*/" },
		{ "ModuleRelativePath", "Public/Objective.h" },
		{ "ToolTip", ", meta=(AllowedClasses=\"ABaseInteractionActor\")" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInteractionObjective_Statics::NewProp_InteractionObjectiveActor = { "InteractionObjectiveActor", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInteractionObjective, InteractionObjectiveActor), Z_Construct_UClass_ABaseInteractionActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInteractionObjective_Statics::NewProp_InteractionObjectiveActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInteractionObjective_Statics::NewProp_InteractionObjectiveActor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInteractionObjective_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInteractionObjective_Statics::NewProp_InteractionObjectiveActor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInteractionObjective_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInteractionObjective>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInteractionObjective_Statics::ClassParams = {
		&UInteractionObjective::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UInteractionObjective_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UInteractionObjective_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInteractionObjective_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInteractionObjective_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInteractionObjective()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInteractionObjective_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInteractionObjective, 225428564);
	template<> QUESTSYSTEM_API UClass* StaticClass<UInteractionObjective>()
	{
		return UInteractionObjective::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInteractionObjective(Z_Construct_UClass_UInteractionObjective, &UInteractionObjective::StaticClass, TEXT("/Script/QuestSystem"), TEXT("UInteractionObjective"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInteractionObjective);
	void ULocationObjective::StaticRegisterNativesULocationObjective()
	{
	}
	UClass* Z_Construct_UClass_ULocationObjective_NoRegister()
	{
		return ULocationObjective::StaticClass();
	}
	struct Z_Construct_UClass_ULocationObjective_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LocationObjective_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LocationObjective;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULocationObjective_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObjective,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULocationObjective_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Objective.h" },
		{ "ModuleRelativePath", "Public/Objective.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULocationObjective_Statics::NewProp_LocationObjective_MetaData[] = {
		{ "Category", "LocationObjective" },
		{ "Comment", "/*, meta=(AllowedClasses=\"BP_QuestLocation\")*/" },
		{ "ModuleRelativePath", "Public/Objective.h" },
		{ "ToolTip", ", meta=(AllowedClasses=\"BP_QuestLocation\")" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULocationObjective_Statics::NewProp_LocationObjective = { "LocationObjective", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULocationObjective, LocationObjective), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULocationObjective_Statics::NewProp_LocationObjective_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULocationObjective_Statics::NewProp_LocationObjective_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULocationObjective_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULocationObjective_Statics::NewProp_LocationObjective,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULocationObjective_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULocationObjective>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULocationObjective_Statics::ClassParams = {
		&ULocationObjective::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ULocationObjective_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ULocationObjective_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_ULocationObjective_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULocationObjective_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULocationObjective()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULocationObjective_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULocationObjective, 4076529748);
	template<> QUESTSYSTEM_API UClass* StaticClass<ULocationObjective>()
	{
		return ULocationObjective::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULocationObjective(Z_Construct_UClass_ULocationObjective, &ULocationObjective::StaticClass, TEXT("/Script/QuestSystem"), TEXT("ULocationObjective"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULocationObjective);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
