// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BhagwanPawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABhagwanPawn
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
	void HandleDestruction();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	class ATank* tank;
	UPROPERTY(EditAnywhere)
	float FireRange= 900.f;

	FTimerHandle FireRateTimeHandle;
	float FireRate = 2.f;
	void checkFireCondition();

};
