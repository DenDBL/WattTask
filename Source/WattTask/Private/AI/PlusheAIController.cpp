// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/PlusheAIController.h"
#include "Actors/BasePlushe.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"

APlusheAIController::APlusheAIController(FObjectInitializer const& ObjectInitializer) : Super(ObjectInitializer)
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception Component"));

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	PerceptionComponent->ConfigureSense(*SightConfig);

	PerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());

}

void APlusheAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (ABasePlushe* const PossessedPlushe = Cast<ABasePlushe>(InPawn))
	{
		PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(PossessedPlushe, &ABasePlushe::OnTargetPerceptionUpdated);

		if (UBehaviorTree* const BehaviorTree = PossessedPlushe->GetBehaviorTree())
		{
			UBlackboardComponent* BlackboardComponent;
			UseBlackboard(BehaviorTree->BlackboardAsset, BlackboardComponent);
			Blackboard = BlackboardComponent;
			RunBehaviorTree(BehaviorTree);
		}
	}
}

void APlusheAIController::SetEnemy(AActor* InPawn)
{
	Blackboard->SetValueAsObject("Enemy", InPawn);
}

void APlusheAIController::SetMaster(AActor* InPawn)
{
	Blackboard->SetValueAsObject("Master", InPawn);
}

void APlusheAIController::SetHomeLocation(const FVector& Location)
{
	Blackboard->SetValueAsVector("HomeLocation", Location);
}

void APlusheAIController::SetBehaviorState(EPlusheBehaviorState BehaviorState)
{
	Blackboard->SetValueAsEnum("PlusheState", uint8(BehaviorState));
}
