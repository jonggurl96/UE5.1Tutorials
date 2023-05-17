# Game-Controlled Cameras
> Camera를 어떻게 활성화하고 다른 Camera로 전환하기

## 1 - Place Cameras in the World
1. new Basic Code Project "HowTo_AutoCamera" 생성
2. Place Actors 패널에서 Camera 액터를 레벨에 드래그하여 첫 번째 카메라 생성
3. 두 번째 카메라를 생성하기 위해 카메라가 바라볼 액터로 Cube 선택해 레벨로 드래그
4. Cube 액터를 선택하고 Details 패널(F4)에서 **+ Add Component**를 선택해 CameraComponent를 추가
5. Camera 액터의 설정과 일치하도록 Constrain Aspect Ratio를 켜서 CameraComponent를 커스터마이징(선택사항, 카메라 전환이 더 부드러워짐)

## 2 - Control Camera View in C++
1. **Tools** > **New C++ Class**를 선택해 Actor를 확장한 CameraDirector 클래스를 생성
2. **CameraDirector.h** 파일 ACameraDirector 정의부 아래에 다음 코드 추가
    ```c++
    UPROPERTY(EditAnywhere)
    AActor* CameraOne;

    UPROPERTY(EditAnywhere)
    AActor* CameraTwo;

    float TimeToNextCameraChange;
    ```
> **UPROPERTY** 매크로는 변수를 Unreal Engine 에디터에 보이게 한다.
3. **CameraDirector.cpp** 파일 마지막 *#include* 코드 아래에 다음 코드 추가
    ```c++
    #include "Kismet/GameplayStatics.h"
    ```
    > **GameplayStatics.h**: 몇가지 유용한 범용 기능에 대한 액세스를 제공
4. 다음 코드를 ACameraDirector::Tick의 아래에 추가
    ```c++
    const float TimeBetweenCameraChanges = 2.0f;
    const float SmoothBlendTime = 0.75f;
    TimeToNextCameraChange -= DeltaTime;

    // 카메라 전환까지 시간이 아직 남은 경우 리턴
    if (TimeToNextCameraChange > 0.0f) return;

    // 카메라 전환이 필요한 경우 수행
    TimeToNextCameraChange += TimeBetweenCameraChanges;

    // local player를 제어할 수 있는 액터 찾기
    APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);

    // 플레이어가 제어하는 액터가 없을 경우 리턴
    if (!OurPlayerController) return;

    if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
    {
        // CameraOne으로 즉시 전환
        OurPlayerController->SetViewTarget(CameraOne);
    }
    else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
    {
        // CameraTwo로 부드럽게 전환
        OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
    }
    ```
5. 모든 코드가 작성되었으니 **Unreal Editor로 돌아가서** Compile

## 3 - Place a Camera Director in the World

1. 제대로 컴파일 되었다면 **Content Browser**에서 Level Editor로 드래그하여 인스턴스화할 수 있다.
2. Outliner에서 CameraDirector의 멤버 변수인 CameraOne과 CameraTwo를 앞서 생성한 Cube, CameraActor로 설정

## finished
> 이제 플레이하면 2초 후 카메라가 한 번에 바뀌고 2초 후에 부드게게 바뀌길 반복한다.

## 4 - On Your Own!

- 움직이는 액터에 카메라를 부착해 crane 또는 dolly shot 만들기
    - 지미집..?
- CameraOneTwo가 아닌 CameraArray를 사용해 만들기
- AActor*가 아닌 뷰를 변경하기 전의 시간과 포인터를 유지하는 구조를 만들어 적용하기

- [출처](https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/CPPTutorials/AutoCamera/)