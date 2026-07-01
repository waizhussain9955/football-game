#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StrikerGameModeBase.generated.h"

/**
 * Core GameMode for the football match.
 * Responsible for match rules, refereeing logic, and state transitions (kickoff, half-time, full-time).
 */
UCLASS()
class PROJECTSTRIKER_API AStrikerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AStrikerGameModeBase();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

public:
	// Example functions for match flow
	UFUNCTION(BlueprintCallable, Category = "Match Flow")
	void StartKickoff();

	UFUNCTION(BlueprintCallable, Category = "Match Flow")
	void EndHalfTime();

	UFUNCTION(BlueprintCallable, Category = "Match Flow")
	void GoalScored(int32 TeamIndex);
};
