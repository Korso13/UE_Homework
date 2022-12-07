// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TankInventorySystem/Public/InventoryManagerComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryManagerComponent() {}
// Cross Module References
	TANKINVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryManagerComponent_NoRegister();
	TANKINVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryManagerComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_TankInventorySystem();
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
	TANKINVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	TANKINVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UInventoryManagerComponent::execGetNanites)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNanites();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryManagerComponent::execCloseContainer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseContainer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryManagerComponent::execSetNanites)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_InCount);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetNanites(Z_Param_InCount);
		P_NATIVE_END;
	}
	void UInventoryManagerComponent::StaticRegisterNativesUInventoryManagerComponent()
	{
		UClass* Class = UInventoryManagerComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CloseContainer", &UInventoryManagerComponent::execCloseContainer },
			{ "GetNanites", &UInventoryManagerComponent::execGetNanites },
			{ "SetNanites", &UInventoryManagerComponent::execSetNanites },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInventoryManagerComponent_CloseContainer_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryManagerComponent_CloseContainer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryManagerComponent_CloseContainer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryManagerComponent, nullptr, "CloseContainer", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryManagerComponent_CloseContainer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryManagerComponent_CloseContainer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryManagerComponent_CloseContainer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryManagerComponent_CloseContainer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryManagerComponent_GetNanites_Statics
	{
		struct InventoryManagerComponent_eventGetNanites_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryManagerComponent_GetNanites_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryManagerComponent_eventGetNanites_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryManagerComponent_GetNanites_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryManagerComponent_GetNanites_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryManagerComponent_GetNanites_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryManagerComponent_GetNanites_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryManagerComponent, nullptr, "GetNanites", nullptr, nullptr, sizeof(InventoryManagerComponent_eventGetNanites_Parms), Z_Construct_UFunction_UInventoryManagerComponent_GetNanites_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryManagerComponent_GetNanites_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryManagerComponent_GetNanites_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryManagerComponent_GetNanites_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryManagerComponent_GetNanites()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryManagerComponent_GetNanites_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryManagerComponent_SetNanites_Statics
	{
		struct InventoryManagerComponent_eventSetNanites_Parms
		{
			int32 InCount;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_InCount;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryManagerComponent_SetNanites_Statics::NewProp_InCount = { "InCount", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryManagerComponent_eventSetNanites_Parms, InCount), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryManagerComponent_SetNanites_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryManagerComponent_SetNanites_Statics::NewProp_InCount,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryManagerComponent_SetNanites_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;*/" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
		{ "ToolTip", "virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryManagerComponent_SetNanites_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryManagerComponent, nullptr, "SetNanites", nullptr, nullptr, sizeof(InventoryManagerComponent_eventSetNanites_Parms), Z_Construct_UFunction_UInventoryManagerComponent_SetNanites_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryManagerComponent_SetNanites_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryManagerComponent_SetNanites_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryManagerComponent_SetNanites_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryManagerComponent_SetNanites()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryManagerComponent_SetNanites_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UInventoryManagerComponent_NoRegister()
	{
		return UInventoryManagerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UInventoryManagerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemsData_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ItemsData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathToItemsData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PathToItemsData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JSONData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_JSONData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StartingLoadout_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StartingLoadout;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LocalInventory_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LocalInventory;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EquipInventory_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EquipInventory;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExternalInventory_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ExternalInventory;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinInventorySize_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MinInventorySize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InventoryWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_InventoryWidgetClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EquipWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_EquipWidgetClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChestWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ChestWidgetClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InventoryWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InventoryWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EquipWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EquipWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChestWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ChestWidget;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventoryManagerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_TankInventorySystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInventoryManagerComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryManagerComponent_CloseContainer, "CloseContainer" }, // 349929861
		{ &Z_Construct_UFunction_UInventoryManagerComponent_GetNanites, "GetNanites" }, // 1783444474
		{ &Z_Construct_UFunction_UInventoryManagerComponent_SetNanites, "SetNanites" }, // 1352194776
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "InventoryManagerComponent.h" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ItemsData_MetaData[] = {
		{ "Category", "InventoryManagerComponent" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ItemsData = { "ItemsData", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, ItemsData), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ItemsData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ItemsData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_PathToItemsData_MetaData[] = {
		{ "Category", "InventoryManagerComponent" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_PathToItemsData = { "PathToItemsData", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, PathToItemsData), METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_PathToItemsData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_PathToItemsData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_JSONData_MetaData[] = {
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_JSONData = { "JSONData", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, JSONData), METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_JSONData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_JSONData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_StartingLoadout_MetaData[] = {
		{ "Category", "InventoryManagerComponent" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_StartingLoadout = { "StartingLoadout", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, StartingLoadout), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_StartingLoadout_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_StartingLoadout_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_LocalInventory_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_LocalInventory = { "LocalInventory", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, LocalInventory), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_LocalInventory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_LocalInventory_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipInventory_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipInventory = { "EquipInventory", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, EquipInventory), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipInventory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipInventory_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ExternalInventory_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ExternalInventory = { "ExternalInventory", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, ExternalInventory), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ExternalInventory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ExternalInventory_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_MinInventorySize_MetaData[] = {
		{ "Category", "InventoryManagerComponent" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_MinInventorySize = { "MinInventorySize", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, MinInventorySize), METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_MinInventorySize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_MinInventorySize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_InventoryWidgetClass_MetaData[] = {
		{ "Category", "InventoryManagerComponent" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_InventoryWidgetClass = { "InventoryWidgetClass", nullptr, (EPropertyFlags)0x0024080000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, InventoryWidgetClass), Z_Construct_UClass_UInventoryWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_InventoryWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_InventoryWidgetClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipWidgetClass_MetaData[] = {
		{ "Category", "InventoryManagerComponent" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipWidgetClass = { "EquipWidgetClass", nullptr, (EPropertyFlags)0x0024080000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, EquipWidgetClass), Z_Construct_UClass_UInventoryWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipWidgetClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ChestWidgetClass_MetaData[] = {
		{ "Category", "InventoryManagerComponent" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ChestWidgetClass = { "ChestWidgetClass", nullptr, (EPropertyFlags)0x0024080000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, ChestWidgetClass), Z_Construct_UClass_UInventoryWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ChestWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ChestWidgetClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_InventoryWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_InventoryWidget = { "InventoryWidget", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, InventoryWidget), Z_Construct_UClass_UInventoryWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_InventoryWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_InventoryWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipWidget = { "EquipWidget", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, EquipWidget), Z_Construct_UClass_UInventoryWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ChestWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryManagerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ChestWidget = { "ChestWidget", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryManagerComponent, ChestWidget), Z_Construct_UClass_UInventoryWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ChestWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ChestWidget_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryManagerComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ItemsData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_PathToItemsData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_JSONData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_StartingLoadout,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_LocalInventory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipInventory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ExternalInventory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_MinInventorySize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_InventoryWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ChestWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_InventoryWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_EquipWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryManagerComponent_Statics::NewProp_ChestWidget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventoryManagerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryManagerComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInventoryManagerComponent_Statics::ClassParams = {
		&UInventoryManagerComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UInventoryManagerComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UInventoryManagerComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryManagerComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInventoryManagerComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInventoryManagerComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInventoryManagerComponent, 608343114);
	template<> TANKINVENTORYSYSTEM_API UClass* StaticClass<UInventoryManagerComponent>()
	{
		return UInventoryManagerComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInventoryManagerComponent(Z_Construct_UClass_UInventoryManagerComponent, &UInventoryManagerComponent::StaticClass, TEXT("/Script/TankInventorySystem"), TEXT("UInventoryManagerComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryManagerComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
