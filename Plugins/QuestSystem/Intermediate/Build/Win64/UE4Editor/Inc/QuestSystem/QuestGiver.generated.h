// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef QUESTSYSTEM_QuestGiver_generated_h
#error "QuestGiver.generated.h already included, missing '#pragma once' in QuestGiver.h"
#endif
#define QUESTSYSTEM_QuestGiver_generated_h

#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_SPARSE_DATA
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_RPC_WRAPPERS
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_RPC_WRAPPERS_NO_PURE_DECLS
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAQuestGiver(); \
	friend struct Z_Construct_UClass_AQuestGiver_Statics; \
public: \
	DECLARE_CLASS(AQuestGiver, ABaseInteractionActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(AQuestGiver)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAQuestGiver(); \
	friend struct Z_Construct_UClass_AQuestGiver_Statics; \
public: \
	DECLARE_CLASS(AQuestGiver, ABaseInteractionActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(AQuestGiver)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AQuestGiver(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AQuestGiver) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AQuestGiver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AQuestGiver); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AQuestGiver(AQuestGiver&&); \
	NO_API AQuestGiver(const AQuestGiver&); \
public:


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AQuestGiver(AQuestGiver&&); \
	NO_API AQuestGiver(const AQuestGiver&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AQuestGiver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AQuestGiver); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AQuestGiver)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SceneComponent() { return STRUCT_OFFSET(AQuestGiver, SceneComponent); } \
	FORCEINLINE static uint32 __PPO__QuestAvailableSign() { return STRUCT_OFFSET(AQuestGiver, QuestAvailableSign); } \
	FORCEINLINE static uint32 __PPO__QuestSignWidgetClass() { return STRUCT_OFFSET(AQuestGiver, QuestSignWidgetClass); }


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_18_PROLOG
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_RPC_WRAPPERS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_INCLASS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEM_API UClass* StaticClass<class AQuestGiver>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestGiver_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
