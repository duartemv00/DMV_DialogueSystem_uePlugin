// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueComponent.generated.h"

/**
 * This is the component to add to any Actor that needs to have a dialogue.
 * From here the dialogue gets triggered.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DMV_DIALOGUESYSTEM_API UDialogueComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UDialogueComponent();

protected:
	virtual void BeginPlay() override;
};
