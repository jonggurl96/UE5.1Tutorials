// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HowTo_AutoCamera/HowTo_AutoCameraGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHowTo_AutoCameraGameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	HOWTO_AUTOCAMERA_API UClass* Z_Construct_UClass_AHowTo_AutoCameraGameModeBase();
	HOWTO_AUTOCAMERA_API UClass* Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HowTo_AutoCamera();
// End Cross Module References
	void AHowTo_AutoCameraGameModeBase::StaticRegisterNativesAHowTo_AutoCameraGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHowTo_AutoCameraGameModeBase);
	UClass* Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_NoRegister()
	{
		return AHowTo_AutoCameraGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HowTo_AutoCamera,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "HowTo_AutoCameraGameModeBase.h" },
		{ "ModuleRelativePath", "HowTo_AutoCameraGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHowTo_AutoCameraGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::ClassParams = {
		&AHowTo_AutoCameraGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHowTo_AutoCameraGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AHowTo_AutoCameraGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHowTo_AutoCameraGameModeBase.OuterSingleton, Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AHowTo_AutoCameraGameModeBase.OuterSingleton;
	}
	template<> HOWTO_AUTOCAMERA_API UClass* StaticClass<AHowTo_AutoCameraGameModeBase>()
	{
		return AHowTo_AutoCameraGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHowTo_AutoCameraGameModeBase);
	AHowTo_AutoCameraGameModeBase::~AHowTo_AutoCameraGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_HowTo_AutoCameraGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_HowTo_AutoCameraGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AHowTo_AutoCameraGameModeBase, AHowTo_AutoCameraGameModeBase::StaticClass, TEXT("AHowTo_AutoCameraGameModeBase"), &Z_Registration_Info_UClass_AHowTo_AutoCameraGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHowTo_AutoCameraGameModeBase), 3708574599U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_HowTo_AutoCameraGameModeBase_h_1559708910(TEXT("/Script/HowTo_AutoCamera"),
		Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_HowTo_AutoCameraGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_HowTo_AutoCameraGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
