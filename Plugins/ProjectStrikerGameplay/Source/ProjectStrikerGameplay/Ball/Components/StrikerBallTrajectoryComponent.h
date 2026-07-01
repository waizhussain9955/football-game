#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerBallTrajectoryComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerBallTrajectoryComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerBallTrajectoryComponent();
protected:
    virtual void BeginPlay() override;
};
