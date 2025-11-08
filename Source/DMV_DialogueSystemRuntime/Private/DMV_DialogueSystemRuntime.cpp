// Copyright Epic Games, Inc. All Rights Reserved.

#include "DMV_DialogueSystemRuntime.h"

#include "AssetToolsModule.h"
#include "IAssetTools.h"

#define LOCTEXT_NAMESPACE "FDMV_DialogueSystemModule"

void FDMV_DialogueSystemRuntimeModule::StartupModule()
{

}

void FDMV_DialogueSystemRuntimeModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDMV_DialogueSystemRuntimeModule, DMV_DialogueSystemRuntime)