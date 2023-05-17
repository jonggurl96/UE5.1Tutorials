// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HowTo_AutoCamera/Public/MovingCamDirector.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovingCamDirector() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	HOWTO_AUTOCAMERA_API UClass* Z_Construct_UClass_AMovingCamDirector();
	HOWTO_AUTOCAMERA_API UClass* Z_Construct_UClass_AMovingCamDirector_NoRegister();
	HOWTO_AUTOCAMERA_API UClass* Z_Construct_UClass_UCamMovementComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HowTo_AutoCamera();
// End Cross Module References
	void AMovingCamDirector::StaticRegisterNativesAMovingCamDirector()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMovingCamDirector);
	UClass* Z_Construct_UClass_AMovingCamDirector_NoRegister()
	{
		return AMovingCamDirector::StaticClass();
	}
	struct Z_Construct_UClass_AMovingCamDirector_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CamMovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CamMovementComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMovingCamDirector_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_HowTo_AutoCamera,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingCamDirector_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MovingCamDirector.h" },
		{ "ModuleRelativePath", "Public/MovingCamDirector.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_SpringArm_MetaData[] = {
		{ "Category", "MovingCamDirector" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MovingCamDirector.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AMovingCamDirector, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_SpringArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_SpringArm_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_Camera_MetaData[] = {
		{ "Category", "MovingCamDirector" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MovingCamDirector.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AMovingCamDirector, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_Camera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_Camera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_CamMovementComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MovingCamDirector.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_CamMovementComponent = { "CamMovementComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AMovingCamDirector, CamMovementComponent), Z_Construct_UClass_UCamMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_CamMovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_CamMovementComponent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMovingCamDirector_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_SpringArm,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_Camera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingCamDirector_Statics::NewProp_CamMovementComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMovingCamDirector_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMovingCamDirector>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMovingCamDirector_Statics::ClassParams = {
		&AMovingCamDirector::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMovingCamDirector_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMovingCamDirector_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMovingCamDirector_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingCamDirector_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMovingCamDirector()
	{
		if (!Z_Registration_Info_UClass_AMovingCamDirector.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMovingCamDirector.OuterSingleton, Z_Construct_UClass_AMovingCamDirector_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMovingCamDirector.OuterSingleton;
	}
	template<> HOWTO_AUTOCAMERA_API UClass* StaticClass<AMovingCamDirector>()
	{
		return AMovingCamDirector::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMovingCamDirector);
	AMovingCamDirector::~AMovingCamDirector() {}
	struct Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_Public_MovingCamDirector_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_Public_MovingCamDirector_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMovingCamDirector, AMovingCamDirector::StaticClass, TEXT("AMovingCamDirector"), &Z_Registration_Info_UClass_AMovingCamDirector, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMovingCamDirector), 604928123U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_Public_MovingCamDirector_h_3788888584(TEXT("/Script/HowTo_AutoCamera"),
		Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_Public_MovingCamDirector_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_Public_MovingCamDirector_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
