// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingCamDirector.h"

void AMovingCamDirector::InitSpringCamera()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(FName("Spring Arm Component"));
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(FName("MovingCam"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

// Sets default values
AMovingCamDirector::AMovingCamDirector()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitSpringCamera();

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	CamMovementComponent = CreateDefaultSubobject<UCamMovementComponent>(FName("Camera Movement Component"));
	CamMovementComponent->UpdatedComponent = Camera;

}

// Called when the game starts or when spawned
void AMovingCamDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingCamDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMovingCamDirector::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Move Cam to Left", IE_Pressed, Camera, &AMovingCamDirector::ChangeCamLeft);
	PlayerInputComponent->BindAction("Move Cam to Center", IE_Pressed, Camera, &AMovingCamDirector::ChangeCamCenter);
	PlayerInputComponent->BindAction("Move Cam to Right", IE_Pressed, Camera, &AMovingCamDirector::ChangeCamRight);

}

UCamMovementComponent* AMovingCamDirector::GetCamMovementComponent() const
{
	return CamMovementComponent;
}

void AMovingCamDirector::ChangeCamLeft()
{
	if (CamMovementComponent && (CamMovementComponent->UpdatedComponent == Camera))
	{
		Camera->SetRelativeLocation(Left);
	}
}

void AMovingCamDirector::ChangeCamCenter()
{
	if (CamMovementComponent && (CamMovementComponent->UpdatedComponent == Camera))
	{
		Camera->SetRelativeLocation(Center);
	}
}

void AMovingCamDirector::ChangeCamRight()
{
	if (CamMovementComponent && (CamMovementComponent->UpdatedComponent == Camera))
	{
		Camera->SetRelativeLocation(Right);
	}
}