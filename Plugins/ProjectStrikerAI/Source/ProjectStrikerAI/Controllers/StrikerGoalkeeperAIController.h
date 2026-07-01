#pragma once
#include "CoreMinimal.h"
#include "Controllers/StrikerAIController.h"
#include "StrikerGoalkeeperAIController.generated.h"

UCLASS()
class PROJECTSTRIKERAI_API AStrikerGoalkeeperAIController : public AStrikerAIController
{
    GENERATED_BODY()
public:
    AStrikerGoalkeeperAIController();
protected:
    virtual void BeginPlay() override;
};
