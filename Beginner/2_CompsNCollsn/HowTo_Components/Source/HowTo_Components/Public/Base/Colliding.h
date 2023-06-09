// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "UObject/ConstructorHelpers.h"

#include "CollidingPawnMovementComponent.h"

#include "Colliding.generated.h"

UCLASS()
class HOWTO_COMPONENTS_API AColliding : public APawn
{
	GENERATED_BODY()

public:
	void InitSphere();

	void InitMeshParticle();

	void InitSpringCamera();

public:
	// Sets default values for this pawn's properties
	AColliding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	class UParticleSystemComponent* OurParticleSystem;

	UPROPERTY()
	class UCollidingPawnMovementComponent* OurMovementComponent;

	virtual UPawnMovementComponent* GetMovementComponent() const override;

	void MoveForward(float AxisValue);

	void MoveRight(float AxisValue);

	void Turn(float AxisValue);

	void ParticleToggle();

};
