// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UObjective;
#ifdef QUESTSYSTEM_Quest_generated_h
#error "Quest.generated.h already included, missing '#pragma once' in Quest.h"
#endif
#define QUESTSYSTEM_Quest_generated_h

#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_SPARSE_DATA
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execResetLocation); \
	DECLARE_FUNCTION(execTakeQuest); \
	DECLARE_FUNCTION(execOnObjectiveCompleted);


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execResetLocation); \
	DECLARE_FUNCTION(execTakeQuest); \
	DECLARE_FUNCTION(execOnObjectiveCompleted);


#if WITH_EDITOR
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_EDITOR_ONLY_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAddLocationObjective); \
	DECLARE_FUNCTION(execAddInteractObjective);


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAddLocationObjective); \
	DECLARE_FUNCTION(execAddInteractObjective);


#else
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_EDITOR_ONLY_RPC_WRAPPERS
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS
#endif //WITH_EDITOR
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAQuest(); \
	friend struct Z_Construct_UClass_AQuest_Statics; \
public: \
	DECLARE_CLASS(AQuest, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(AQuest)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_INCLASS \
private: \
	static void StaticRegisterNativesAQuest(); \
	friend struct Z_Construct_UClass_AQuest_Statics; \
public: \
	DECLARE_CLASS(AQuest, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(AQuest)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AQuest(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AQuest) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AQuest); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AQuest); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AQuest(AQuest&&); \
	NO_API AQuest(const AQuest&); \
public:


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AQuest(AQuest&&); \
	NO_API AQuest(const AQuest&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AQuest); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AQuest); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AQuest)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__QuestName() { return STRUCT_OFFSET(AQuest, QuestName); } \
	FORCEINLINE static uint32 __PPO__QuestDescription() { return STRUCT_OFFSET(AQuest, QuestDescription); } \
	FORCEINLINE static uint32 __PPO__Objectives() { return STRUCT_OFFSET(AQuest, Objectives); } \
	FORCEINLINE static uint32 __PPO__bIsTaken() { return STRUCT_OFFSET(AQuest, bIsTaken); } \
	FORCEINLINE static uint32 __PPO__bIsOrderedObjectives() { return STRUCT_OFFSET(AQuest, bIsOrderedObjectives); } \
	FORCEINLINE static uint32 __PPO__bIsMainQuest() { return STRUCT_OFFSET(AQuest, bIsMainQuest); } \
	FORCEINLINE static uint32 __PPO__bIsCompleted() { return STRUCT_OFFSET(AQuest, bIsCompleted); } \
	FORCEINLINE static uint32 __PPO__PrerequisiteQuest() { return STRUCT_OFFSET(AQuest, PrerequisiteQuest); }


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_15_PROLOG
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_RPC_WRAPPERS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_EDITOR_ONLY_RPC_WRAPPERS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_INCLASS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEM_API UClass* StaticClass<class AQuest>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_QuestSystem_Source_QuestSystem_Public_Quest_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
