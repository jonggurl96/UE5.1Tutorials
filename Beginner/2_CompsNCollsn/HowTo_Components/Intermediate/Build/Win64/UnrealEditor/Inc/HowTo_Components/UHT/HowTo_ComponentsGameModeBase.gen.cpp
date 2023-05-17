// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HowTo_Components/HowTo_ComponentsGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHowTo_ComponentsGameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	HOWTO_COMPONENTS_API UClass* Z_Construct_UClass_AHowTo_ComponentsGameModeBase();
	HOWTO_COMPONENTS_API UClass* Z_Construct_UClass_AHowTo_ComponentsGameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HowTo_Components();
// End Cross Module References
	void AHowTo_ComponentsGameModeBase::StaticRegisterNativesAHowTo_ComponentsGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHowTo_ComponentsGameModeBase);
	UClass* Z_Construct_UClass_AHowTo_ComponentsGameModeBase_NoRegister()
	{
		return AHowTo_ComponentsGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AHowTo_ComponentsGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHowTo_ComponentsGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HowTo_Components,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHowTo_ComponentsGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "HowTo_ComponentsGameModeBase.h" },
		{ "ModuleRelativePath", "HowTo_ComponentsGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHowTo_ComponentsGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHowTo_ComponentsGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AHowTo_ComponentsGameModeBase_Statics::ClassParams = {
		&AHowTo_ComponentsGameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AHowTo_ComponentsGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHowTo_ComponentsGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHowTo_ComponentsGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AHowTo_ComponentsGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHowTo_ComponentsGameModeBase.OuterSingleton, Z_Construct_UClass_AHowTo_ComponentsGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AHowTo_ComponentsGameModeBase.OuterSingleton;
	}
	template<> HOWTO_COMPONENTS_API UClass* StaticClass<AHowTo_ComponentsGameModeBase>()
	{
		return AHowTo_ComponentsGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHowTo_ComponentsGameModeBase);
	AHowTo_ComponentsGameModeBase::~AHowTo_ComponentsGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_2_CompsNCollsn_HowTo_Components_Source_HowTo_Components_HowTo_ComponentsGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_2_CompsNCollsn_HowTo_Components_Source_HowTo_Components_HowTo_ComponentsGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AHowTo_ComponentsGameModeBase, AHowTo_ComponentsGameModeBase::StaticClass, TEXT("AHowTo_ComponentsGameModeBase"), &Z_Registration_Info_UClass_AHowTo_ComponentsGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHowTo_ComponentsGameModeBase), 3377117497U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_2_CompsNCollsn_HowTo_Components_Source_HowTo_Components_HowTo_ComponentsGameModeBase_h_1647220995(TEXT("/Script/HowTo_Components"),
		Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_2_CompsNCollsn_HowTo_Components_Source_HowTo_Components_HowTo_ComponentsGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_2_CompsNCollsn_HowTo_Components_Source_HowTo_Components_HowTo_ComponentsGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
