# First Person Shooter Tutorial

## 1 - Setting up Project

### 1.1 - Project Setup
1. FPSProject라는 이름의 빈 C++ 게임용 프로젝트 생성
2. Content 폴더 아래 Maps폴더를 생성하고 그 안에 FPSMap 맵(basic) 생성
3. **Edit > Project Settings > Maps & Modes > Editor Startup Map** FPSMap으로 설정
4. Visual Studio 프로젝트 생성

### 1.2 - Adding Log Messaging
1. **FPSProjectGameMode.h** 열고 아래 코드 작성
```c++
> virtual void StartPlay() override;
```
2. **FpsProjectGameMode.cpp** 아래 다음 코드 작성
```c++
void AFPSProjectGameModeBase::StartPlay()
{
    Super::StartPlay();

    check(GEngine != nullptr);

    // 5초간 보여지는 로그 메세지 작성
    // -1값은 메세지가 업데이트되거나 갱신되는 것을 방지
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));
}
```
### 1.3 - Extending C++ Game Mode Class to Blueprints
1. Content 폴더 아래에 Blueprints 폴더 생성
2. 콘텐츠 브라우저에서 C++ Classes 폴더에 있는 **FPSProjectGameModeBase.h** 우클릭 후 **Create Blueprint class based on FPSProjectGameModeBase** 클릭
3. **Content > Blueprints > BP_FPSProjectGameModeBase** 생성
4. 블루프린트 에디터를 열고 생성한 **BP_FPSProjectGameModeBase** 저장

### 1.4 - Setting the Default Game Mode
1. **Edit > Project Settings > Maps & Modes > Default GameMode**에서 **BP_FPSProjectGameMode** 선택


## 2 - Implementing Character (캐릭터 구현)

### 2.1 - 새 캐릭터 만들기
1. C++ class character 생성: FPSCharacter
2. **FPSCharacter.cpp** BeginPlay()함수 아래에 다음 코드 추가
```c++
check(GEngine != nullptr);
GEngine->AddOnScreenDebugMessage(-1, 5.0f, FCollor::Red, TEXT("We are using FPSCharacter."));
```
3. 빌드 후 블루프린트 클래스로 확장 BP_FPSCharacter
4. **Edit > Project Settings > Maps & Modes > Default Pawn Class** *BP_FPSCharacter* 선택
    > 직접 배치하지 않아도 자동으로 생성하기 위함

### 2.2 - Setting up Axis Mapping
1. **Edit > Project Settings > Engine > Input > Bindings > Axis Mappings**에서 Moveforward(w: 1, s: -1), MoveRight(d: 1, a: -1) 추가

### 2.3 - 캐릭터 동작 구현
1. **FPSCharacter.h** 파일에 다음 두 함수 추가
```c++
UFUNCTION()
void MoveForward(float Value);

UFUNCTION()
void MoveRight(float Value);
```
2. **FPSCharacter.cpp**의 SetupPlayerInputComponent()에 다음 코드 추가
```c++
PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
```
3. **MoveForward()**와 **MoveRight()** 구현
```c++
void MoveForward(float Value)
{
    AddMovementInput(GetActorForwardVector(), Value);
}

void MoveRight(float Value)
{
    AddMovementInput(GetActorRightVector(), Value);
}
```

### 2.4 - 마우스 카메라 컨트롤 구현
1. **Edit > Project Settings > Engine > Input > Bindings > Axis Mappings**에서 Turn 추가(Mouse X, 1.0): Yaw
2. **Edit > Project Settings > Engine > Input > Bindings > Axis Mappings**에서 LookUp 추가(Mouse Y, -1.0): Pitch
3. BindAxis
```c++
PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);
```

### 2.5 - 점프 구현
1. **Edit > Project Settings > Engine > Input > Bindings > Action Mappings**에서 SpaceBar에 Jump mapping
2. *ACharacter.h* 파일을 보면 점프용 built-in support가 있는데 변수 *bPressedJump*에 의해 결정된다.
3. 다음 코드를 **AFPSCharacter.h**에 추가한다.
```c++
UFUNCTION()
void StartJump();

UFUNCTION()
void StopJump();
```
4. 각각의 함수에서 bPressedJump 값에 true, false를 대입한다.
5. InputAction Event에 각각의 액션을 mapping
```c++
PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::StartJump);
PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJump);
```

### 2.6 - 캐릭터에 Mesh 추가
[우클릭 후 다른이름으로 저장하여 GenericMale.fbx 사용하기](https://docs.unrealengine.com/5.1/Attachments/programming-and-scripting/programming-language-implementation/cpp-in-unreal-engine/tutorials/first-person-shooter-cpp/implementing-character/GenericMale.zip)
1. 콘텐츠 브라우저의 Content 폴더로 이동
2. Import Asset > Import to /Game > GenericMale.fbx
3. FBX Import Options 창이 열리면 Import All 클릭
4. 블루프린트 에디터를 열고 캐릭터의 캡슐 컴포넌트에 Mesh 컴포는트를 GenericMale 스켈레탈 메시로 변경
5. Mesh의 Location Z값을 -88.0으로 변경하여 캡슐 컴포넌트 안에 들어오도록 설정

### 2.7 - 카메라 뷰 바꾸기
1. "Camera/CameraComponent.h"와 "Components/CapsuleComponent.h"를 include
2. public 접근 제어자에 카메라 컴포넌트 추가
```c++
public:
    UPROPERTY(VisibleAnywhere)
    UCameraComponent* FPSCameraComponent;
```
3. FPSCharacter 생성자에 카메라 컴포넌트와 캡슐 컴포넌트를 추가
```c++
FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
check(FPSCameraComponent != nullptr);

FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));
```
4. 계속해서 다음 코드 추가
```c++
// 눈높이에 카메라 위치시키기
FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

// Camera Rotation으로 Pawn 회전시키기
FPSCameraComponent->bUsePawnControlRotation = true;
```

### 2.8 - Add a First Person Mesh
> FPS 게임을 만드는 일반적인 방법은 전신 Mesh를 무기, 팔 Mesh와 분리하는 것이다.
1. 사용자에게 보이는 무기, 팔 Mesh를 추가한다.
```c++
UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
USkeletalMeshComponent* FPSMesh;
```
2. 생성자에서 FPSMesh를 생성한다.
```c++
FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
check(FPSMesh != nullptr);

// 사용자만 보이게 설정
FPSMesh->SetOnlyOwnerSee(true);

// FPSCameraComponrnt에 장착
FPSMesh->SetupAttachment(FPSCameraComponent);

// 그림자가 생성되지 않도록 설정
FPSMesh->bCastDynamicShadow = false;
FPSMesh->CastShadow = false;

// 사용자 눈에는 전신 Mesh가 보이지 않도록 설정
GetMesh()->SetOwnerNoSee(true);
```
3. [링크](https://docs.unrealengine.com/5.1/Attachments/programming-and-scripting/programming-language-implementation/cpp-in-unreal-engine/tutorials/first-person-shooter-cpp/implementing-character/HeroFPP.zip)를 다른 이름으로 저장 후 무기, 팔 Mesh 다운로드
4. 마찬가지로 Import 하는데, Skeletal Mesh 부분 clear 후 Import All
5. 메시지 로그 에러나는데 정상임
6. 저장 후 full bluprint editor에서 FirstPersonMesh 적용
7. Location(220, 0, 35), Rotation(180, 50, 180) 설정
8. 팔이 전신에서 많이 떨어지고 하늘을 향해야 정상

## 3 - Implementing Projectiles (발사체 구현)

### 3.1 - 발사체 추가하기
1. **Edit > Project Settings > Engine > Input > Bindings > Action Mappings**에서 마우스 좌클릭에 Fire 액션 추가하기
2. 새 C++ 클래스 FPSProjectile : Actor 생성
3. 총알은 구체이니 구체 컴포넌트를 사용
```c++
#include "Components/SphereComponent.h"

UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
USphereComponent* CollisionComponent;
```
4. 생성자에 다음 코드 추가
```c++
if(!RootComponent)
{
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
}

if(!CollisionComponent)
{
    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    CollisionComponent->InitSphereRadius(15.0f);
    RootComponent = CollisionComponent;
}
```
5. 발사체 무브먼트 컴포넌트를 추가
```c++
#include "GameFramework/ProjectileMovementComponent.h"

UPROPERTY(VisibleAnywhere, Category = Movement)
UProjectileMovementComponent* ProjectileMovementComponent;
```
6. 다시 생성자로 돌아가서 다음 코드 추가
```c++
if(!ProjectileMovementComponent)
{
    ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
    ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
    ProjectileMovementComponent->InitialSpeed = 3000.0f;
    ProjectileMovementComponent->MaxSpeed = 3000.0f;
    ProjectileMovementComponent->bRotationFollowsVelocity = true;
    ProjectileMovementComponent->bShouldBounce = true;
    ProjectileMovementComponent->Bounciness = 0.3f;
    ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
}
```
7. 발사체 초기속도 구현
```c++
void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
    ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}
```

8. 발사 액션 바인딩
```c++
// FPSCharacter.h
UFUNCTION()
void Fire();

// FPSCharacter.cpp

// Binding
PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);

// Declaration
void FPSProjectile::Fire()
{
    ;
}
```

9. FPSCharacter에 발사체 스폰 위치 설정
```c++
// 카메라 위치로부터 총구 offset
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
FVector MuzzleOffset;

// 스폰할 FPSProjectile 생성
UPROPERTY(EditDefaultsOnly, Category = Projectile)
TSubclassOf<class AFPSProjectile> ProjectileClass;
```

### 3.2 - 슈팅 구현
1. *FPSCharacter.cpp*의 Fire()를 정의한다.
```c++
void AFPSCharacter::Fire()
{
    if(!ProjectileClass)
    {
        return;
    }
    
    // Get the Camera Transform
    FVector CameraLocation;
    FRotator CameraRotation;
    GetActorEyesViewPoint(CameraLocation, CameraRotation);

    // MuzzleOffset 초기화
    MuzzleOffset.Set(100.0f, 0.0f, 0.0f);

    // Set Muzzle Offset from Camera space to world space
    FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

    // Skew the aim to be slightly upwards
    FRotator MuzzleRotation = CameraRotation;
    MuzzleRotation.Pitch += 10.0f;

    UWorld* World = GetWorld();
    if(!World)
    {
        return;
    }
    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.Instigator = GetInstigator(); // 선동자..?

    // Spawn the Projectile at the Muzzle
    AFPSProjectile* Projectile = World->SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);

    if(Projectile)
    {
        // Set the projectile's Initial trajectory 궤도
        FVector LaunchDirection = MuzzleRotation.Vector();
        Projectile->FireInDirection(LaunchDirection);
    }
}
```
2. *FPSCharacter.h*파일에 *FPSProjectile.h* include
3. [여기](https://docs.unrealengine.com/4.26/Attachments/ProgrammingAndScripting/ProgrammingWithCPP/CPPTutorials/FirstPersonShooter/3/2/Sphere.zip)에서 Projectile Mesh 다운로드 후 Import
4. Projectile Mesh 추가하기
```c++
// FPSProjectile.h
UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
UStaticMeshComponent* ProjectileMeshComponent;

// FPSProjectile.cpp
if(!ProjectileMeshComponent)
{
    ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
    static ConstructorHelpers::FObjectFinder<UStaticMeshComponent>Mesh(TEXT("[다운받은 Mesh 우클릭 후 Copy Reference]"));
    if(Mesh.Succeeded())
    {
        ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
    }
}
```
5. Projectile Material 추가하기
> 새 Material 추가하기
> -
> |이름|Base Color|Specular|Emissive Color|
> |-|-|-|-|
> |-|색상|반사광|방출광|
> |SphereMaterial|Constant3VectorNode(1, 0, 0)|ConstantNode 0.5|ConstantNode 0.05|
```c++
// FPSProjectile.h
UPROPERTY(VisibleDefaultsOnly, Category = Movement)
UMaterialInstanceDynamic* ProjectileMaterialInstance;

// FPSProjectile.cpp
static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("[다운받은 Mesh와 함께 있는 Material 혹은 새로 만든 Material 우클릭 후 Copy Reference]"));
if(Material.Succeeded())
{
    ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
}
ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
ProjectileMeshComponent->SetupAttachMent(RootComponent);
```
6. BP_FPSCharacter full editor를 열고 Projectile Class를 FPSProjectile 선택

### 3.3 - 발사체 충돌과 수명 설정
1. *FPSProjectile.cpp* constructor에 수명 설정
```c++
InitialLifeSpan = 3.0f;
```
2. **Edit > Project Settings > Engine > Collision**에서 *New Object Channel...* 선택후 이름은 Projectile, Default Response는 Block 선택 후 Accept
3. **Edit > Project Settings > Engine > Collision > Preset**에서 *New...*를 선택하여 새로운 Profile을 아래 설정에 맞게 생성

|Name|Collision Enabled|Object Type|Description|Collision Response|Visibility|Camera|World Static|World Dynamic|Pawn|Physics Body|Vehicle|Destructible|Projectile|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Projectile|Collision Enabled(Query and Physics)|Projectile|Our projectile collision profile1|-|Block|Block|Block|Block|Overlap|Block|Block|Block|Block|
4. FPSProjectile 생성자에서 Collision Profile 선택
```c++
CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
```

### 3.4 - Getting Projectiles to Interaction with World
1. **FPSProjectile.h**에 다음 코드 추가
```c++
// 발사체가 무언가와 충돌하면 실행되는 함수
UFUNCTION()
void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
```
2. 구현하기
```c++
void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    if(OtherActor != this && OtherComponent->IsSimulatingPhysics())
    {
        OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
    }

    Destroy();
}
```
3. 구현한 Hit Event Catcher를 Binding
```c++
CollisionComponent->OnComponentHit.AddDynamic(this, $AFPSProjectile::OnHit);
```

## 4 - Adding Character Animation

### 4.1 - Animating Character
1. Contents 폴더 아래에 Animations 폴더 생성 후 [이 주소를 다른 이름으로 저장한 후에 압축해제한다.](https://docs.unrealengine.com/4.26/Attachments/ProgrammingAndScripting/ProgrammingWithCPP/CPPTutorials/FirstPersonShooter/4/1/FPP_Animations.zip)
2. 모두 import(Animation [Set Range], Advanced > Frame Import Range: 0 ~ 5, 모두 팔 모양 애니메이션이므로 Mesh HeroFPP 선택)
3. Animation Blueprint 생성
    1. Parent Class: AnimInstance
    2. Target: Hero_FPP_Skeleton
    3. Name: Arms_AnimBP
4. 블루프린트 에디터 열고 **My Bluprint**탭에서 boolean 변수 추가(IsRunning, IsFalling)

### 4.2 - Setting upEvent Graph
1. **Arms_AnimBP** 블루프린트 에디터 열고 Event Graph를 열면 TryGetPawnOwner 노드와 함께 Event Blueprint Update Animation 노드가 생성되어 있음
2. 블루프린트 애니메이션이 업데이트될 때마다(틱마다) 애니메이션이 실행되도록 캐릭터를 받아와야하므로 *Event Blueprint Update Animation* 다음에 *Cast To Character* 노드를 연결하고 object 핀과 *Try Get Pawn Owner* 노드를 연결한다.
3. 매 틱마다 캐릭터 상태를 알기 위해 캐스팅 된 캐릭터로부터 다음 두 가지를 가져온다.
    > IsRunning
    >
    > - GetVelocity - VectorLength가 0보다 크면 true

    > IsFalling
    >
    > - GetCharacterMovement - GetMovementMode가 (Enumerate) Falling과 같으면 true

### 4.3 - Adding an Animation State Machine
1. Anim Graph에서 Add New State Machine 선택 *Arms State Machine*과 Final Animation Pose 연결

### 4.4 - Adding Animation Transition Status
1. *Arms State Machine* 더블클릭하여 스테이트 머신 그래프 열기
2. 다음 5개의 State를 추가하고 더블클릭해 Animation 블루프린트와 Pose 핀을 연결
    1. Idle
    2. Run
    3. JumpStart
    4. JumpLoop
    5. JumpEnd
3. Entry 노드에서 Idle 스테이트로 연결
4. Idle 스테이트에서 Run, JumpStart 스테이트로 연결
5. Run 스테이트에서 Idle, JumpStart 스테이트로 연결
6. Run과 Idle 스테이트가 연결된 두 트랜지션을 각각 더블클릭하여 IsRunning 값(T, F)을 Result에 추가한다.
7. Run과 Idle 스테이트에서 JumpStart로 연결되는 트랜지션은 IsFalling 값을 사용한다.
8. JumpStart 스테이트에서 JumpLoop 스테이트로 향하는 트랜지션을 더블클하하고 Animation FPP_JumpStart의 Time Remaining 값이 0.1보다 작거나 같으면 넘어가도록 연결
9. JumpLoop 스테이트에서 JumpEnd 스테이트로 넘어가는 조건은 IsFalling 값이 False인 경우임
10. JumpEnd에서 Idle로 넘어가는 조건은 FPP_JumpEnd의 Time Remaining 값이 0.1보다 작거나 같은 경우임.

### 4.5 - Associating Animation and Character Blueprints
1. 컴파일 후 BP_FPSCharacter 블루프린트 에디터에서 FPSMesh의 Anim Class를 Arms_AnimBP로 설정
2. FPSMesh의 Location과 Rotation 변경
    - Location: 50, -15, -150
    - Rotation: 0, 25, 350

