// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GaCha7Equipe4/GaCha7Equipe4GameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGaCha7Equipe4GameModeBase() {}
// Cross Module References
	GACHA7EQUIPE4_API UClass* Z_Construct_UClass_AGaCha7Equipe4GameModeBase_NoRegister();
	GACHA7EQUIPE4_API UClass* Z_Construct_UClass_AGaCha7Equipe4GameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_GaCha7Equipe4();
// End Cross Module References
	void AGaCha7Equipe4GameModeBase::StaticRegisterNativesAGaCha7Equipe4GameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGaCha7Equipe4GameModeBase);
	UClass* Z_Construct_UClass_AGaCha7Equipe4GameModeBase_NoRegister()
	{
		return AGaCha7Equipe4GameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AGaCha7Equipe4GameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGaCha7Equipe4GameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GaCha7Equipe4,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGaCha7Equipe4GameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GaCha7Equipe4GameModeBase.h" },
		{ "ModuleRelativePath", "GaCha7Equipe4GameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGaCha7Equipe4GameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGaCha7Equipe4GameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGaCha7Equipe4GameModeBase_Statics::ClassParams = {
		&AGaCha7Equipe4GameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AGaCha7Equipe4GameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGaCha7Equipe4GameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGaCha7Equipe4GameModeBase()
	{
		if (!Z_Registration_Info_UClass_AGaCha7Equipe4GameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGaCha7Equipe4GameModeBase.OuterSingleton, Z_Construct_UClass_AGaCha7Equipe4GameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGaCha7Equipe4GameModeBase.OuterSingleton;
	}
	template<> GACHA7EQUIPE4_API UClass* StaticClass<AGaCha7Equipe4GameModeBase>()
	{
		return AGaCha7Equipe4GameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGaCha7Equipe4GameModeBase);
	struct Z_CompiledInDeferFile_FID_GaCha7Equipe4_Source_GaCha7Equipe4_GaCha7Equipe4GameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GaCha7Equipe4_Source_GaCha7Equipe4_GaCha7Equipe4GameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGaCha7Equipe4GameModeBase, AGaCha7Equipe4GameModeBase::StaticClass, TEXT("AGaCha7Equipe4GameModeBase"), &Z_Registration_Info_UClass_AGaCha7Equipe4GameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGaCha7Equipe4GameModeBase), 3252662976U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GaCha7Equipe4_Source_GaCha7Equipe4_GaCha7Equipe4GameModeBase_h_3007669609(TEXT("/Script/GaCha7Equipe4"),
		Z_CompiledInDeferFile_FID_GaCha7Equipe4_Source_GaCha7Equipe4_GaCha7Equipe4GameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GaCha7Equipe4_Source_GaCha7Equipe4_GaCha7Equipe4GameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
