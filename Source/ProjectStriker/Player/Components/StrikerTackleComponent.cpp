#include "StrikerTackleComponent.h"

UStrikerTackleComponent::UStrikerTackleComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStrikerTackleComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerTackleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerTackleComponent::PerformStandingTackle()
{
	// Play standing tackle animation, detect ball or player collision
}

void UStrikerTackleComponent::PerformSlidingTackle()
{
	// Play sliding tackle animation, modify locomotion
}
