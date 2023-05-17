// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/Colliding.h"

// Sets default values
AColliding::AColliding()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitSphere();

	InitMeshParticle();

	InitSpringCamera();

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	OurMovementComponent = CreateDefaultSubobject<UCollidingPawnMovementComponent>(TEXT("CustomMovementComponent"));
	OurMovementComponent->UpdatedComponent = RootComponent;

}

void AColliding::InitSphere()
{
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));
}

void AColliding::InitMeshParticle()
{
	// Static Mesh
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->SetupAttachment(RootComponent);
	// static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	// if(SphereVisualAsset.Succeeded())
	// {
	// 	SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
	// }
	SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
	SphereVisual->SetWorldScale3D(FVector(0.8f));

	// Particle
	OurParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MovementParticles"));
	OurParticleSystem->SetupAttachment(SphereVisual);
	OurParticleSystem->bAutoActivate = false;
	OurParticleSystem->SetRelativeLocation(FVector(-20.0f, 0.0f, 20.0f));
	// static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
	// if(ParticleAsset.Succeeded())
	// {
	// 	OurParticleSystem->SetTemplate(ParticleAsset.Object);
	// }
}

void AColliding::InitSpringCamera()
{
	// Spring Arm Component
	USpringArmComponent*  SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	// Camera Component
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void AColliding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColliding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AColliding::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(FName("ParticleToggle"), IE_Pressed, this, &AColliding::ParticleToggle);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AColliding::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &AColliding::MoveRight);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AColliding::Turn);

}

UPawnMovementComponent* AColliding::GetMovementComponent() const
{
	return OurMovementComponent;
}

void AColliding::MoveForward(float AxisValue)
{
	if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
	{
		OurMovementComponent->AddInputVector(GetActorForwardVector() * AxisValue);
	}
}

void AColliding::MoveRight(float AxisValue)
{
	if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
	{
		OurMovementComponent->AddInputVector(GetActorRightVector() * AxisValue);
	}
}

void AColliding::Turn(float AxisValue)
{
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += AxisValue;
	SetActorRotation(NewRotation);	
}

void AColliding::ParticleToggle()
{
	if (OurParticleSystem && (OurParticleSystem->Template))
	{
		OurParticleSystem->ToggleActive();
	}
}