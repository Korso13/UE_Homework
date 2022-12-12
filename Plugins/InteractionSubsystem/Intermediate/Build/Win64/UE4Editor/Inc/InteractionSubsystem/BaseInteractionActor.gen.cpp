// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InteractionSubsystem/Public/BaseInteractionActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseInteractionActor() {}
// Cross Module References
	INTERACTIONSUBSYSTEM_API UClass* Z_Construct_UClass_ABaseInteractionActor_NoRegister();
	INTERACTIONSUBSYSTEM_API UClass* Z_Construct_UClass_ABaseInteractionActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_InteractionSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	INTERACTIONSUBSYSTEM_API UClass* Z_Construct_UClass_UInteractableActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ABaseInteractionActor::execOnInteractionFinished)
	{
		P_GET_OBJECT(AActor,Z_Param_InteractionInstigator);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnInteractionFinished(Z_Param_InteractionInstigator);
		P_NATIVE_END;
	}
	void ABaseInteractionActor::StaticRegisterNativesABaseInteractionActor()
	{
		UClass* Class = ABaseInteractionActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnInteractionFinished", &ABaseInteractionActor::execOnInteractionFinished },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished_Statics
	{
		struct BaseInteractionActor_eventOnInteractionFinished_Parms
		{
			AActor* InteractionInstigator;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InteractionInstigator;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished_Statics::NewProp_InteractionInstigator = { "InteractionInstigator", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BaseInteractionActor_eventOnInteractionFinished_Parms, InteractionInstigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished_Statics::NewProp_InteractionInstigator,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BaseInteractionActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseInteractionActor, nullptr, "OnInteractionFinished", nullptr, nullptr, sizeof(BaseInteractionActor_eventOnInteractionFinished_Parms), Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABaseInteractionActor_NoRegister()
	{
		return ABaseInteractionActor::StaticClass();
	}
	struct Z_Construct_UClass_ABaseInteractionActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABaseInteractionActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_InteractionSubsystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABaseInteractionActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABaseInteractionActor_OnInteractionFinished, "OnInteractionFinished" }, // 3878655434
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseInteractionActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BaseInteractionActor.h" },
		{ "ModuleRelativePath", "Public/BaseInteractionActor.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ABaseInteractionActor_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInteractableActor_NoRegister, (int32)VTABLE_OFFSET(ABaseInteractionActor, IInteractableActor), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABaseInteractionActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseInteractionActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABaseInteractionActor_Statics::ClassParams = {
		&ABaseInteractionActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABaseInteractionActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABaseInteractionActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABaseInteractionActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABaseInteractionActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABaseInteractionActor, 979252380);
	template<> INTERACTIONSUBSYSTEM_API UClass* StaticClass<ABaseInteractionActor>()
	{
		return ABaseInteractionActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABaseInteractionActor(Z_Construct_UClass_ABaseInteractionActor, &ABaseInteractionActor::StaticClass, TEXT("/Script/InteractionSubsystem"), TEXT("ABaseInteractionActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseInteractionActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
