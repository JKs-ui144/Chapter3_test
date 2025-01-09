#include "Test.h"

ATest::ATest()
{
	PrimaryActorTick.bCanEverTick = true;
	start = FVector2D(0, 0);
	evCnt = 0;
	totDist = 0;
}

void ATest::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hi"));   // 시작 시 출력 확인
	move();
	UE_LOG(LogTemp, Warning, TEXT("Total Event : %d"), evCnt);
	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %d"), totDist);

}

int32 ATest::step()
{
	return FMath::RandRange(0, 1);  // 캐릭터의 이동 한도는 최대값은 x, y 1씩
}

void ATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// 움직인건 start
float ATest::distance(FVector2D first, FVector2D second)
{
	float vX = first.X - second.X;
	float vY = first.Y - second.Y;
	return FMath::Sqrt(vX*vX + vY*vY);
}

int32 ATest::createEvent()
{
	int32 RandomValue = FMath::RandRange(1, 100); // 랜덤 값 생성
	if (RandomValue < 50) {
		UE_LOG(LogTemp, Warning, TEXT("Event Triggered"));
		evCnt++;
	}
	else UE_LOG(LogTemp, Warning, TEXT("Event Not Triggered"));
	return evCnt;
}

void ATest::move()
{
	FVector2D current = start;	     // 현재 위치 받아오기
	FVector2D previous = current;    // 현재 위치를 이전 위치로 이동

	for (int32 i = 0; i < 10; i++) {
		int32 nextX = step();
		int32 nextY = step();
		FVector2D nextLot(current.X + nextX, current.Y + nextY);    // 캐릭터의 다음 위치 값 설정 (현재위치 X값 + 이동값, 현재위치 Y값 + 이동값)
		
		float dist = distance(current, nextLot);
		totDist += dist;
		UE_LOG(LogTemp, Warning, TEXT("step : %d Lotcation : %f, %f Move Distance : %f"), i + 1, nextLot.X, nextLot.Y,dist);  // TEXT( 한글로 출력하려 하면 로그 출력 안됨 )
		previous = current;  // 현재위치를 과거위치로 설정
		current = nextLot;   // 다음위치를 현재위치로 설정
		createEvent();
	}

}