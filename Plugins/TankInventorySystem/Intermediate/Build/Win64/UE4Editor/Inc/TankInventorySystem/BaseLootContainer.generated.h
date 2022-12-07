// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef TANKINVENTORYSYSTEM_BaseLootContainer_generated_h
#error "BaseLootContainer.generated.h already included, missing '#pragma once' in BaseLootContainer.h"
#endif
#define TANKINVENTORYSYSTEM_BaseLootContainer_generated_h

#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_SPARSE_DATA
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnComponentEndOverlap); \
	DECLARE_FUNCTION(execOnBeginOverlap); \
	DECLARE_FUNCTION(execCloseContainer);


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnComponentEndOverlap); \
	DECLARE_FUNCTION(execOnBeginOverlap); \
	DECLARE_FUNCTION(execCloseContainer);


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABaseLootContainer(); \
	friend struct Z_Construct_UClass_ABaseLootContainer_Statics; \
public: \
	DECLARE_CLASS(ABaseLootContainer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TankInventorySystem"), NO_API) \
	DECLARE_SERIALIZER(ABaseLootContainer)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_INCLASS \
private: \
	static void StaticRegisterNativesABaseLootContainer(); \
	friend struct Z_Construct_UClass_ABaseLootContainer_Statics; \
public: \
	DECLARE_CLASS(ABaseLootContainer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TankInventorySystem"), NO_API) \
	DECLARE_SERIALIZER(ABaseLootContainer)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABaseLootContainer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABaseLootContainer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseLootContainer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseLootContainer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseLootContainer(ABaseLootContainer&&); \
	NO_API ABaseLootContainer(const ABaseLootContainer&); \
public:


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseLootContainer(ABaseLootContainer&&); \
	NO_API ABaseLootContainer(const ABaseLootContainer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseLootContainer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseLootContainer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABaseLootContainer)


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Collision() { return STRUCT_OFFSET(ABaseLootContainer, Collision); } \
	FORCEINLINE static uint32 __PPO__BoxMesh() { return STRUCT_OFFSET(ABaseLootContainer, BoxMesh); } \
	FORCEINLINE static uint32 __PPO__Inventory() { return STRUCT_OFFSET(ABaseLootContainer, Inventory); } \
	FORCEINLINE static uint32 __PPO__ContainerContents() { return STRUCT_OFFSET(ABaseLootContainer, ContainerContents); } \
	FORCEINLINE static uint32 __PPO__ButtonTooltip() { return STRUCT_OFFSET(ABaseLootContainer, ButtonTooltip); } \
	FORCEINLINE static uint32 __PPO__ButtonTooltipClass() { return STRUCT_OFFSET(ABaseLootContainer, ButtonTooltipClass); } \
	FORCEINLINE static uint32 __PPO__ActorInRange() { return STRUCT_OFFSET(ABaseLootContainer, ActorInRange); }


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_16_PROLOG
#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_SPARSE_DATA \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_RPC_WRAPPERS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_INCLASS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_SPARSE_DATA \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TANKINVENTORYSYSTEM_API UClass* StaticClass<class ABaseLootContainer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_TankInventorySystem_Source_TankInventorySystem_Public_BaseLootContainer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
