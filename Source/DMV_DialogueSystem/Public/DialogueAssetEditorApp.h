#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowCentricApplication.h"

class FDialogueAssetEditorApp : public FWorkflowCentricApplication, public FEditorUndoClient, public FNotifyHook
{
public:
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;
	void InitEditor(const EToolkitMode::Type mode,
		const TSharedPtr<class IToolkitHost>& initToolkitHost, UObject* inObject);

	class UDialogueAsset* GetWorkingAsset() { return _workingAsset; }

public: // FAssetEditorToolkit interface
	virtual FName GetToolkitFName() const override
	{
		return FName("DialogueAssetEditor");
	}
	virtual FText GetBaseToolkitName() const override
	{
		return NSLOCTEXT("DialogueAssetEditor", "AppLabel", "Dialogue Asset Editor");
	}
	virtual FString GetWorldCentricTabPrefix() const override
	{
		return TEXT("DialogueAssetEditor");
	}
	virtual FLinearColor GetWorldCentricTabColorScale() const override
	{
		return FLinearColor(.3,.2,.15,.5);
	}
	virtual FString GetDocumentationLink() const override
	{
		return TEXT("https://github.com/duartemv");
	}
	virtual void OnToolkitHostingStarted(const TSharedRef<IToolkit>& Toolkit) override { }
	virtual void OnToolkitHostingFinished(const TSharedRef<IToolkit>& Toolkit) override { }

private:
	UPROPERTY()
	class UDialogueAsset* _workingAsset = nullptr;
};