#include "StrikerRuleManager.h"

void UStrikerRuleManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

bool UStrikerRuleManager::IsOffsideEnabled() const
{
	return true; // Configurable via Match Settings
}
