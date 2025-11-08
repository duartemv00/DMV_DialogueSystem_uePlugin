#include "DialogueAssetEditorApp.h"
#include "DialogueAsset.h"
#include "DialogueAssetAppMode.h"

void FDialogueAssetEditorApp::RegisterTabSpawners(const TSharedRef<FTabManager>& tabManager)
{
	FWorkflowCentricApplication::RegisterTabSpawners(tabManager);
}

void FDialogueAssetEditorApp::InitEditor(const EToolkitMode::Type mode,
	const TSharedPtr<class IToolkitHost>& initToolkitHost, UObject* inObject)
{
	TArray<UObject*> objectsToEdit;
	objectsToEdit.Add(inObject);

	_workingAsset = Cast<UDialogueAsset>(inObject);

	InitAssetEditor(
		mode,
		initToolkitHost,
		TEXT("DialogueAssetEditor"),
		FTabManager::FLayout::NullLayout,
		true, // create standalone menu
		true, // create default toolbar
		objectsToEdit
	);

	AddApplicationMode(TEXT("DialogueAssetAppMode"), MakeShareable(new FDialogueAssetAppMode(SharedThis(this))));
	SetCurrentMode(TEXT("DialogueAssetAppMode"));
}
