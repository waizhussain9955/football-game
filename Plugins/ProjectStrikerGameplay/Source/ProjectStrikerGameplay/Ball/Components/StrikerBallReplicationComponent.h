#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerBallReplicationComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerBallReplicationComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerBallReplicationComponent();
protected:
    virtual void BeginPlay() override;
};
