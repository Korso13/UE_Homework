// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MediaWidget/Public/MediaPlayerWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMediaPlayerWidget() {}
// Cross Module References
	MEDIAWIDGET_API UClass* Z_Construct_UClass_UMediaPlayerWidget_NoRegister();
	MEDIAWIDGET_API UClass* Z_Construct_UClass_UMediaPlayerWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_MediaWidget();
	UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	MEDIAASSETS_API UClass* Z_Construct_UClass_UMediaPlayer_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	MEDIAASSETS_API UClass* Z_Construct_UClass_UMediaSoundComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UMediaPlayerWidget::execOpenMedia)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OpenMedia();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMediaPlayerWidget::execOpenPreviousFile)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OpenPreviousFile();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMediaPlayerWidget::execOpenNextFile)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OpenNextFile();
		P_NATIVE_END;
	}
	void UMediaPlayerWidget::StaticRegisterNativesUMediaPlayerWidget()
	{
		UClass* Class = UMediaPlayerWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OpenMedia", &UMediaPlayerWidget::execOpenMedia },
			{ "OpenNextFile", &UMediaPlayerWidget::execOpenNextFile },
			{ "OpenPreviousFile", &UMediaPlayerWidget::execOpenPreviousFile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMediaPlayerWidget_OpenMedia_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMediaPlayerWidget_OpenMedia_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMediaPlayerWidget_OpenMedia_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMediaPlayerWidget, nullptr, "OpenMedia", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMediaPlayerWidget_OpenMedia_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMediaPlayerWidget_OpenMedia_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMediaPlayerWidget_OpenMedia()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMediaPlayerWidget_OpenMedia_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMediaPlayerWidget_OpenNextFile_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMediaPlayerWidget_OpenNextFile_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMediaPlayerWidget_OpenNextFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMediaPlayerWidget, nullptr, "OpenNextFile", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMediaPlayerWidget_OpenNextFile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMediaPlayerWidget_OpenNextFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMediaPlayerWidget_OpenNextFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMediaPlayerWidget_OpenNextFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMediaPlayerWidget_OpenPreviousFile_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMediaPlayerWidget_OpenPreviousFile_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMediaPlayerWidget_OpenPreviousFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMediaPlayerWidget, nullptr, "OpenPreviousFile", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMediaPlayerWidget_OpenPreviousFile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMediaPlayerWidget_OpenPreviousFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMediaPlayerWidget_OpenPreviousFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMediaPlayerWidget_OpenPreviousFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMediaPlayerWidget_NoRegister()
	{
		return UMediaPlayerWidget::StaticClass();
	}
	struct Z_Construct_UClass_UMediaPlayerWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerDisplay_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerDisplay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DynMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DynMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OpenFileButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OpenFileButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MediaPlayer_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MediaPlayer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoundActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SoundActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sound;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Images_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Images_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Images;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelectedFileIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_SelectedFileIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathToFile_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PathToFile;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MultipleFilesSelection_MetaData[];
#endif
		static void NewProp_MultipleFilesSelection_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_MultipleFilesSelection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SupportedFileTypes_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SupportedFileTypes;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMediaPlayerWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_MediaWidget,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMediaPlayerWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMediaPlayerWidget_OpenMedia, "OpenMedia" }, // 3178015392
		{ &Z_Construct_UFunction_UMediaPlayerWidget_OpenNextFile, "OpenNextFile" }, // 1229338590
		{ &Z_Construct_UFunction_UMediaPlayerWidget_OpenPreviousFile, "OpenPreviousFile" }, // 1645509064
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MediaPlayerWidget.h" },
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_PlayerDisplay_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "MediaPlayerWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_PlayerDisplay = { "PlayerDisplay", nullptr, (EPropertyFlags)0x002008000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMediaPlayerWidget, PlayerDisplay), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_PlayerDisplay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_PlayerDisplay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_DynMaterial_MetaData[] = {
		{ "Category", "MediaPlayerWidget" },
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_DynMaterial = { "DynMaterial", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMediaPlayerWidget, DynMaterial), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_DynMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_DynMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_OpenFileButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_OpenFileButton = { "OpenFileButton", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMediaPlayerWidget, OpenFileButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_OpenFileButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_OpenFileButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MediaPlayer_MetaData[] = {
		{ "Category", "MediaPlayerWidget" },
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MediaPlayer = { "MediaPlayer", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMediaPlayerWidget, MediaPlayer), Z_Construct_UClass_UMediaPlayer_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MediaPlayer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MediaPlayer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SoundActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SoundActor = { "SoundActor", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMediaPlayerWidget, SoundActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SoundActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SoundActor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Sound_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMediaPlayerWidget, Sound), Z_Construct_UClass_UMediaSoundComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Sound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Sound_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Images_Inner = { "Images", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Images_MetaData[] = {
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Images = { "Images", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMediaPlayerWidget, Images), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Images_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Images_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SelectedFileIndex_MetaData[] = {
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SelectedFileIndex = { "SelectedFileIndex", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMediaPlayerWidget, SelectedFileIndex), METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SelectedFileIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SelectedFileIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_PathToFile_MetaData[] = {
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_PathToFile = { "PathToFile", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMediaPlayerWidget, PathToFile), METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_PathToFile_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_PathToFile_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MultipleFilesSelection_MetaData[] = {
		{ "Category", "MediaPlayerWidget" },
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	void Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MultipleFilesSelection_SetBit(void* Obj)
	{
		((UMediaPlayerWidget*)Obj)->MultipleFilesSelection = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MultipleFilesSelection = { "MultipleFilesSelection", nullptr, (EPropertyFlags)0x0010000000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UMediaPlayerWidget), &Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MultipleFilesSelection_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MultipleFilesSelection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MultipleFilesSelection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SupportedFileTypes_MetaData[] = {
		{ "Category", "MediaPlayerWidget" },
		{ "ModuleRelativePath", "Public/MediaPlayerWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SupportedFileTypes = { "SupportedFileTypes", nullptr, (EPropertyFlags)0x0010000000010005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMediaPlayerWidget, SupportedFileTypes), METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SupportedFileTypes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SupportedFileTypes_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMediaPlayerWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_PlayerDisplay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_DynMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_OpenFileButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MediaPlayer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SoundActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Sound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Images_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_Images,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SelectedFileIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_PathToFile,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_MultipleFilesSelection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMediaPlayerWidget_Statics::NewProp_SupportedFileTypes,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMediaPlayerWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMediaPlayerWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMediaPlayerWidget_Statics::ClassParams = {
		&UMediaPlayerWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMediaPlayerWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMediaPlayerWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMediaPlayerWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMediaPlayerWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMediaPlayerWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMediaPlayerWidget, 1218056872);
	template<> MEDIAWIDGET_API UClass* StaticClass<UMediaPlayerWidget>()
	{
		return UMediaPlayerWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMediaPlayerWidget(Z_Construct_UClass_UMediaPlayerWidget, &UMediaPlayerWidget::StaticClass, TEXT("/Script/MediaWidget"), TEXT("UMediaPlayerWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMediaPlayerWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
