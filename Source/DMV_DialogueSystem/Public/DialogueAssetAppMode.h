#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FDialogueAssetAppMode : public FApplicationMode
{
public:
	FDialogueAssetAppMode(TSharedPtr<class FDialogueAssetEditorApp> app);

	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PreDeactivateMode() override;
	virtual void PostActivateMode() override;

private:
	TWeakPtr<class FDialogueAssetEditorApp> _app;
	FWorkflowAllowedTabSet _tabs; // Tab factories associated with this mode
};