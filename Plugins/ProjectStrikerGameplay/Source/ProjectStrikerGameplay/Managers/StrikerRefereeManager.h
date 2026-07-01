#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerRefereeManager.generated.h"

class AStrikerBall;
class AStrikerCharacter;

/**
 * AI logic for the referee to blow the whistle, give cards, and detect offsides/fouls.
 */
UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerRefereeManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Referee")
	void ReportFoul(AStrikerCharacter* Offender, AStrikerCharacter* Victim);

	UFUNCTION(BlueprintCallable, Category = "Referee")
	void CheckOffside(AStrikerBall* Ball, AStrikerCharacter* PassingPlayer);
};
