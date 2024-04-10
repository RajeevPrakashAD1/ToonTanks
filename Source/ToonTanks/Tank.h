// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BhagwanPawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABhagwanPawn
{
	GENERATED_BODY()

public:
	ATank();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere)
	float Speed = 500.f;
	void Move(float Value);

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 45.f;
	void Turn(float Value);

	APlayerController* PlayerControllerRef;
};
