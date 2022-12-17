// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystem/Public/ObjectiveWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectiveWidget() {}
// Cross Module References
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UObjectiveWidget_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UObjectiveWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_QuestSystem();
	UMG_API UClass* Z_Construct_UClass_UCheckBox_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
// End Cross Module References
	void UObjectiveWidget::StaticRegisterNativesUObjectiveWidget()
	{
	}
	UClass* Z_Construct_UClass_UObjectiveWidget_NoRegister()
	{
		return UObjectiveWidget::StaticClass();
	}
	struct Z_Construct_UClass_UObjectiveWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CompletionCheckbox_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CompletionCheckbox;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectiveDescription_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ObjectiveDescription;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectiveWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "ObjectiveWidget.h" },
		{ "ModuleRelativePath", "Public/ObjectiveWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveWidget_Statics::NewProp_CompletionCheckbox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ObjectiveWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UObjectiveWidget_Statics::NewProp_CompletionCheckbox = { "CompletionCheckbox", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectiveWidget, CompletionCheckbox), Z_Construct_UClass_UCheckBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UObjectiveWidget_Statics::NewProp_CompletionCheckbox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveWidget_Statics::NewProp_CompletionCheckbox_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveWidget_Statics::NewProp_ObjectiveDescription_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ObjectiveWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UObjectiveWidget_Statics::NewProp_ObjectiveDescription = { "ObjectiveDescription", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectiveWidget, ObjectiveDescription), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UObjectiveWidget_Statics::NewProp_ObjectiveDescription_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveWidget_Statics::NewProp_ObjectiveDescription_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UObjectiveWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectiveWidget_Statics::NewProp_CompletionCheckbox,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectiveWidget_Statics::NewProp_ObjectiveDescription,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectiveWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectiveWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectiveWidget_Statics::ClassParams = {
		&UObjectiveWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UObjectiveWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectiveWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectiveWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectiveWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectiveWidget, 1501612183);
	template<> QUESTSYSTEM_API UClass* StaticClass<UObjectiveWidget>()
	{
		return UObjectiveWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectiveWidget(Z_Construct_UClass_UObjectiveWidget, &UObjectiveWidget::StaticClass, TEXT("/Script/QuestSystem"), TEXT("UObjectiveWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectiveWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
