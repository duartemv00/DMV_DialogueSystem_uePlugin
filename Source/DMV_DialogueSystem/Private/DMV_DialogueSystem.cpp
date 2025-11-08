// Copyright Epic Games, Inc. All Rights Reserved.

#include "DMV_DialogueSystem.h"
#include "AssetToolsModule.h"
#include "DialogueAssetAction.h"
#include "IAssetTools.h"


#define LOCTEXT_NAMESPACE "FDMV_DialogueSystemModule"

void FDMV_DialogueSystemModule::StartupModule()
{
	//IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	//AssetTools.RegisterAssetTypeActions(MakeShareable(new FDialogueGraphAssetTypeActions()))
	
	IAssetTools& assetToolsModule = IAssetTools::Get();
	EAssetTypeCategories::Type assetType = assetToolsModule.RegisterAdvancedAssetCategory(FName(TEXT("DMVQuestSystem")),
		FText::FromString("DMV Quest System"));
	TSharedPtr<DialogueAssetAction> customAssetAction = MakeShareable(new DialogueAssetAction(assetType));
	assetToolsModule.RegisterAssetTypeActions(customAssetAction.ToSharedRef());
}

void FDMV_DialogueSystemModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDMV_DialogueSystemModule, DMV_DialogueSystem)