#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerMovementPredictionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerMovementPredictionComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerMovementPredictionComponent();
protected:
    virtual void BeginPlay() override;
public:	
    // Interfaces / Delegate Hooks
};
