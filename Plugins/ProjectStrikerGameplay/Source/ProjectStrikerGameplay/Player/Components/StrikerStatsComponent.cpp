#include "StrikerStatsComponent.h"

UStrikerStatsComponent::UStrikerStatsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SprintSpeedRating = 75.0f;
	FinishingRating = 75.0f;
	ShortPassRating = 75.0f;
	StaminaRating = 75.0f;
}

void UStrikerStatsComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerStatsComponent::InitializeFromDataAsset(UPrimaryDataAsset* DataAsset)
{
	// Load attributes from data asset
}
