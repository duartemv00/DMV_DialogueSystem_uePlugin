// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "DialogueGraphSchema.generated.h"

/**
 * 
 */
UCLASS()
class DMV_DIALOGUESYSTEM_API UDialogueGraphSchema : public UEdGraphSchema
{
	GENERATED_BODY()

public:
	virtual void GetGraphContextActions(
		FGraphContextMenuBuilder& ContextMenuBuilder) const override;
	virtual const FPinConnectionResponse CanCreateConnection(
		const UEdGraphPin* A, const UEdGraphPin* B) const override;
};
