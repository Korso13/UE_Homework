// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AQuest;
#ifdef QUESTSYSTEM_QuestBoard_generated_h
#error "QuestBoard.generated.h already included, missing '#pragma once' in QuestBoard.h"
#endif
#define QUESTSYSTEM_QuestBoard_generated_h

#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_SPARSE_DATA
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPickQuestForViewer);


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPickQuestForViewer);


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuestBoard(); \
	friend struct Z_Construct_UClass_UQuestBoard_Statics; \
public: \
	DECLARE_CLASS(UQuestBoard, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UQuestBoard)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUQuestBoard(); \
	friend struct Z_Construct_UClass_UQuestBoard_Statics; \
public: \
	DECLARE_CLASS(UQuestBoard, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UQuestBoard)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestBoard(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestBoard) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestBoard); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestBoard); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestBoard(UQuestBoard&&); \
	NO_API UQuestBoard(const UQuestBoard&); \
public:


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestBoard(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestBoard(UQuestBoard&&); \
	NO_API UQuestBoard(const UQuestBoard&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestBoard); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestBoard); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestBoard)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__QuestListEntryClass() { return STRUCT_OFFSET(UQuestBoard, QuestListEntryClass); } \
	FORCEINLINE static uint32 __PPO__MainQuestsList() { return STRUCT_OFFSET(UQuestBoard, MainQuestsList); } \
	FORCEINLINE static uint32 __PPO__SideQuestsList() { return STRUCT_OFFSET(UQuestBoard, SideQuestsList); } \
	FORCEINLINE static uint32 __PPO__QuestDescription() { return STRUCT_OFFSET(UQuestBoard, QuestDescription); } \
	FORCEINLINE static uint32 __PPO__QuestManager() { return STRUCT_OFFSET(UQuestBoard, QuestManager); }


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_20_PROLOG
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_RPC_WRAPPERS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_INCLASS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEM_API UClass* StaticClass<class UQuestBoard>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestBoard_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
