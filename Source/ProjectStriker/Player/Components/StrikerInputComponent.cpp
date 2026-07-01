#include "StrikerInputComponent.h"

UStrikerInputComponent::UStrikerInputComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStrikerInputComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerInputComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerInputComponent::SetMoveInput(FVector2D NewInput)
{
	MoveInput = NewInput;
}
