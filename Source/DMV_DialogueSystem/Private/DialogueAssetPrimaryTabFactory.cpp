#include "DialogueAssetPrimaryTabFactory.h"
#include "DialogueAssetEditorApp.h"
#include "DialogueAsset.h"
#include "IDetailsView.h"
#include "PropertyEditorModule.h"
#include "Elements/Common/TypedElementCommonTypes.h"

FDialogueAssetPrimaryTabFactory::FDialogueAssetPrimaryTabFactory(TSharedPtr<class FDialogueAssetEditorApp> app) :
	FWorkflowTabFactory(FName("DialogueAssetPrimaryTab"), app)
{
	_app = app;
	TabLabel = FText::FromString("Primary");
	ViewMenuDescription = FText::FromString("Primary");
	ViewMenuTooltip = FText::FromString("Primary");
}

TSharedRef<SWidget> FDialogueAssetPrimaryTabFactory::CreateTabBody(const FWorkflowTabSpawnInfo& info) const
{
	TSharedPtr<FDialogueAssetEditorApp> app = _app.Pin();
	FPropertyEditorModule& propertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	FDetailsViewArgs detailsViewArgs;
	{
		detailsViewArgs.bAllowSearch = false;
		detailsViewArgs.bHideSelectionTip = true;
		detailsViewArgs.bLockable = false;
		detailsViewArgs.bSearchInitialKeyFocus = true;
		detailsViewArgs.bUpdatesFromSelection = false;
		detailsViewArgs.NotifyHook = nullptr;
		detailsViewArgs.bShowOptions = true;
		detailsViewArgs.bShowModifiedPropertiesOption = false;
		detailsViewArgs.bShowScrollBar = false;
	}

	TSharedPtr<IDetailsView> detailsView = propertyModule.CreateDetailView(detailsViewArgs);
	detailsView->SetObject(app->GetWorkingAsset());

	return SNew(SVerticalBox) + SVerticalBox::Slot().FillHeight(1.0f).HAlign(HAlign_Fill)
		[
			detailsView.ToSharedRef()
		];
}

FText FDialogueAssetPrimaryTabFactory::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FText::FromString("Primary");
}
