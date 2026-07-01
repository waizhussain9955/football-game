#include "StrikerAudioManager.h"

void UStrikerAudioManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UStrikerAudioManager::PlayMatchEventSound(FName EventName, FVector Location)
{
	// Play sounds like kicks, whistles, net impacts
}

void UStrikerAudioManager::TriggerCommentary(FName EventKey)
{
	// Queue and play commentary lines
}
