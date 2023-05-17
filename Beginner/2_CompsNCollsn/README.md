# Components and Collision

> Components를 이용해 Pawn이 다른 물체와의 상호작용이나 파티클 이펙트 등을 적용하는지 확인

## 1 - Creating and Attaching Components

1. 새 C++ 프로젝트 HowTo_Components 생성 후 프로젝트에 추가할 Components를 탑재한 CollidingPawn 생성

2. **.h** 파일에 아래 코드 추가
```c++
URPOPERTY()
class UParticleSystemComponent* OurParticleSystem;
```

3. **.cpp** 파일을 열고 생성자 코드에 다음 컴포넌트들을 추가한다.
    - Sphere Component: 물리적 영역을 구체로 설정해주는 컴포넌트
    - Static Mesh Component: 메시를 설정하는 컴포넌트
    - Spring Arm Component: 카메라와 폰 사이의 장애물 유무에 따라 카메라와의 거리를 조절하기 위한 컴포넌트
    - Camera Component: 카메라 컴포넌트
    
    > **.h** 파일에 아래 코드 추가
    > ```C++
    > #include "UObject/ConstructorHelpers.h"
    > #include "Particles/ParticleSubsystemComponent.h"
    > #include "Components/SphereComponent.h"
    > #include "Camera/CameraComponent.h"
    > #include "GameFramework/SpringArmComponent.h"
    > ```
4. 어느 컴포넌트를 RootComponent로 설정할 지 결정한다. 해당 프로젝트에서는 SphereComponent를 RootComponent로 설정한다.
```C++
USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
RootComponent = SphereComponent;
SphereComponent->InitSphereRadius(40.0f);
SphereComponent->SetCollisionProfileName(TEXT("Pawn"));
```
5. Static Mesh 설정
```C++
UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
SphereVisual->SetupAttachment(RootComponent);
static ConstructionHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
if (SphereVisualAsset.Succeeded())
{
    SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
    SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
    SphereVisual->SetWorldScale3D(FVector(0.8f));
}
```
> 위 코드처럼 Mesh 경로를 하드코딩할 수도 있지만 보통은 생성자에서 컴포넌트를 생성하고 언리얼 에디터에서 수정할 수 있도록 설정한 후 블루프린트 에셋을 만들어 거기서 설정한다.

6. Particle System을 생성한다. Particle System Component는 스태틱 메시에 직접 연결한다. 또한 메시의 bottom-center로부터 약간의 offset을 준 위치에 보이게 할 수도 있다.
```c++
OurParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MovementParticles"));
OurParticleSystem->SetupAttachment(SphereVisual);
OurParticleSystem->bAutoActivate = false;
OurParticleSystem->SetRelativeLocation(FVector(-20.0f, 0.0f, 20.0f));
static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StaterContent/Particles/P_Fire.P_Fire"));
if (ParticleAsset.Succedded())
{
    OurParticleSystem->SetTemplate(ParticleAsset.Object);
}
```
7. Spring Arm Component 추가
```c++
USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
SpringArm->SetupAttachment(RootComponent);
SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
SpringArm->TargetArmLength = 400.0f;
SpringArm->bEnableCameraLag = true;
SpringArm->CameraLagSpeed = 3.0f;
```
8. USpringArmComponent의 소켓 SpringEndPoint에 카메라 컴포넌트 추가하기
```c++
UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
```
9. 생성이 완료되었으니 플레이어 빙의 코드 추가
```c++
AutoPossessPlayer = EAutoReceiveInput::Player0;
```

## 2 - Configuring Input and Creating a Pawn Movement Component
1. 언리얼 에디터로 돌아가 **Edit** > **Project Settings** 메뉴를 열고 아래와 같이 설정한다.
    - **ParticleToggle**: Space Bar
    - **MoveForward**: W 1.0, S -1.0
    - **MoveRight**: A -1.0, D 1.0
    - **Turn**: MouseX 1.0
2. Pawn Movement Component를 확장한 새 C++ 클래스 CollidingPawnMovementComponent를 생성한다.

## 3 - Coding Our Pawn Movement Component's Behavior
1. 소스 코드 에디터로 돌아가 프레임마다 움직일 동작을 설정하기 위해 TickComponent 함수를 작성한다.
```C++
void UCollidingPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }

    // ACollidingPawn::Tick 함수에서 설정한 movement vector를 Get (and then clear)
    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 150.0f;
    if (!DesiredMovementThisFrame.IsNearlyZero())
    {
        FHitResult Hit;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

        // If we bumped into something, try to slide along it
        if (Hit.IsValidBlockingHit())
        {
            SlideAlongSurface(DesiredMovementThisFrame, 1.0f = Hit.Time, Hit.Normal, Hit);
        }
    }
}
```
## 4 - Using Our Pawn and Components Together
1. Colliding Pawn에 생성한 Pawn Movement Component를 추가한다.
```c++
// .h
UPROEPRTY()
class UCollidingPawnMovementComponent* OurMovementComponent;

// .cpp
OurMovementComponent = CreateDefaultSubobject<UCollidingPawnMovementComponent>(TEXT("CustomMovementComponent"));
OurMovementComponent->UpdatedComponent = RootComponent;
```
2. Pawn 클래스는 사용중인 Pawn Movement Component에 접근하기 위한 GetMovementComponent 함수가 있는데 **virtual** 타입이므로 override해야한다.
```c++
// .h
virtual UPawnMovementComponent* GetMovementComponent() const override;

// .pp
UPawnMovementComponent* ACollidingPawn::GetMovementComponent() const
{
    return OurMovementComponent;
}
```
3. CollidingPawn 클래스에 다음 4개의 함수를 추가해야함.
```c++
void ACollidingPawn::MoveForward(float AxisValue)
{
    if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
    {
        OurMovementComponent->AddInputVector(GetActorForwardVector() * AxisValue);
    }
}

void ACollidingPawn::MoveRight(float AxisValue)
{
    if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
    {
        OurMovementComponent->AddInputVector(GetActorRightVector() * AxisValue());
    }
}

void ACollidingPawn::Turn(float AxisValue)
{
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += AxisValue;
    SetActorRotation(NewRotation);
}

void ACollidingPawn::ParticleToggle()
{
    if (OurParticleSystem && OurParticleSystem->Template)
    {
        OurParticleSystem->ToggleActive();
    }
}
```
4. 이제 Input Event와 방금 생성한 함수를 바인딩하면 끝
```c++
// ACollidingPawn::SetupPlayerInputComponent:
InInputComponent->BindAction("ParticleToggle", IE_Pressed, this, &ACollidingPawn::ParticleToggle);
InInputComponent->BindAxis("MoveForward", this, &ACollidingPawn::MoveForward);
InInputComponent->BindAxis("MoveRight", this, &ACollidingPawn::MoveRight);
InInputComponent->BindAxis("Turn", this, &ACollidingPawn::Turn);
```
## 5 - On your Own!
- Actor 주위를 공전하는 컴포넌트 추가
- 스폰하고 3초 후 디스폰하는 자식을 3개 갖는 컴포넌트 만들기
- 컴포넌트를 통해 전체 액터를 다른 액터에 연결