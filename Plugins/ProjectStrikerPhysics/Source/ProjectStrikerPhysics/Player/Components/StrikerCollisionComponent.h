#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerCollisionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERPHYSICS_API UStrikerCollisionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerCollisionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Collision")
	void HandlePlayerCollision(AActor* OtherPlayer);
};
