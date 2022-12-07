// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TANKINVENTORYSYSTEM_InventoryCellWidget_generated_h
#error "InventoryCellWidget.generated.h already included, missing '#pragma once' in InventoryCellWidget.h"
#endif
#define TANKINVENTORYSYSTEM_InventoryCellWidget_generated_h

#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_SPARSE_DATA
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_RPC_WRAPPERS
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_RPC_WRAPPERS_NO_PURE_DECLS
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryCellWidget(); \
	friend struct Z_Construct_UClass_UInventoryCellWidget_Statics; \
public: \
	DECLARE_CLASS(UInventoryCellWidget, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/TankInventorySystem"), NO_API) \
	DECLARE_SERIALIZER(UInventoryCellWidget)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_INCLASS \
private: \
	static void StaticRegisterNativesUInventoryCellWidget(); \
	friend struct Z_Construct_UClass_UInventoryCellWidget_Statics; \
public: \
	DECLARE_CLASS(UInventoryCellWidget, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/TankInventorySystem"), NO_API) \
	DECLARE_SERIALIZER(UInventoryCellWidget)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryCellWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryCellWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryCellWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryCellWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryCellWidget(UInventoryCellWidget&&); \
	NO_API UInventoryCellWidget(const UInventoryCellWidget&); \
public:


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryCellWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryCellWidget(UInventoryCellWidget&&); \
	NO_API UInventoryCellWidget(const UInventoryCellWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryCellWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryCellWidget); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryCellWidget)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__bHasItem() { return STRUCT_OFFSET(UInventoryCellWidget, bHasItem); } \
	FORCEINLINE static uint32 __PPO__bCanDrag() { return STRUCT_OFFSET(UInventoryCellWidget, bCanDrag); } \
	FORCEINLINE static uint32 __PPO__ItemIcon() { return STRUCT_OFFSET(UInventoryCellWidget, ItemIcon); } \
	FORCEINLINE static uint32 __PPO__ItemCountText() { return STRUCT_OFFSET(UInventoryCellWidget, ItemCountText); } \
	FORCEINLINE static uint32 __PPO__Item() { return STRUCT_OFFSET(UInventoryCellWidget, Item); }


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_19_PROLOG
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_SPARSE_DATA \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_RPC_WRAPPERS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_INCLASS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_SPARSE_DATA \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TANKINVENTORYSYSTEM_API UClass* StaticClass<class UInventoryCellWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryCellWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
