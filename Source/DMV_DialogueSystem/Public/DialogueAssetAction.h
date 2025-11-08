#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class DialogueAssetAction : public FAssetTypeActions_Base
{
public:
	DialogueAssetAction(EAssetTypeCategories::Type Category);

public: // FAssetTypeActions_Base interface
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	virtual void OpenAssetEditor(
		const TArray<UObject*>& InObjects,
		TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
	
private:
	EAssetTypeCategories::Type _assetCategory;
	
};