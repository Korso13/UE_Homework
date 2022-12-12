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
#ifdef INTERACTIONSUBSYSTEM_InteractionComponent_generated_h
#error "InteractionComponent.generated.h already included, missing '#pragma once' in InteractionComponent.h"
#endif
#define INTERACTIONSUBSYSTEM_InteractionComponent_generated_h

#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_SPARSE_DATA
#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnInteractionCompEndOverlap); \
	DECLARE_FUNCTION(execOnInteractionCompBeginOverlap); \
	DECLARE_FUNCTION(execInteract);


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnInteractionCompEndOverlap); \
	DECLARE_FUNCTION(execOnInteractionCompBeginOverlap); \
	DECLARE_FUNCTION(execInteract);


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInteractionComponent(); \
	friend struct Z_Construct_UClass_UInteractionComponent_Statics; \
public: \
	DECLARE_CLASS(UInteractionComponent, USphereComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/InteractionSubsystem"), NO_API) \
	DECLARE_SERIALIZER(UInteractionComponent)


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUInteractionComponent(); \
	friend struct Z_Construct_UClass_UInteractionComponent_Statics; \
public: \
	DECLARE_CLASS(UInteractionComponent, USphereComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/InteractionSubsystem"), NO_API) \
	DECLARE_SERIALIZER(UInteractionComponent)


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInteractionComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractionComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInteractionComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractionComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInteractionComponent(UInteractionComponent&&); \
	NO_API UInteractionComponent(const UInteractionComponent&); \
public:


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInteractionComponent(UInteractionComponent&&); \
	NO_API UInteractionComponent(const UInteractionComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInteractionComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractionComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UInteractionComponent)


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__InteractTooltipClass() { return STRUCT_OFFSET(UInteractionComponent, InteractTooltipClass); } \
	FORCEINLINE static uint32 __PPO__InteractTooltip() { return STRUCT_OFFSET(UInteractionComponent, InteractTooltip); } \
	FORCEINLINE static uint32 __PPO__InteractionActor() { return STRUCT_OFFSET(UInteractionComponent, InteractionActor); }


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_11_PROLOG
#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_SPARSE_DATA \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_RPC_WRAPPERS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_INCLASS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_SPARSE_DATA \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INTERACTIONSUBSYSTEM_API UClass* StaticClass<class UInteractionComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractionComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
