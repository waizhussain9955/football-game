#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StrikerPlayerController.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class PROJECTSTRIKER_API AStrikerPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AStrikerPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	// Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* PassAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* ShootAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* SprintAction;

	void Move(const struct FInputActionValue& Value);
	void Pass(const struct FInputActionValue& Value);
	void Shoot(const struct FInputActionValue& Value);
	void StartSprint(const struct FInputActionValue& Value);
	void StopSprint(const struct FInputActionValue& Value);
};
