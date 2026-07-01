#include "StrikerStaminaComponent.h"

UStrikerStaminaComponent::UStrikerStaminaComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	MaxStamina = 100.0f;
	CurrentStamina = MaxStamina;
}

void UStrikerStaminaComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerStaminaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerStaminaComponent::DepleteStamina(float Amount)
{
	CurrentStamina = FMath::Clamp(CurrentStamina - Amount, 0.0f, MaxStamina);
}

void UStrikerStaminaComponent::RecoverStamina(float Amount)
{
	CurrentStamina = FMath::Clamp(CurrentStamina + Amount, 0.0f, MaxStamina);
}
