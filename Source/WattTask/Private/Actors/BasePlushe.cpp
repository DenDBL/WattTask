// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePlushe.h"
#include "AI/PlusheAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "WattTask/WattTaskCharacter.h"
#include "DataAssets/PlusheTypeDataAsset.h"

ABasePlushe::ABasePlushe()
{
	PrimaryActorTick.bCanEverTick = true;


	AIControllerClass = APlusheAIController::StaticClass();
}

void ABasePlushe::BeginPlay()
{
	Super::BeginPlay();
	
	InitialLocation = GetActorLocation();
	
	if (IsValid(PlusheTypeDataAsset))
	{
		UpdatePlusheData(PlusheTypeDataAsset->MovementSpeed,PlusheTypeDataAsset->PerceptionRadius, PlusheTypeDataAsset->BehaviorState);
	}
}

void ABasePlushe::SetupPlayerInputComponent(UInputComponent* Input)
{
	Super::SetupPlayerInputComponent(Input);
}

void ABasePlushe::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		if (AWattTaskCharacter* PlayerCharacter = Cast<AWattTaskCharacter>(Actor))
		{
			if (APlusheAIController* AIController = Cast<APlusheAIController>(GetController()))
			{
				AIController->SetEnemy(PlayerCharacter);
				return;
			}
		}
	}
	else
	{
		if (APlusheAIController* AIController = Cast<APlusheAIController>(GetController()))
		{
			AIController->SetEnemy(nullptr);
		}
	}
}

// Called every frame
void ABasePlushe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePlushe::UpdatePlusheData(float MovementSpeed, float PerceptionRadius, EPlusheBehaviorState BehaviorState)
{
	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;

	if (APlusheAIController* AIController = Cast<APlusheAIController>(GetController()))
	{
		AIController->SightConfig->SightRadius = PerceptionRadius;
		AIController->SightConfig->LoseSightRadius = PerceptionRadius;
		AIController->PerceptionComponent->ConfigureSense(*AIController->SightConfig);
	}
	UpdatePlusheState(BehaviorState);
}

void ABasePlushe::UpdatePlusheState(EPlusheBehaviorState BehaviorState)
{
	PlusheBehaviorState = BehaviorState;
	if (APlusheAIController* AIController = Cast<APlusheAIController>(GetController()))
	{
		AIController->SetBehaviorState(BehaviorState);
	}
}

void ABasePlushe::ReactToGadget_Implementation(AActor* GadgetUser)
{
	UpdatePlusheState(EPlusheBehaviorState::Tamed);
	if (APlusheAIController* AIController = Cast<APlusheAIController>(GetController()))
	{
		AIController->SetMaster(GadgetUser);
	}
}

