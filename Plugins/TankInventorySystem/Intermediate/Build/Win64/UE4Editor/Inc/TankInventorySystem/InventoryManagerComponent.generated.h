// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TANKINVENTORYSYSTEM_InventoryManagerComponent_generated_h
#error "InventoryManagerComponent.generated.h already included, missing '#pragma once' in InventoryManagerComponent.h"
#endif
#define TANKINVENTORYSYSTEM_InventoryManagerComponent_generated_h

#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_SPARSE_DATA
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetNanites); \
	DECLARE_FUNCTION(execCloseContainer); \
	DECLARE_FUNCTION(execSetNanites);


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetNanites); \
	DECLARE_FUNCTION(execCloseContainer); \
	DECLARE_FUNCTION(execSetNanites);


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryManagerComponent(); \
	friend struct Z_Construct_UClass_UInventoryManagerComponent_Statics; \
public: \
	DECLARE_CLASS(UInventoryManagerComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TankInventorySystem"), NO_API) \
	DECLARE_SERIALIZER(UInventoryManagerComponent)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUInventoryManagerComponent(); \
	friend struct Z_Construct_UClass_UInventoryManagerComponent_Statics; \
public: \
	DECLARE_CLASS(UInventoryManagerComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TankInventorySystem"), NO_API) \
	DECLARE_SERIALIZER(UInventoryManagerComponent)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryManagerComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryManagerComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryManagerComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryManagerComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryManagerComponent(UInventoryManagerComponent&&); \
	NO_API UInventoryManagerComponent(const UInventoryManagerComponent&); \
public:


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryManagerComponent(UInventoryManagerComponent&&); \
	NO_API UInventoryManagerComponent(const UInventoryManagerComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryManagerComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryManagerComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UInventoryManagerComponent)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ItemsData() { return STRUCT_OFFSET(UInventoryManagerComponent, ItemsData); } \
	FORCEINLINE static uint32 __PPO__PathToItemsData() { return STRUCT_OFFSET(UInventoryManagerComponent, PathToItemsData); } \
	FORCEINLINE static uint32 __PPO__JSONData() { return STRUCT_OFFSET(UInventoryManagerComponent, JSONData); } \
	FORCEINLINE static uint32 __PPO__StartingLoadout() { return STRUCT_OFFSET(UInventoryManagerComponent, StartingLoadout); } \
	FORCEINLINE static uint32 __PPO__LocalInventory() { return STRUCT_OFFSET(UInventoryManagerComponent, LocalInventory); } \
	FORCEINLINE static uint32 __PPO__EquipInventory() { return STRUCT_OFFSET(UInventoryManagerComponent, EquipInventory); } \
	FORCEINLINE static uint32 __PPO__ExternalInventory() { return STRUCT_OFFSET(UInventoryManagerComponent, ExternalInventory); } \
	FORCEINLINE static uint32 __PPO__MinInventorySize() { return STRUCT_OFFSET(UInventoryManagerComponent, MinInventorySize); } \
	FORCEINLINE static uint32 __PPO__InventoryWidgetClass() { return STRUCT_OFFSET(UInventoryManagerComponent, InventoryWidgetClass); } \
	FORCEINLINE static uint32 __PPO__EquipWidgetClass() { return STRUCT_OFFSET(UInventoryManagerComponent, EquipWidgetClass); } \
	FORCEINLINE static uint32 __PPO__ChestWidgetClass() { return STRUCT_OFFSET(UInventoryManagerComponent, ChestWidgetClass); } \
	FORCEINLINE static uint32 __PPO__InventoryWidget() { return STRUCT_OFFSET(UInventoryManagerComponent, InventoryWidget); } \
	FORCEINLINE static uint32 __PPO__EquipWidget() { return STRUCT_OFFSET(UInventoryManagerComponent, EquipWidget); } \
	FORCEINLINE static uint32 __PPO__ChestWidget() { return STRUCT_OFFSET(UInventoryManagerComponent, ChestWidget); }


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_16_PROLOG
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_SPARSE_DATA \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_RPC_WRAPPERS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_INCLASS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_SPARSE_DATA \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TANKINVENTORYSYSTEM_API UClass* StaticClass<class UInventoryManagerComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryManagerComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
