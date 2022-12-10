// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MEDIAWIDGET_MediaPlayerWidget_generated_h
#error "MediaPlayerWidget.generated.h already included, missing '#pragma once' in MediaPlayerWidget.h"
#endif
#define MEDIAWIDGET_MediaPlayerWidget_generated_h

#define Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_SPARSE_DATA
#define Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOpenMedia); \
	DECLARE_FUNCTION(execOpenPreviousFile); \
	DECLARE_FUNCTION(execOpenNextFile);


#define Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOpenMedia); \
	DECLARE_FUNCTION(execOpenPreviousFile); \
	DECLARE_FUNCTION(execOpenNextFile);


#define Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMediaPlayerWidget(); \
	friend struct Z_Construct_UClass_UMediaPlayerWidget_Statics; \
public: \
	DECLARE_CLASS(UMediaPlayerWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MediaWidget"), NO_API) \
	DECLARE_SERIALIZER(UMediaPlayerWidget)


#define Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUMediaPlayerWidget(); \
	friend struct Z_Construct_UClass_UMediaPlayerWidget_Statics; \
public: \
	DECLARE_CLASS(UMediaPlayerWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MediaWidget"), NO_API) \
	DECLARE_SERIALIZER(UMediaPlayerWidget)


#define Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMediaPlayerWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMediaPlayerWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMediaPlayerWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMediaPlayerWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMediaPlayerWidget(UMediaPlayerWidget&&); \
	NO_API UMediaPlayerWidget(const UMediaPlayerWidget&); \
public:


#define Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMediaPlayerWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMediaPlayerWidget(UMediaPlayerWidget&&); \
	NO_API UMediaPlayerWidget(const UMediaPlayerWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMediaPlayerWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMediaPlayerWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMediaPlayerWidget)


#define Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PlayerDisplay() { return STRUCT_OFFSET(UMediaPlayerWidget, PlayerDisplay); } \
	FORCEINLINE static uint32 __PPO__DynMaterial() { return STRUCT_OFFSET(UMediaPlayerWidget, DynMaterial); } \
	FORCEINLINE static uint32 __PPO__OpenFileButton() { return STRUCT_OFFSET(UMediaPlayerWidget, OpenFileButton); } \
	FORCEINLINE static uint32 __PPO__MediaPlayer() { return STRUCT_OFFSET(UMediaPlayerWidget, MediaPlayer); } \
	FORCEINLINE static uint32 __PPO__SoundActor() { return STRUCT_OFFSET(UMediaPlayerWidget, SoundActor); } \
	FORCEINLINE static uint32 __PPO__Sound() { return STRUCT_OFFSET(UMediaPlayerWidget, Sound); } \
	FORCEINLINE static uint32 __PPO__Images() { return STRUCT_OFFSET(UMediaPlayerWidget, Images); } \
	FORCEINLINE static uint32 __PPO__SelectedFileIndex() { return STRUCT_OFFSET(UMediaPlayerWidget, SelectedFileIndex); }


#define Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_16_PROLOG
#define Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_SPARSE_DATA \
	Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_RPC_WRAPPERS \
	Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_INCLASS \
	Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_PRIVATE_PROPERTY_OFFSET \
	Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_SPARSE_DATA \
	Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_INCLASS_NO_PURE_DECLS \
	Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MEDIAWIDGET_API UClass* StaticClass<class UMediaPlayerWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Homework_Plugins_MediaWidget_Source_MediaWidget_Public_MediaPlayerWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
