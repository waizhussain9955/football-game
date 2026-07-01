#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerAudioManager.generated.h"

/**
 * Dynamically mixes stadium audio, match events, crowd reactions, and commentary.
 */
UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerAudioManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlayMatchEventSound(FName EventName, FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void TriggerCommentary(FName EventKey);
};
