#include "StrikerCrossingComponent.h"

UStrikerCrossingComponent::UStrikerCrossingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStrikerCrossingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerCrossingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerCrossingComponent::ExecuteCross(float Power, FVector TargetArea)
{
}

void UStrikerCrossingComponent::ExecuteEarlyCross(float Power, FVector TargetArea)
{
}
