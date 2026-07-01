#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerBallCollisionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerBallCollisionComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerBallCollisionComponent();
protected:
    virtual void BeginPlay() override;
};
