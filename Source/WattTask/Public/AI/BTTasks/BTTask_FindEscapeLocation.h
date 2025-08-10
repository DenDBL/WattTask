// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindEscapeLocation.generated.h"

/**
 * 
 */
UCLASS()
class WATTTASK_API UBTTask_FindEscapeLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
    UBTTask_FindEscapeLocation(FObjectInitializer const& ObjectInitializer);

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
    UPROPERTY(EditAnywhere)
    float EscapeDistance = 1000.0f;
};
