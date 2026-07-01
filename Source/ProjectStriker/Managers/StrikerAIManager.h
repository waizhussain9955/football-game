#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerAIManager.generated.h"

/**
 * High-level orchestration of AI tacticts, evaluating space, and assigning State Trees to players based on roles.
 */
UCLASS()
class PROJECTSTRIKER_API UStrikerAIManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AI")
	void AssignTacticalRoles(int32 TeamIndex);

	UFUNCTION(BlueprintCallable, Category = "AI")
	void UpdateTeamMentality(int32 TeamIndex, uint8 NewMentality);
};
