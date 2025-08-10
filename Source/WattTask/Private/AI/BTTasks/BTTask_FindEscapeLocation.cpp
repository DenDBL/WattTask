// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/BTTasks/BTTask_FindEscapeLocation.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FindEscapeLocation::UBTTask_FindEscapeLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Find Escape Location";
}

EBTNodeResult::Type UBTTask_FindEscapeLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	if (const auto* AAIController = OwnerComp.GetAIOwner())
	{
		if (const auto* Pawn = AAIController->GetPawn())
		{
			const FVector PawnLoc = Pawn->GetActorLocation();
			const FVector PlayerLoc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
			
			if (const auto* NavSys = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				FVector Direction = PawnLoc - PlayerLoc;
				Direction.Normalize();

				FVector EscapeLocation = PawnLoc + Direction * EscapeDistance;

				OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), EscapeLocation);
				return EBTNodeResult::Succeeded;
			}

		}
	}

	return EBTNodeResult::Failed;
}
