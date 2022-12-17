// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef QUESTSYSTEM_QuestDialogueWidget_generated_h
#error "QuestDialogueWidget.generated.h already included, missing '#pragma once' in QuestDialogueWidget.h"
#endif
#define QUESTSYSTEM_QuestDialogueWidget_generated_h

#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_SPARSE_DATA
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnRejected); \
	DECLARE_FUNCTION(execOnAccepted);


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRejected); \
	DECLARE_FUNCTION(execOnAccepted);


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuestDialogueWidget(); \
	friend struct Z_Construct_UClass_UQuestDialogueWidget_Statics; \
public: \
	DECLARE_CLASS(UQuestDialogueWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UQuestDialogueWidget)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUQuestDialogueWidget(); \
	friend struct Z_Construct_UClass_UQuestDialogueWidget_Statics; \
public: \
	DECLARE_CLASS(UQuestDialogueWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UQuestDialogueWidget)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestDialogueWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestDialogueWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestDialogueWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestDialogueWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestDialogueWidget(UQuestDialogueWidget&&); \
	NO_API UQuestDialogueWidget(const UQuestDialogueWidget&); \
public:


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestDialogueWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestDialogueWidget(UQuestDialogueWidget&&); \
	NO_API UQuestDialogueWidget(const UQuestDialogueWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestDialogueWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestDialogueWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestDialogueWidget)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__AcceptButton() { return STRUCT_OFFSET(UQuestDialogueWidget, AcceptButton); } \
	FORCEINLINE static uint32 __PPO__RejectButton() { return STRUCT_OFFSET(UQuestDialogueWidget, RejectButton); } \
	FORCEINLINE static uint32 __PPO__QuestDescription() { return STRUCT_OFFSET(UQuestDialogueWidget, QuestDescription); } \
	FORCEINLINE static uint32 __PPO__bDisableMouseCursorOnDialogeEnd() { return STRUCT_OFFSET(UQuestDialogueWidget, bDisableMouseCursorOnDialogeEnd); }


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_16_PROLOG
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_RPC_WRAPPERS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_INCLASS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEM_API UClass* StaticClass<class UQuestDialogueWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestDialogueWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
