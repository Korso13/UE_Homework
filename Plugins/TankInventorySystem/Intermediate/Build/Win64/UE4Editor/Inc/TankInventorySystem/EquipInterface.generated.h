// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TANKINVENTORYSYSTEM_EquipInterface_generated_h
#error "EquipInterface.generated.h already included, missing '#pragma once' in EquipInterface.h"
#endif
#define TANKINVENTORYSYSTEM_EquipInterface_generated_h

#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_SPARSE_DATA
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_RPC_WRAPPERS
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TANKINVENTORYSYSTEM_API UEquipInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEquipInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TANKINVENTORYSYSTEM_API, UEquipInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEquipInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	TANKINVENTORYSYSTEM_API UEquipInterface(UEquipInterface&&); \
	TANKINVENTORYSYSTEM_API UEquipInterface(const UEquipInterface&); \
public:


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TANKINVENTORYSYSTEM_API UEquipInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	TANKINVENTORYSYSTEM_API UEquipInterface(UEquipInterface&&); \
	TANKINVENTORYSYSTEM_API UEquipInterface(const UEquipInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TANKINVENTORYSYSTEM_API, UEquipInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEquipInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEquipInterface)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUEquipInterface(); \
	friend struct Z_Construct_UClass_UEquipInterface_Statics; \
public: \
	DECLARE_CLASS(UEquipInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/TankInventorySystem"), TANKINVENTORYSYSTEM_API) \
	DECLARE_SERIALIZER(UEquipInterface)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_GENERATED_UINTERFACE_BODY() \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_GENERATED_UINTERFACE_BODY() \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IEquipInterface() {} \
public: \
	typedef UEquipInterface UClassType; \
	typedef IEquipInterface ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_INCLASS_IINTERFACE \
protected: \
	virtual ~IEquipInterface() {} \
public: \
	typedef UEquipInterface UClassType; \
	typedef IEquipInterface ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_11_PROLOG
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_SPARSE_DATA \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_RPC_WRAPPERS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_SPARSE_DATA \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TANKINVENTORYSYSTEM_API UClass* StaticClass<class UEquipInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_EquipInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
