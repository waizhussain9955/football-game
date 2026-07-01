#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerGameFlowManager.generated.h"

/**
 * Handles transitions between match phases (PreMatch, FirstHalf, HalfTime, FullTime).
 */
UCLASS()
class PROJECTSTRIKER_API UStrikerGameFlowManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Game Flow")
	void TransitionToPhase(uint8 NewPhase);
};
