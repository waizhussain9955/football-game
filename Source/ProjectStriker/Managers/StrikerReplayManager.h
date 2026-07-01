#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerReplayManager.generated.h"

/**
 * Captures game state and orchestrates the playback of action replays.
 */
UCLASS()
class PROJECTSTRIKER_API UStrikerReplayManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Replay")
	void StartRecording();

	UFUNCTION(BlueprintCallable, Category = "Replay")
	void StopRecording();

	UFUNCTION(BlueprintCallable, Category = "Replay")
	void PlayHighlight();
};
