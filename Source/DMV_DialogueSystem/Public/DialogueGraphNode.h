// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "DialogueGraphNode.generated.h"

/**
 * 
 */
UCLASS()
class DMV_DIALOGUESYSTEM_API UDialogueGraphNode : public UEdGraphNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Dialogue")
	FText DialogueText;

	UPROPERTY(EditAnywhere, Category="Dialogue")
	bool bIsPlayerChoice = false;

	// Link to runtime data if needed
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
};
