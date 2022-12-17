// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystem/Public/QuestDialogueWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestDialogueWidget() {}
// Cross Module References
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestDialogueWidget_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestDialogueWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_QuestSystem();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestDescriptionWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UQuestDialogueWidget::execOnRejected)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRejected();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UQuestDialogueWidget::execOnAccepted)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnAccepted();
		P_NATIVE_END;
	}
	void UQuestDialogueWidget::StaticRegisterNativesUQuestDialogueWidget()
	{
		UClass* Class = UQuestDialogueWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnAccepted", &UQuestDialogueWidget::execOnAccepted },
			{ "OnRejected", &UQuestDialogueWidget::execOnRejected },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuestDialogueWidget_OnAccepted_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestDialogueWidget_OnAccepted_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/QuestDialogueWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestDialogueWidget_OnAccepted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestDialogueWidget, nullptr, "OnAccepted", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestDialogueWidget_OnAccepted_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestDialogueWidget_OnAccepted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestDialogueWidget_OnAccepted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestDialogueWidget_OnAccepted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UQuestDialogueWidget_OnRejected_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestDialogueWidget_OnRejected_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/QuestDialogueWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestDialogueWidget_OnRejected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestDialogueWidget, nullptr, "OnRejected", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestDialogueWidget_OnRejected_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestDialogueWidget_OnRejected_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestDialogueWidget_OnRejected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestDialogueWidget_OnRejected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UQuestDialogueWidget_NoRegister()
	{
		return UQuestDialogueWidget::StaticClass();
	}
	struct Z_Construct_UClass_UQuestDialogueWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AcceptButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AcceptButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RejectButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RejectButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestDescription_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_QuestDescription;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDisableMouseCursorOnDialogeEnd_MetaData[];
#endif
		static void NewProp_bDisableMouseCursorOnDialogeEnd_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDisableMouseCursorOnDialogeEnd;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestDialogueWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuestDialogueWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestDialogueWidget_OnAccepted, "OnAccepted" }, // 417845377
		{ &Z_Construct_UFunction_UQuestDialogueWidget_OnRejected, "OnRejected" }, // 2299205525
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestDialogueWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "QuestDialogueWidget.h" },
		{ "ModuleRelativePath", "Public/QuestDialogueWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_AcceptButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestDialogueWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestDialogueWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_AcceptButton = { "AcceptButton", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestDialogueWidget, AcceptButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_AcceptButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_AcceptButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_RejectButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestDialogueWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestDialogueWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_RejectButton = { "RejectButton", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestDialogueWidget, RejectButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_RejectButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_RejectButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_QuestDescription_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestDialogueWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_QuestDescription = { "QuestDescription", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestDialogueWidget, QuestDescription), Z_Construct_UClass_UQuestDescriptionWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_QuestDescription_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_QuestDescription_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_bDisableMouseCursorOnDialogeEnd_MetaData[] = {
		{ "Category", "QuestDialogueWidget" },
		{ "ModuleRelativePath", "Public/QuestDialogueWidget.h" },
	};
#endif
	void Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_bDisableMouseCursorOnDialogeEnd_SetBit(void* Obj)
	{
		((UQuestDialogueWidget*)Obj)->bDisableMouseCursorOnDialogeEnd = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_bDisableMouseCursorOnDialogeEnd = { "bDisableMouseCursorOnDialogeEnd", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UQuestDialogueWidget), &Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_bDisableMouseCursorOnDialogeEnd_SetBit, METADATA_PARAMS(Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_bDisableMouseCursorOnDialogeEnd_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_bDisableMouseCursorOnDialogeEnd_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestDialogueWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_AcceptButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_RejectButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_QuestDescription,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDialogueWidget_Statics::NewProp_bDisableMouseCursorOnDialogeEnd,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestDialogueWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestDialogueWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UQuestDialogueWidget_Statics::ClassParams = {
		&UQuestDialogueWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuestDialogueWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDialogueWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UQuestDialogueWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDialogueWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuestDialogueWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UQuestDialogueWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UQuestDialogueWidget, 2164034874);
	template<> QUESTSYSTEM_API UClass* StaticClass<UQuestDialogueWidget>()
	{
		return UQuestDialogueWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UQuestDialogueWidget(Z_Construct_UClass_UQuestDialogueWidget, &UQuestDialogueWidget::StaticClass, TEXT("/Script/QuestSystem"), TEXT("UQuestDialogueWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestDialogueWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
