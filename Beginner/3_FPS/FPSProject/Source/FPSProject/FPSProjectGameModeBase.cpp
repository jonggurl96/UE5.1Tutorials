// Copyright Epic Games, Inc. All Rights Reserved.


#include "FPSProjectGameModeBase.h"

void AFPSProjectGameModeBase::StartPlay()
{
    Super::StartPlay();

    check(GEngine != nullptr);

    // 5초간 보여지는 로그 작성
    // -1값은 갱신 금지 값
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello world, This is FPSGameMode!"));
}