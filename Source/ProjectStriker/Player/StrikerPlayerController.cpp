#include "StrikerPlayerController.h"
#include "StrikerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/StrikerLocomotionComponent.h"
#include "Components/StrikerActionComponent.h"

AStrikerPlayerController::AStrikerPlayerController()
{
}

void AStrikerPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (DefaultMappingContext)
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AStrikerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Bindings would go here if actions are valid
		/*
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AStrikerPlayerController::Move);
		EnhancedInputComponent->BindAction(PassAction, ETriggerEvent::Started, this, &AStrikerPlayerController::Pass);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &AStrikerPlayerController::Shoot);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &AStrikerPlayerController::StartSprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AStrikerPlayerController::StopSprint);
		*/
	}
}

void AStrikerPlayerController::Move(const FInputActionValue& Value)
{
	// Route input to possessed StrikerCharacter
}

void AStrikerPlayerController::Pass(const FInputActionValue& Value)
{
	// Route to ActionComponent
}

void AStrikerPlayerController::Shoot(const FInputActionValue& Value)
{
	// Route to ActionComponent
}

void AStrikerPlayerController::StartSprint(const FInputActionValue& Value)
{
	if (AStrikerCharacter* Striker = Cast<AStrikerCharacter>(GetPawn()))
	{
		if (Striker->LocomotionComp)
			Striker->LocomotionComp->SetSprinting(true);
	}
}

void AStrikerPlayerController::StopSprint(const FInputActionValue& Value)
{
	if (AStrikerCharacter* Striker = Cast<AStrikerCharacter>(GetPawn()))
	{
		if (Striker->LocomotionComp)
			Striker->LocomotionComp->SetSprinting(false);
	}
}
