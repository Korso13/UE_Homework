// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TankInventorySystem/Public/InventoryCellWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryCellWidget() {}
// Cross Module References
	TANKINVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryCellWidget_NoRegister();
	TANKINVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryCellWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_TankInventorySystem();
	UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	TANKINVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlotInfo();
	TANKINVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryWidget_NoRegister();
// End Cross Module References
	void UInventoryCellWidget::StaticRegisterNativesUInventoryCellWidget()
	{
	}
	UClass* Z_Construct_UClass_UInventoryCellWidget_NoRegister()
	{
		return UInventoryCellWidget::StaticClass();
	}
	struct Z_Construct_UClass_UInventoryCellWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHasItem_MetaData[];
#endif
		static void NewProp_bHasItem_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHasItem;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCanDrag_MetaData[];
#endif
		static void NewProp_bCanDrag_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCanDrag;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemIcon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ItemIcon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemCountText_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ItemCountText;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Item_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Item;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IndexInInventory_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_IndexInInventory;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParentInventoryWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ParentInventoryWidget;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventoryCellWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_TankInventorySystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryCellWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InventoryCellWidget.h" },
		{ "ModuleRelativePath", "Public/InventoryCellWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bHasItem_MetaData[] = {
		{ "ModuleRelativePath", "Public/InventoryCellWidget.h" },
	};
#endif
	void Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bHasItem_SetBit(void* Obj)
	{
		((UInventoryCellWidget*)Obj)->bHasItem = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bHasItem = { "bHasItem", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UInventoryCellWidget), &Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bHasItem_SetBit, METADATA_PARAMS(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bHasItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bHasItem_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bCanDrag_MetaData[] = {
		{ "Category", "InventoryCellWidget" },
		{ "ModuleRelativePath", "Public/InventoryCellWidget.h" },
	};
#endif
	void Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bCanDrag_SetBit(void* Obj)
	{
		((UInventoryCellWidget*)Obj)->bCanDrag = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bCanDrag = { "bCanDrag", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UInventoryCellWidget), &Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bCanDrag_SetBit, METADATA_PARAMS(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bCanDrag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bCanDrag_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ItemIcon_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "InventoryCellWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryCellWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ItemIcon = { "ItemIcon", nullptr, (EPropertyFlags)0x002008000008001c, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryCellWidget, ItemIcon), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ItemIcon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ItemIcon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ItemCountText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "InventoryCellWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryCellWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ItemCountText = { "ItemCountText", nullptr, (EPropertyFlags)0x002008000008001c, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryCellWidget, ItemCountText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ItemCountText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ItemCountText_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_Item_MetaData[] = {
		{ "ModuleRelativePath", "Public/InventoryCellWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryCellWidget, Item), Z_Construct_UScriptStruct_FInventorySlotInfo, METADATA_PARAMS(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_Item_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_Item_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_IndexInInventory_MetaData[] = {
		{ "Category", "InventoryCellWidget" },
		{ "Comment", "/** For equipment widget: must coincide with Equipment Slot keys and have Inventory array in Equipment Component have values with respective keys*/" },
		{ "ModuleRelativePath", "Public/InventoryCellWidget.h" },
		{ "ToolTip", "For equipment widget: must coincide with Equipment Slot keys and have Inventory array in Equipment Component have values with respective keys" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_IndexInInventory = { "IndexInInventory", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryCellWidget, IndexInInventory), METADATA_PARAMS(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_IndexInInventory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_IndexInInventory_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ParentInventoryWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryCellWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ParentInventoryWidget = { "ParentInventoryWidget", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryCellWidget, ParentInventoryWidget), Z_Construct_UClass_UInventoryWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ParentInventoryWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ParentInventoryWidget_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryCellWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bHasItem,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_bCanDrag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ItemIcon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ItemCountText,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_Item,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_IndexInInventory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryCellWidget_Statics::NewProp_ParentInventoryWidget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventoryCellWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryCellWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInventoryCellWidget_Statics::ClassParams = {
		&UInventoryCellWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UInventoryCellWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryCellWidget_Statics::PropPointers),
		0,
		0x00B010A1u,
		METADATA_PARAMS(Z_Construct_UClass_UInventoryCellWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryCellWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInventoryCellWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInventoryCellWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInventoryCellWidget, 3000597259);
	template<> TANKINVENTORYSYSTEM_API UClass* StaticClass<UInventoryCellWidget>()
	{
		return UInventoryCellWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInventoryCellWidget(Z_Construct_UClass_UInventoryCellWidget, &UInventoryCellWidget::StaticClass, TEXT("/Script/TankInventorySystem"), TEXT("UInventoryCellWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryCellWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
