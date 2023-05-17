// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FPSProject/FPSProjectGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPSProjectGameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	FPSPROJECT_API UClass* Z_Construct_UClass_AFPSProjectGameModeBase();
	FPSPROJECT_API UClass* Z_Construct_UClass_AFPSProjectGameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FPSProject();
// End Cross Module References
	void AFPSProjectGameModeBase::StaticRegisterNativesAFPSProjectGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFPSProjectGameModeBase);
	UClass* Z_Construct_UClass_AFPSProjectGameModeBase_NoRegister()
	{
		return AFPSProjectGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AFPSProjectGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFPSProjectGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FPSProject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSProjectGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "FPSProjectGameModeBase.h" },
		{ "ModuleRelativePath", "FPSProjectGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFPSProjectGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPSProjectGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFPSProjectGameModeBase_Statics::ClassParams = {
		&AFPSProjectGameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AFPSProjectGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFPSProjectGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFPSProjectGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AFPSProjectGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFPSProjectGameModeBase.OuterSingleton, Z_Construct_UClass_AFPSProjectGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFPSProjectGameModeBase.OuterSingleton;
	}
	template<> FPSPROJECT_API UClass* StaticClass<AFPSProjectGameModeBase>()
	{
		return AFPSProjectGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPSProjectGameModeBase);
	AFPSProjectGameModeBase::~AFPSProjectGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_3_FPS_FPSProject_Source_FPSProject_FPSProjectGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_3_FPS_FPSProject_Source_FPSProject_FPSProjectGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFPSProjectGameModeBase, AFPSProjectGameModeBase::StaticClass, TEXT("AFPSProjectGameModeBase"), &Z_Registration_Info_UClass_AFPSProjectGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFPSProjectGameModeBase), 118626942U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_3_FPS_FPSProject_Source_FPSProject_FPSProjectGameModeBase_h_254107696(TEXT("/Script/FPSProject"),
		Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_3_FPS_FPSProject_Source_FPSProject_FPSProjectGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_3_FPS_FPSProject_Source_FPSProject_FPSProjectGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
