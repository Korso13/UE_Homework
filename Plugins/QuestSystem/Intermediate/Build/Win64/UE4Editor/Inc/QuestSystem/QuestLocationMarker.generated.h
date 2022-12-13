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
#ifdef QUESTSYSTEM_QuestLocationMarker_generated_h
#error "QuestLocationMarker.generated.h already included, missing '#pragma once' in QuestLocationMarker.h"
#endif
#define QUESTSYSTEM_QuestLocationMarker_generated_h

#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_SPARSE_DATA
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnCompBeginOverlap);


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnCompBeginOverlap);


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAQuestLocationMarker(); \
	friend struct Z_Construct_UClass_AQuestLocationMarker_Statics; \
public: \
	DECLARE_CLASS(AQuestLocationMarker, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(AQuestLocationMarker)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAQuestLocationMarker(); \
	friend struct Z_Construct_UClass_AQuestLocationMarker_Statics; \
public: \
	DECLARE_CLASS(AQuestLocationMarker, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/QuestSystem"), NO_API) \
	DECLARE_SERIALIZER(AQuestLocationMarker)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AQuestLocationMarker(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AQuestLocationMarker) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AQuestLocationMarker); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AQuestLocationMarker); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AQuestLocationMarker(AQuestLocationMarker&&); \
	NO_API AQuestLocationMarker(const AQuestLocationMarker&); \
public:


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AQuestLocationMarker(AQuestLocationMarker&&); \
	NO_API AQuestLocationMarker(const AQuestLocationMarker&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AQuestLocationMarker); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AQuestLocationMarker); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AQuestLocationMarker)


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__DetectionCube() { return STRUCT_OFFSET(AQuestLocationMarker, DetectionCube); }


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_13_PROLOG
#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_RPC_WRAPPERS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_INCLASS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_SPARSE_DATA \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEM_API UClass* StaticClass<class AQuestLocationMarker>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_QuestSystem_Source_QuestSystem_Public_QuestLocationMarker_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
