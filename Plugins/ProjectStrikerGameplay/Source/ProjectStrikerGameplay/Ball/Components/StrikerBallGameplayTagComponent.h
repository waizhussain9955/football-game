#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerBallGameplayTagComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerBallGameplayTagComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerBallGameplayTagComponent();
protected:
    virtual void BeginPlay() override;
};
