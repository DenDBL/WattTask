// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PlusheAIController.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Sight;

UCLASS()
class WATTTASK_API APlusheAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	APlusheAIController(FObjectInitializer const& ObjectInitializer);

protected:

	virtual void OnPossess(APawn* InPawn) override;

public:


	UPROPERTY()
	UAISenseConfig_Sight* SightConfig;

	UFUNCTION(BlueprintCallable)
	void SetEnemy(AActor* InPawn);

	UFUNCTION(BlueprintCallable)
	void SetMaster(AActor* InPawn);

	UFUNCTION(BlueprintCallable)
	void SetHomeLocation(const FVector& Location);

	UFUNCTION(BlueprintCallable)
	void SetBehaviorState(EPlusheBehaviorState BehaviorState);
};
