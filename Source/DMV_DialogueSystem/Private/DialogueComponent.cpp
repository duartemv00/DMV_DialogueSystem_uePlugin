// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueComponent.h"


UDialogueComponent::UDialogueComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}


void UDialogueComponent::BeginPlay()
{
	Super::BeginPlay();
}

