#include "StrikerAnimationManager.h"

void UStrikerAnimationManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UStrikerAnimationManager::RegisterPoseDatabase(FName DatabaseName)
{
	// Load and prepare Pose Search Databases for motion matching
}
