// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef QUESTSYSTEM_QuestListEntry_generated_h
#error "QuestListEntry.generated.h already included, missing '#pragma once' in QuestListEntry.h"
#endif
#define QUESTSYSTEM_QuestListEntry_generated_h

#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_SPARSE_DATA
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_RPC_WRAPPERS
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuestListEntry(); \
	friend struct Z_Construct_UClass_UQuestListEntry_Statics; \
public: \
	DECLARE_CLASS(UQuestListEntry, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UQuestListEntry)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUQuestListEntry(); \
	friend struct Z_Construct_UClass_UQuestListEntry_Statics; \
public: \
	DECLARE_CLASS(UQuestListEntry, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UQuestListEntry)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestListEntry(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestListEntry) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestListEntry); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestListEntry); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestListEntry(UQuestListEntry&&); \
	NO_API UQuestListEntry(const UQuestListEntry&); \
public:


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestListEntry(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestListEntry(UQuestListEntry&&); \
	NO_API UQuestListEntry(const UQuestListEntry&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestListEntry); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestListEntry); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestListEntry)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__QuestName() { return STRUCT_OFFSET(UQuestListEntry, QuestName); } \
	FORCEINLINE static uint32 __PPO__QuestEntryBorder() { return STRUCT_OFFSET(UQuestListEntry, QuestEntryBorder); } \
	FORCEINLINE static uint32 __PPO__Quest() { return STRUCT_OFFSET(UQuestListEntry, Quest); }


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_17_PROLOG
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_RPC_WRAPPERS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_INCLASS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEM_API UClass* StaticClass<class UQuestListEntry>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestListEntry_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
