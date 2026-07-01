#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerBallOwnershipComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerBallOwnershipComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerBallOwnershipComponent();
protected:
    virtual void BeginPlay() override;
};
