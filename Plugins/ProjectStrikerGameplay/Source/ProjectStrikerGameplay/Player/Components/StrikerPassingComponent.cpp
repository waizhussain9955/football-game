#include "StrikerPassingComponent.h"

UStrikerPassingComponent::UStrikerPassingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStrikerPassingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerPassingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerPassingComponent::ExecuteShortPass(float Power)
{
}

void UStrikerPassingComponent::ExecuteLongPass(float Power)
{
}

void UStrikerPassingComponent::ExecuteThroughPass(float Power)
{
}
