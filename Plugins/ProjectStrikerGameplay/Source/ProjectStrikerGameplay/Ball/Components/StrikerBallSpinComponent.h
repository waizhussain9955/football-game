#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerBallSpinComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerBallSpinComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerBallSpinComponent();
protected:
    virtual void BeginPlay() override;
};
