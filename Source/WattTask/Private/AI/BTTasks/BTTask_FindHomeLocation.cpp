// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTasks/BTTask_FindHomeLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include "AIController.h"
#include "Actors/BasePlushe.h"

UBTTask_FindHomeLocation::UBTTask_FindHomeLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Find Home Location";
}

EBTNodeResult::Type UBTTask_FindHomeLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	if (ABasePlushe* Plushe = Cast<ABasePlushe>(OwnerComp.GetAIOwner()->GetPawn()))
		{
				FNavLocation PlayerLocation;

				OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Plushe->GetInitialLocation());
				return EBTNodeResult::Succeeded;
		}

	return EBTNodeResult::Failed;
}
