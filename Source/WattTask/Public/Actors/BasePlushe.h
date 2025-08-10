// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/InteractionInterface.h"
#include "BasePlushe.generated.h"

UENUM(BlueprintType)
enum class EPlusheBehaviorState : uint8
{
	Idle		UMETA(DisplayName = "Idle"),
	Aggressive	UMETA(DisplayName = "Aggressive"),
	Shy			UMETA(DisplayName = "Shy"),
	Tamed		UMETA(DisplayName = "Tamed")
};

class UBehaviorTree;
class UPlusheTypeDataAsset;

UCLASS()
class WATTTASK_API ABasePlushe : public ACharacter, public IInteractionInterface
{
	GENERATED_BODY()

public:

	ABasePlushe();

protected:


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBehaviorTree* BehaviorTree;

	UPROPERTY(BlueprintReadOnly)
	FVector InitialLocation;

	UPROPERTY()
	EPlusheBehaviorState PlusheBehaviorState;


	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* Input) override;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPlusheTypeDataAsset* PlusheTypeDataAsset;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	UBehaviorTree* GetBehaviorTree() { return BehaviorTree; };

	UFUNCTION(BlueprintCallable)
	FVector GetInitialLocation() { return InitialLocation; };

	UFUNCTION(BlueprintCallable)
	void UpdatePlusheData(float MovementSpeed, float PerceptionRadius, EPlusheBehaviorState BehaviorState);

	UFUNCTION(BlueprintCallable)
	void UpdatePlusheState(EPlusheBehaviorState BehaviorState);

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	//Implementations

	void ReactToGadget_Implementation(AActor* GadgetUser) override;
};
