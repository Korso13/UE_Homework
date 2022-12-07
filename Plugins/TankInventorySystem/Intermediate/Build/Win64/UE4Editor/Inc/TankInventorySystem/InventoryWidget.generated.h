// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TANKINVENTORYSYSTEM_InventoryWidget_generated_h
#error "InventoryWidget.generated.h already included, missing '#pragma once' in InventoryWidget.h"
#endif
#define TANKINVENTORYSYSTEM_InventoryWidget_generated_h

#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_SPARSE_DATA
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_RPC_WRAPPERS
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryWidget(); \
	friend struct Z_Construct_UClass_UInventoryWidget_Statics; \
public: \
	DECLARE_CLASS(UInventoryWidget, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/TankInventorySystem"), NO_API) \
	DECLARE_SERIALIZER(UInventoryWidget)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUInventoryWidget(); \
	friend struct Z_Construct_UClass_UInventoryWidget_Statics; \
public: \
	DECLARE_CLASS(UInventoryWidget, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/TankInventorySystem"), NO_API) \
	DECLARE_SERIALIZER(UInventoryWidget)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryWidget(UInventoryWidget&&); \
	NO_API UInventoryWidget(const UInventoryWidget&); \
public:


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryWidget(UInventoryWidget&&); \
	NO_API UInventoryWidget(const UInventoryWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryWidget); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryWidget)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__InventoryPanel() { return STRUCT_OFFSET(UInventoryWidget, InventoryPanel); } \
	FORCEINLINE static uint32 __PPO__NanitesSlot() { return STRUCT_OFFSET(UInventoryWidget, NanitesSlot); } \
	FORCEINLINE static uint32 __PPO__CloseWindowButton() { return STRUCT_OFFSET(UInventoryWidget, CloseWindowButton); } \
	FORCEINLINE static uint32 __PPO__CellWidgetClass() { return STRUCT_OFFSET(UInventoryWidget, CellWidgetClass); } \
	FORCEINLINE static uint32 __PPO__ItemsInRow() { return STRUCT_OFFSET(UInventoryWidget, ItemsInRow); } \
	FORCEINLINE static uint32 __PPO__CellWidgets() { return STRUCT_OFFSET(UInventoryWidget, CellWidgets); }


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_20_PROLOG
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_SPARSE_DATA \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_RPC_WRAPPERS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_INCLASS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_SPARSE_DATA \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TANKINVENTORYSYSTEM_API UClass* StaticClass<class UInventoryWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_InventoryWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
