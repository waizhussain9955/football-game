#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerBallDebugComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerBallDebugComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerBallDebugComponent();
protected:
    virtual void BeginPlay() override;
};
