// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueGraphNode.h"

FText UDialogueGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return DialogueText.IsEmpty() ? FText::FromString("Dialogue Node") : DialogueText;
}
