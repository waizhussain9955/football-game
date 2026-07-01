#include "StrikerReplayManager.h"

void UStrikerReplayManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UStrikerReplayManager::StartRecording()
{
	// Trigger Unreal's demo net driver or custom state tracking
}

void UStrikerReplayManager::StopRecording()
{
}

void UStrikerReplayManager::PlayHighlight()
{
	// Start playback of a recently recorded event
}
