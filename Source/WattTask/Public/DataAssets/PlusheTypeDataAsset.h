// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BehaviorTree/BehaviorTree.h"
#include "PlusheTypeDataAsset.generated.h"

enum class EPlusheBehaviorState : uint8;

UCLASS()
class WATTTASK_API UPlusheTypeDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:

    UPROPERTY(EditAnywhere)
    float MovementSpeed = 200.0f;

    UPROPERTY(EditAnywhere)
    float PerceptionRadius = 2000.0f;

    UPROPERTY(EditAnywhere)
    EPlusheBehaviorState BehaviorState;
};
