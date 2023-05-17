// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"

#include "ComMovementComponent.h"

#include "MovingCamDirector.generated.h"

UCLASS()
class HOWTO_AUTOCAMERA_API AMovingCamDirector : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMovingCamDirector();

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY()
	class UCamMovementComponent* CamMovementComponent;

	FVector Left = FVector(0.0f, -100.0f, 0.0f);

	FVector Center = FVector(0.0f, 0.0f, 0.0f);

	FVector Right = FVector(0.0f, 100.0f, 0.0f);

	void InitSpringCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UCamMovementComponent* GetCamMovementComponent() const override;

public:
	// Change Camera Location by Component
	void ChangeCamLeft();

	void ChangeCamCenter();

	void ChangeCamRight();

};
