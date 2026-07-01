#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "StrikerGameStateBase.generated.h"

UENUM(BlueprintType)
enum class EMatchPhase : uint8
{
	PreMatch UMETA(DisplayName = "Pre-Match"),
	FirstHalf UMETA(DisplayName = "First Half"),
	HalfTime UMETA(DisplayName = "Half Time"),
	SecondHalf UMETA(DisplayName = "Second Half"),
	FullTime UMETA(DisplayName = "Full Time")
};

/**
 * Maintains the global state of the match, including scores, time, and current phase.
 */
UCLASS()
class PROJECTSTRIKER_API AStrikerGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AStrikerGameStateBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Match State")
	EMatchPhase CurrentPhase;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Match State")
	int32 TeamBlueScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Match State")
	int32 TeamRedScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Match State")
	float MatchTimeSeconds;

	UFUNCTION(BlueprintCallable, Category = "Match State")
	void UpdateMatchTime(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Match State")
	void AddScore(int32 TeamIndex, int32 Points = 1);
};
