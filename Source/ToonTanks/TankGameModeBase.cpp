// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"

#include "Tank.h"
#include "Tower.h"

#include <Kismet/GameplayStatics.h>
#include "TankPlayerController.h"

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{

	if (ATank* DestroyedEntity = Cast<ATank>(DeadActor))
	{
		DestroyedEntity->HandleDestruction();
		if (TankPlayerCtrl)
		{
			TankPlayerCtrl->SetPlayerEnabledState(false);
		}
			
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
	}
}

void ATankGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
}

void ATankGameModeBase::HandleGameStart()
{

	TankPlayerCtrl = Cast<ATankPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (TankPlayerCtrl)
	{
		TankPlayerCtrl->SetPlayerEnabledState(false);
		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
			TankPlayerCtrl,
			&ATankPlayerController::SetPlayerEnabledState,
			true
		);

		GetWorldTimerManager().SetTimer(
			PlayerEnableTimerHandle,
			PlayerEnableTimerDelegate,
			StartDelay,
			false
		);
	}
}