#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerPossessionManager.generated.h"

class AStrikerCharacter;

/**
 * Tracks which player and team currently possesses the ball.
 */
UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerPossessionManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintReadOnly, Category = "Possession")
	AStrikerCharacter* CurrentPossessor;

	UPROPERTY(BlueprintReadOnly, Category = "Possession")
	int32 PossessingTeamIndex;

	UFUNCTION(BlueprintCallable, Category = "Possession")
	void SetPossession(AStrikerCharacter* NewPossessor, int32 TeamIndex);

	UFUNCTION(BlueprintCallable, Category = "Possession")
	void ClearPossession();
};
