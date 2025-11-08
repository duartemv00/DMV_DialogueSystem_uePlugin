#include "DialogueAssetFactory.h"
#include "DialogueAsset.h"

UDialogueAssetFactory::UDialogueAssetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UDialogueAsset::StaticClass();
}

UObject* UDialogueAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
                                               UObject* Context, FFeedbackContext* Warn)
{
	UDialogueAsset* NewAsset = NewObject<UDialogueAsset>(InParent, Class, Name, Flags);
	return NewAsset;
}

bool UDialogueAssetFactory::CanCreateNew() const
{
	return true;
}
