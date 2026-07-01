#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "StrikerAIController.generated.h"

UCLASS()
class PROJECTSTRIKER_API AStrikerAIController : public AAIController
{
	GENERATED_BODY()

public:
	AStrikerAIController();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

public:
	virtual void Tick(float DeltaTime) override;

	// Blackboard keys or references can be set here
};
