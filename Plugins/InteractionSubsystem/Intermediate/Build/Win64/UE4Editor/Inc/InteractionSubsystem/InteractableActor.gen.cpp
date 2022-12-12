// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InteractionSubsystem/Public/InteractableActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractableActor() {}
// Cross Module References
	INTERACTIONSUBSYSTEM_API UClass* Z_Construct_UClass_UInteractableActor_NoRegister();
	INTERACTIONSUBSYSTEM_API UClass* Z_Construct_UClass_UInteractableActor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_InteractionSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IInteractableActor::execInteract_Implementation)
	{
		P_GET_OBJECT(AActor,Z_Param_InteractionInstigator);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Interact_Implementation(Z_Param_InteractionInstigator);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInteractableActor::execInteract)
	{
		P_GET_OBJECT(AActor,Z_Param_Instigator);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Interact_Implementation(Z_Param_Instigator);
		P_NATIVE_END;
	}
	void IInteractableActor::Interact(AActor* Instigator)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_Interact instead.");
	}
	void UInteractableActor::StaticRegisterNativesUInteractableActor()
	{
		UClass* Class = UInteractableActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Interact", &IInteractableActor::execInteract },
			{ "Interact_Implementation", &IInteractableActor::execInteract_Implementation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInteractableActor_Interact_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInteractableActor_Interact_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InteractableActor_eventInteract_Parms, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractableActor_Interact_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractableActor_Interact_Statics::NewProp_Instigator,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractableActor_Interact_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/InteractableActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractableActor_Interact_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractableActor, nullptr, "Interact", nullptr, nullptr, sizeof(InteractableActor_eventInteract_Parms), Z_Construct_UFunction_UInteractableActor_Interact_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractableActor_Interact_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInteractableActor_Interact_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractableActor_Interact_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInteractableActor_Interact()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInteractableActor_Interact_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInteractableActor_Interact_Implementation_Statics
	{
		struct InteractableActor_eventInteract_Implementation_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInteractableActor_Interact_Implementation_Statics::NewProp_InteractionInstigator = { "InteractionInstigator", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InteractableActor_eventInteract_Implementation_Parms, InteractionInstigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractableActor_Interact_Implementation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractableActor_Interact_Implementation_Statics::NewProp_InteractionInstigator,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInteractableActor_Interact_Implementation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/InteractableActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractableActor_Interact_Implementation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInteractableActor, nullptr, "Interact_Implementation", nullptr, nullptr, sizeof(InteractableActor_eventInteract_Implementation_Parms), Z_Construct_UFunction_UInteractableActor_Interact_Implementation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractableActor_Interact_Implementation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInteractableActor_Interact_Implementation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractableActor_Interact_Implementation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInteractableActor_Interact_Implementation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInteractableActor_Interact_Implementation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UInteractableActor_NoRegister()
	{
		return UInteractableActor::StaticClass();
	}
	struct Z_Construct_UClass_UInteractableActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInteractableActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_InteractionSubsystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInteractableActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInteractableActor_Interact, "Interact" }, // 803903026
		{ &Z_Construct_UFunction_UInteractableActor_Interact_Implementation, "Interact_Implementation" }, // 2077236904
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInteractableActor_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/InteractableActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInteractableActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInteractableActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInteractableActor_Statics::ClassParams = {
		&UInteractableActor::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UInteractableActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInteractableActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInteractableActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInteractableActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInteractableActor, 3136306225);
	template<> INTERACTIONSUBSYSTEM_API UClass* StaticClass<UInteractableActor>()
	{
		return UInteractableActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInteractableActor(Z_Construct_UClass_UInteractableActor, &UInteractableActor::StaticClass, TEXT("/Script/InteractionSubsystem"), TEXT("UInteractableActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInteractableActor);
	static FName NAME_UInteractableActor_Interact = FName(TEXT("Interact"));
	void IInteractableActor::Execute_Interact(UObject* O, AActor* Instigator)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInteractableActor::StaticClass()));
		InteractableActor_eventInteract_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInteractableActor_Interact);
		if (Func)
		{
			Parms.Instigator=Instigator;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInteractableActor*)(O->GetNativeInterfaceAddress(UInteractableActor::StaticClass())))
		{
			I->Interact_Implementation(Instigator);
		}
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
