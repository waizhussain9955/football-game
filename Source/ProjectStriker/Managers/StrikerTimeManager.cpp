#include "StrikerTimeManager.h"

void UStrikerTimeManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentMatchMinute = 0.0f;
	AddedTime = 0.0f;
}

void UStrikerTimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Increment match minute based on time scale if match is active
}

TStatId UStrikerTimeManager::GetStatId() const
{
	RETURN_QUICK_DECLARE_OP(UStrikerTimeManager, STATGROUP_Tickables);
}

void UStrikerTimeManager::SetTimeScale(float NewScale)
{
	// Adjust how fast match minutes tick
}
