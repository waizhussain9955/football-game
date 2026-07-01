#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "StrikerAIController.generated.h"

UCLASS()
class PROJECTSTRIKERAI_API AStrikerAIController : public AAIController
{
    GENERATED_BODY()
public:
    AStrikerAIController();
protected:
    virtual void BeginPlay() override;
};
