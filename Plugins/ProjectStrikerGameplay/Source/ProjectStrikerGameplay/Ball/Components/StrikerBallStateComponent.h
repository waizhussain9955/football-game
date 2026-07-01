#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerBallStateComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerBallStateComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerBallStateComponent();
protected:
    virtual void BeginPlay() override;
};
