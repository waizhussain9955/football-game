#pragma once
#include "CoreMinimal.h"
#include "Controllers/StrikerAIController.h"
#include "StrikerRefereeAIController.generated.h"

UCLASS()
class PROJECTSTRIKERAI_API AStrikerRefereeAIController : public AStrikerAIController
{
    GENERATED_BODY()
public:
    AStrikerRefereeAIController();
protected:
    virtual void BeginPlay() override;
};
