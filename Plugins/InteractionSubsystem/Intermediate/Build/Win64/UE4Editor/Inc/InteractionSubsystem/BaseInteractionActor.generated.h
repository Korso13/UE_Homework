// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef INTERACTIONSUBSYSTEM_BaseInteractionActor_generated_h
#error "BaseInteractionActor.generated.h already included, missing '#pragma once' in BaseInteractionActor.h"
#endif
#define INTERACTIONSUBSYSTEM_BaseInteractionActor_generated_h

#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_SPARSE_DATA
#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnInteractionFinished);


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnInteractionFinished);


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABaseInteractionActor(); \
	friend struct Z_Construct_UClass_ABaseInteractionActor_Statics; \
public: \
	DECLARE_CLASS(ABaseInteractionActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/InteractionSubsystem"), NO_API) \
	DECLARE_SERIALIZER(ABaseInteractionActor) \
	virtual UObject* _getUObject() const override { return const_cast<ABaseInteractionActor*>(this); }


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_INCLASS \
private: \
	static void StaticRegisterNativesABaseInteractionActor(); \
	friend struct Z_Construct_UClass_ABaseInteractionActor_Statics; \
public: \
	DECLARE_CLASS(ABaseInteractionActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/InteractionSubsystem"), NO_API) \
	DECLARE_SERIALIZER(ABaseInteractionActor) \
	virtual UObject* _getUObject() const override { return const_cast<ABaseInteractionActor*>(this); }


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABaseInteractionActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABaseInteractionActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseInteractionActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseInteractionActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseInteractionActor(ABaseInteractionActor&&); \
	NO_API ABaseInteractionActor(const ABaseInteractionActor&); \
public:


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseInteractionActor(ABaseInteractionActor&&); \
	NO_API ABaseInteractionActor(const ABaseInteractionActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseInteractionActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseInteractionActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABaseInteractionActor)


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_PRIVATE_PROPERTY_OFFSET
#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_10_PROLOG
#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_SPARSE_DATA \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_RPC_WRAPPERS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_INCLASS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_SPARSE_DATA \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INTERACTIONSUBSYSTEM_API UClass* StaticClass<class ABaseInteractionActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_BaseInteractionActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
