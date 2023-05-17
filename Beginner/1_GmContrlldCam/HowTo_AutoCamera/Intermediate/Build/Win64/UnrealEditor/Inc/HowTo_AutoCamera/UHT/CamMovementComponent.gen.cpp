// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HowTo_AutoCamera/Public/CamMovementComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCamMovementComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	HOWTO_AUTOCAMERA_API UClass* Z_Construct_UClass_UCamMovementComponent();
	HOWTO_AUTOCAMERA_API UClass* Z_Construct_UClass_UCamMovementComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HowTo_AutoCamera();
// End Cross Module References
	void UCamMovementComponent::StaticRegisterNativesUCamMovementComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCamMovementComponent);
	UClass* Z_Construct_UClass_UCamMovementComponent_NoRegister()
	{
		return UCamMovementComponent::StaticClass();
	}
	struct Z_Construct_UClass_UCamMovementComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Left_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Left;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Right_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Right;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCamMovementComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_HowTo_AutoCamera,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCamMovementComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "CamMovementComponent.h" },
		{ "ModuleRelativePath", "Public/CamMovementComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCamMovementComponent_Statics::NewProp_Left_MetaData[] = {
		{ "Category", "CamMovementComponent" },
		{ "ModuleRelativePath", "Public/CamMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCamMovementComponent_Statics::NewProp_Left = { "Left", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UCamMovementComponent, Left), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UCamMovementComponent_Statics::NewProp_Left_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCamMovementComponent_Statics::NewProp_Left_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCamMovementComponent_Statics::NewProp_Right_MetaData[] = {
		{ "Category", "CamMovementComponent" },
		{ "ModuleRelativePath", "Public/CamMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCamMovementComponent_Statics::NewProp_Right = { "Right", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UCamMovementComponent, Right), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UCamMovementComponent_Statics::NewProp_Right_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCamMovementComponent_Statics::NewProp_Right_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCamMovementComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCamMovementComponent_Statics::NewProp_Left,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCamMovementComponent_Statics::NewProp_Right,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCamMovementComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCamMovementComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCamMovementComponent_Statics::ClassParams = {
		&UCamMovementComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCamMovementComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCamMovementComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCamMovementComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCamMovementComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCamMovementComponent()
	{
		if (!Z_Registration_Info_UClass_UCamMovementComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCamMovementComponent.OuterSingleton, Z_Construct_UClass_UCamMovementComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCamMovementComponent.OuterSingleton;
	}
	template<> HOWTO_AUTOCAMERA_API UClass* StaticClass<UCamMovementComponent>()
	{
		return UCamMovementComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCamMovementComponent);
	UCamMovementComponent::~UCamMovementComponent() {}
	struct Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_Public_CamMovementComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_Public_CamMovementComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCamMovementComponent, UCamMovementComponent::StaticClass, TEXT("UCamMovementComponent"), &Z_Registration_Info_UClass_UCamMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCamMovementComponent), 74361869U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_Public_CamMovementComponent_h_1043256510(TEXT("/Script/HowTo_AutoCamera"),
		Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_Public_CamMovementComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_1_GmContrlldCam_HowTo_AutoCamera_Source_HowTo_AutoCamera_Public_CamMovementComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
