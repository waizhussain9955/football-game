#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerInputComponent.generated.h"

/**
 * Handles buffering and processing of Enhanced Input signals before they reach gameplay logic.
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKER_API UStrikerInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerInputComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly, Category = "Input")
	FVector2D MoveInput;

	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetMoveInput(FVector2D NewInput);
};
