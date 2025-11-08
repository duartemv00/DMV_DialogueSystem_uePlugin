#include "DialogueAssetAction.h"
#include "DialogueAsset.h"
#include "DialogueAssetEditorApp.h"

DialogueAssetAction::DialogueAssetAction(EAssetTypeCategories::Type Category)
{
	_assetCategory = Category;
}

FText DialogueAssetAction::GetName() const
{
	return FText::FromString("Create New Quest"); // NSLOCT
}

FColor DialogueAssetAction::GetTypeColor() const
{
	return FColor::Red;
}

UClass* DialogueAssetAction::GetSupportedClass() const
{
	return UDialogueAsset::StaticClass();
}

uint32 DialogueAssetAction::GetCategories()
{
	return _assetCategory;
}

void DialogueAssetAction::OpenAssetEditor(const TArray<UObject*>& InObjects,
	TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	// FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
	EToolkitMode::Type mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;
	for (UObject* obj : InObjects)
	{
		UDialogueAsset* asset = Cast<UDialogueAsset>(obj);
		if (asset != nullptr)
		{
			TSharedRef<FDialogueAssetEditorApp> editor(new FDialogueAssetEditorApp());
			editor->InitEditor(mode, EditWithinLevelEditor, asset);
		}
	}
}
