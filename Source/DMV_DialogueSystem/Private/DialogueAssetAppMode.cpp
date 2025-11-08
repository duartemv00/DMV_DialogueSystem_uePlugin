#include "DialogueAssetAppMode.h"
#include "DialogueAssetEditorApp.h"
#include "DialogueAssetPrimaryTabFactory.h"

FDialogueAssetAppMode::FDialogueAssetAppMode(TSharedPtr<class FDialogueAssetEditorApp> app) : FApplicationMode(TEXT("DialogueAssetAppMode"))
{
	_app = app;
	_tabs.RegisterFactory(MakeShareable(new FDialogueAssetPrimaryTabFactory(app)));

	TabLayout = FTabManager::NewLayout("DialogueAssetAppMode_Layout_v1")
	->AddArea
	(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
		->Split
		(
			FTabManager::NewStack()->AddTab(FName(TEXT("DialogueAssetPrimaryTab")), ETabState::OpenedTab)
		)
	);
}

void FDialogueAssetAppMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	TSharedPtr<FDialogueAssetEditorApp> app = _app.Pin();
	app->PushTabFactories(_tabs);
	FApplicationMode::RegisterTabFactories(InTabManager);
}

void FDialogueAssetAppMode::PreDeactivateMode()
{
	FApplicationMode::PreDeactivateMode();
}

void FDialogueAssetAppMode::PostActivateMode()
{
	FApplicationMode::PostActivateMode();
}
