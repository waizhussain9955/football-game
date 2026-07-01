#include "StrikerHeadingComponent.h"

UStrikerHeadingComponent::UStrikerHeadingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStrikerHeadingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerHeadingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerHeadingComponent::AttemptHeaderClearance()
{
}

void UStrikerHeadingComponent::AttemptHeaderShot()
{
}
