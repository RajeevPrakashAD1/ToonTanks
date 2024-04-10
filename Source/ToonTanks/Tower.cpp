// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include <Kismet/GameplayStatics.h>

void ATower::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);
	//Find the distance to the tank
	// 
	//
	if (tank) {
		float Distance = FVector::Dist(GetActorLocation(), tank->GetActorLocation());
		if (Distance <= FireRange) {
			//rotate
			RotateTurret(tank->GetActorLocation());
			//shoot
			//hello
		}
	}

}

void ATower::BeginPlay() {
	Super::BeginPlay();
	tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorldTimerManager().SetTimer(FireRateTimeHandle, this, &ATower::checkFireCondition, FireRate, true);
}

void ATower::checkFireCondition() {
	if (tank) {
		float Distance = FVector::Dist(GetActorLocation(), tank->GetActorLocation());
		if (Distance <= FireRange) {
			Fire();
		}
	}
}