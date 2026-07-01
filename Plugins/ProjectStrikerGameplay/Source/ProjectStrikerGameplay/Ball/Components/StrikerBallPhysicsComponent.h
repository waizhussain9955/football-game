#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerBallPhysicsComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerBallPhysicsComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerBallPhysicsComponent();
protected:
    virtual void BeginPlay() override;
};
