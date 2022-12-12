// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef INTERACTIONSUBSYSTEM_InteractableActor_generated_h
#error "InteractableActor.generated.h already included, missing '#pragma once' in InteractableActor.h"
#endif
#define INTERACTIONSUBSYSTEM_InteractableActor_generated_h

#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_SPARSE_DATA
#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_RPC_WRAPPERS \
	virtual void Interact_Implementation(AActor* Instigator) {}; \
 \
	DECLARE_FUNCTION(execInteract_Implementation); \
	DECLARE_FUNCTION(execInteract);


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execInteract_Implementation); \
	DECLARE_FUNCTION(execInteract);


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_EVENT_PARMS \
	struct InteractableActor_eventInteract_Parms \
	{ \
		AActor* Instigator; \
	};


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_CALLBACK_WRAPPERS
#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	INTERACTIONSUBSYSTEM_API UInteractableActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractableActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(INTERACTIONSUBSYSTEM_API, UInteractableActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractableActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	INTERACTIONSUBSYSTEM_API UInteractableActor(UInteractableActor&&); \
	INTERACTIONSUBSYSTEM_API UInteractableActor(const UInteractableActor&); \
public:


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	INTERACTIONSUBSYSTEM_API UInteractableActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	INTERACTIONSUBSYSTEM_API UInteractableActor(UInteractableActor&&); \
	INTERACTIONSUBSYSTEM_API UInteractableActor(const UInteractableActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(INTERACTIONSUBSYSTEM_API, UInteractableActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractableActor); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractableActor)


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInteractableActor(); \
	friend struct Z_Construct_UClass_UInteractableActor_Statics; \
public: \
	DECLARE_CLASS(UInteractableActor, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/InteractionSubsystem"), INTERACTIONSUBSYSTEM_API) \
	DECLARE_SERIALIZER(UInteractableActor)


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_GENERATED_UINTERFACE_BODY() \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_GENERATED_UINTERFACE_BODY() \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInteractableActor() {} \
public: \
	typedef UInteractableActor UClassType; \
	typedef IInteractableActor ThisClass; \
	static void Execute_Interact(UObject* O, AActor* Instigator); \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~IInteractableActor() {} \
public: \
	typedef UInteractableActor UClassType; \
	typedef IInteractableActor ThisClass; \
	static void Execute_Interact(UObject* O, AActor* Instigator); \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_10_PROLOG \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_EVENT_PARMS


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_SPARSE_DATA \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_RPC_WRAPPERS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_CALLBACK_WRAPPERS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_SPARSE_DATA \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_CALLBACK_WRAPPERS \
	Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INTERACTIONSUBSYSTEM_API UClass* StaticClass<class UInteractableActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_InteractionSubsystem_Source_InteractionSubsystem_Public_InteractableActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
