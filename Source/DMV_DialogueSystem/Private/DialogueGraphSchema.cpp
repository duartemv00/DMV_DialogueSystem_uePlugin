// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueGraphSchema.h"

void UDialogueGraphSchema::GetGraphContextActions(
	FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	// Super::GetGraphContextActions(ContextMenuBuilder);

	TSharedPtr<FEdGraphSchemaAction> NewNodeAction = MakeShareable(
		new FEdGraphSchemaAction(
			FText::FromString("Dialogue"),
			FText::FromString("Add Dialogue Node"),
			FText::FromString("Creates a new dialogue node"),
			0
		)
	);

	ContextMenuBuilder.AddAction(NewNodeAction);
}

const FPinConnectionResponse UDialogueGraphSchema::CanCreateConnection(
	const UEdGraphPin* A, const UEdGraphPin* B) const
{
	if (A->GetOwningNode() == B->GetOwningNode())
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Cannot connect to self."));
	return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT(""));
	// return Super::CanCreateConnection(A, B);
}
