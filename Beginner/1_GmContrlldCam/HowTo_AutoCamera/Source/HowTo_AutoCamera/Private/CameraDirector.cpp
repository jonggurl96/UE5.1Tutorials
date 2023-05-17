// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;
	TimeToNextCameraChange -= DeltaTime;

	// 카메라 전환까지 시간이 아직 남은 경우 리턴
	if (TimeToNextCameraChange > 0) return;

	// 카메라 전환이 필요한 경우 아래 코드들 수행
	TimeToNextCameraChange = TimeBetweenCameraChanges;

	// local player를 제어할 수 있는 액터 찾기
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);

	// 액터를 찾지 못한 경우 리턴
	if (!OurPlayerController) return;

	if ((OurPlayerController->GetViewTarget() != CameraOne) && CameraOne != nullptr) {
		OurPlayerController->SetViewTarget(CameraOne);
	}
	else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr)) {
		OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
	}

}

