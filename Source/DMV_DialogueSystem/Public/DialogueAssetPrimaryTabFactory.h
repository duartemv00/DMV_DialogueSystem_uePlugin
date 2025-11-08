#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FDialogueAssetPrimaryTabFactory : public FWorkflowTabFactory
{
public:
	FDialogueAssetPrimaryTabFactory(TSharedPtr<class FDialogueAssetEditorApp> app);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

private:
	TWeakPtr<class FDialogueAssetEditorApp> _app;
};