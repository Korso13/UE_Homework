// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystem/Public/QuestDescriptionWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestDescriptionWidget() {}
// Cross Module References
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestDescriptionWidget_NoRegister();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestDescriptionWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_QuestSystem();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UScrollBox_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	QUESTSYSTEM_API UClass* Z_Construct_UClass_UObjectiveWidget_NoRegister();
// End Cross Module References
	void UQuestDescriptionWidget::StaticRegisterNativesUQuestDescriptionWidget()
	{
	}
	UClass* Z_Construct_UClass_UQuestDescriptionWidget_NoRegister()
	{
		return UQuestDescriptionWidget::StaticClass();
	}
	struct Z_Construct_UClass_UQuestDescriptionWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NameText_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NameText;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DescriptionText_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DescriptionText;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectivesList_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ObjectivesList;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectiveWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ObjectiveWidgetClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestDescriptionWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestDescriptionWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "QuestDescriptionWidget.h" },
		{ "ModuleRelativePath", "Public/QuestDescriptionWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_NameText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestDescriptionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestDescriptionWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_NameText = { "NameText", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestDescriptionWidget, NameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_NameText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_NameText_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_DescriptionText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestDescriptionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestDescriptionWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_DescriptionText = { "DescriptionText", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestDescriptionWidget, DescriptionText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_DescriptionText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_DescriptionText_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_ObjectivesList_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestDescriptionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/QuestDescriptionWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_ObjectivesList = { "ObjectivesList", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestDescriptionWidget, ObjectivesList), Z_Construct_UClass_UScrollBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_ObjectivesList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_ObjectivesList_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_ObjectiveWidgetClass_MetaData[] = {
		{ "Category", "QuestDescriptionWidget" },
		{ "ModuleRelativePath", "Public/QuestDescriptionWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_ObjectiveWidgetClass = { "ObjectiveWidgetClass", nullptr, (EPropertyFlags)0x0024080000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestDescriptionWidget, ObjectiveWidgetClass), Z_Construct_UClass_UObjectiveWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_ObjectiveWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_ObjectiveWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestDescriptionWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_NameText,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_DescriptionText,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_ObjectivesList,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDescriptionWidget_Statics::NewProp_ObjectiveWidgetClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestDescriptionWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestDescriptionWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UQuestDescriptionWidget_Statics::ClassParams = {
		&UQuestDescriptionWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UQuestDescriptionWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDescriptionWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UQuestDescriptionWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDescriptionWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuestDescriptionWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UQuestDescriptionWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UQuestDescriptionWidget, 1735354125);
	template<> QUESTSYSTEM_API UClass* StaticClass<UQuestDescriptionWidget>()
	{
		return UQuestDescriptionWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UQuestDescriptionWidget(Z_Construct_UClass_UQuestDescriptionWidget, &UQuestDescriptionWidget::StaticClass, TEXT("/Script/QuestSystem"), TEXT("UQuestDescriptionWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestDescriptionWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
