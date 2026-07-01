#include "StrikerPhysicsManager.h"

void UStrikerPhysicsManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UStrikerPhysicsManager::ApplyTurfFriction(float GroundWetness)
{
	// Adjust global physical material friction based on weather
}
