#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerAnimationComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERANIMATION_API UStrikerAnimationComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerAnimationComponent();
protected:
    virtual void BeginPlay() override;
};
