#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test.generated.h"

UCLASS()
class CHAPTER3_5_API ATest : public AActor
{
	GENERATED_BODY()
	
public:	
	ATest();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY()
	FVector2D start;

	UPROPERTY()
	int32 evCnt;

	UPROPERTY()
	int totDist;

	UFUNCTION()
	float distance(FVector2D first, FVector2D second);

	UFUNCTION()
	int32 createEvent();

	UFUNCTION()
	void move();

	UFUNCTION()
	int32 step();
};
