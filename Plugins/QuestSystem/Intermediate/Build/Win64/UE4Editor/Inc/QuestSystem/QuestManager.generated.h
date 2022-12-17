// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef QUESTSYSTEM_QuestManager_generated_h
#error "QuestManager.generated.h already included, missing '#pragma once' in QuestManager.h"
#endif
#define QUESTSYSTEM_QuestManager_generated_h

#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_SPARSE_DATA
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_RPC_WRAPPERS
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_RPC_WRAPPERS_NO_PURE_DECLS
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuestManager(); \
	friend struct Z_Construct_UClass_UQuestManager_Statics; \
public: \
	DECLARE_CLASS(UQuestManager, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UQuestManager)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUQuestManager(); \
	friend struct Z_Construct_UClass_UQuestManager_Statics; \
public: \
	DECLARE_CLASS(UQuestManager, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UQuestManager)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestManager(UQuestManager&&); \
	NO_API UQuestManager(const UQuestManager&); \
public:


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestManager(UQuestManager&&); \
	NO_API UQuestManager(const UQuestManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UQuestManager)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ActiveQuestWidget() { return STRUCT_OFFSET(UQuestManager, ActiveQuestWidget); } \
	FORCEINLINE static uint32 __PPO__QuestBoardWidgetClass() { return STRUCT_OFFSET(UQuestManager, QuestBoardWidgetClass); } \
	FORCEINLINE static uint32 __PPO__TakenQuests() { return STRUCT_OFFSET(UQuestManager, TakenQuests); } \
	FORCEINLINE static uint32 __PPO__ActiveQuest() { return STRUCT_OFFSET(UQuestManager, ActiveQuest); } \
	FORCEINLINE static uint32 __PPO__QuestBoardWidget() { return STRUCT_OFFSET(UQuestManager, QuestBoardWidget); }


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_15_PROLOG
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_RPC_WRAPPERS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_INCLASS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEM_API UClass* StaticClass<class UQuestManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
