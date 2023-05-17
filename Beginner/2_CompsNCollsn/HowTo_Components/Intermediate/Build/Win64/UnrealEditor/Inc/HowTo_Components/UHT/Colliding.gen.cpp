// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HowTo_Components/Public/Base/Colliding.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeColliding() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
	HOWTO_COMPONENTS_API UClass* Z_Construct_UClass_AColliding();
	HOWTO_COMPONENTS_API UClass* Z_Construct_UClass_AColliding_NoRegister();
	HOWTO_COMPONENTS_API UClass* Z_Construct_UClass_UCollidingPawnMovementComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HowTo_Components();
// End Cross Module References
	void AColliding::StaticRegisterNativesAColliding()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AColliding);
	UClass* Z_Construct_UClass_AColliding_NoRegister()
	{
		return AColliding::StaticClass();
	}
	struct Z_Construct_UClass_AColliding_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OurParticleSystem_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OurParticleSystem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OurMovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OurMovementComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AColliding_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_HowTo_Components,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AColliding_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Base/Colliding.h" },
		{ "ModuleRelativePath", "Public/Base/Colliding.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AColliding_Statics::NewProp_OurParticleSystem_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Base/Colliding.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AColliding_Statics::NewProp_OurParticleSystem = { "OurParticleSystem", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AColliding, OurParticleSystem), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AColliding_Statics::NewProp_OurParticleSystem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AColliding_Statics::NewProp_OurParticleSystem_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AColliding_Statics::NewProp_OurMovementComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Base/Colliding.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AColliding_Statics::NewProp_OurMovementComponent = { "OurMovementComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AColliding, OurMovementComponent), Z_Construct_UClass_UCollidingPawnMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AColliding_Statics::NewProp_OurMovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AColliding_Statics::NewProp_OurMovementComponent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AColliding_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AColliding_Statics::NewProp_OurParticleSystem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AColliding_Statics::NewProp_OurMovementComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AColliding_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AColliding>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AColliding_Statics::ClassParams = {
		&AColliding::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AColliding_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AColliding_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AColliding_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AColliding_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AColliding()
	{
		if (!Z_Registration_Info_UClass_AColliding.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AColliding.OuterSingleton, Z_Construct_UClass_AColliding_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AColliding.OuterSingleton;
	}
	template<> HOWTO_COMPONENTS_API UClass* StaticClass<AColliding>()
	{
		return AColliding::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AColliding);
	AColliding::~AColliding() {}
	struct Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_2_CompsNCollsn_HowTo_Components_Source_HowTo_Components_Public_Base_Colliding_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_2_CompsNCollsn_HowTo_Components_Source_HowTo_Components_Public_Base_Colliding_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AColliding, AColliding::StaticClass, TEXT("AColliding"), &Z_Registration_Info_UClass_AColliding, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AColliding), 1330644836U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_2_CompsNCollsn_HowTo_Components_Source_HowTo_Components_Public_Base_Colliding_h_1690888799(TEXT("/Script/HowTo_Components"),
		Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_2_CompsNCollsn_HowTo_Components_Source_HowTo_Components_Public_Base_Colliding_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jongg_Desktop_UE5_workspace_UE5_1Tutorials_Beginner_2_CompsNCollsn_HowTo_Components_Source_HowTo_Components_Public_Base_Colliding_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
