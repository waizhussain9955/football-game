#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerTimeManager.generated.h"

/**
 * Tracks match time independently of engine time scale to support added time and varied half lengths.
 */
UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerTimeManager : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;

	UPROPERTY(BlueprintReadOnly, Category = "Time")
	float CurrentMatchMinute;

	UPROPERTY(BlueprintReadOnly, Category = "Time")
	float AddedTime;

	UFUNCTION(BlueprintCallable, Category = "Time")
	void SetTimeScale(float NewScale);
};
