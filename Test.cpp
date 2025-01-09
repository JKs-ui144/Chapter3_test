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
	UE_LOG(LogTemp, Warning, TEXT("Hi"));   // ���� �� ��� Ȯ��
	move();
	UE_LOG(LogTemp, Warning, TEXT("Total Event : %d"), evCnt);
	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %d"), totDist);

}

int32 ATest::step()
{
	return FMath::RandRange(0, 1);  // ĳ������ �̵� �ѵ��� �ִ밪�� x, y 1��
}

void ATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// �����ΰ� start
float ATest::distance(FVector2D first, FVector2D second)
{
	float vX = first.X - second.X;
	float vY = first.Y - second.Y;
	return FMath::Sqrt(vX*vX + vY*vY);
}

int32 ATest::createEvent()
{
	int32 RandomValue = FMath::RandRange(1, 100); // ���� �� ����
	if (RandomValue < 50) {
		UE_LOG(LogTemp, Warning, TEXT("Event Triggered"));
		evCnt++;
	}
	else UE_LOG(LogTemp, Warning, TEXT("Event Not Triggered"));
	return evCnt;
}

void ATest::move()
{
	FVector2D current = start;	     // ���� ��ġ �޾ƿ���
	FVector2D previous = current;    // ���� ��ġ�� ���� ��ġ�� �̵�

	for (int32 i = 0; i < 10; i++) {
		int32 nextX = step();
		int32 nextY = step();
		FVector2D nextLot(current.X + nextX, current.Y + nextY);    // ĳ������ ���� ��ġ �� ���� (������ġ X�� + �̵���, ������ġ Y�� + �̵���)
		
		float dist = distance(current, nextLot);
		totDist += dist;
		UE_LOG(LogTemp, Warning, TEXT("step : %d Lotcation : %f, %f Move Distance : %f"), i + 1, nextLot.X, nextLot.Y,dist);  // TEXT( �ѱ۷� ����Ϸ� �ϸ� �α� ��� �ȵ� )
		previous = current;  // ������ġ�� ������ġ�� ����
		current = nextLot;   // ������ġ�� ������ġ�� ����
		createEvent();
	}

}