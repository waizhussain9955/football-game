#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerBallControlComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerBallControlComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerBallControlComponent();
protected:
    virtual void BeginPlay() override;
};
