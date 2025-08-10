// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindHomeLocation.generated.h"

/**
 * 
 */
UCLASS()
class WATTTASK_API UBTTask_FindHomeLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:

	UBTTask_FindHomeLocation(FObjectInitializer const& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
