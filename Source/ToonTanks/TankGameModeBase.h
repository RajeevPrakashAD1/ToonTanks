// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	void ActorDied(AActor* DeadActor);
protected:
	virtual void BeginPlay() override;
private:
	class ATankPlayerController* TankPlayerCtrl;
	float StartDelay = 3.f;
	void HandleGameStart();
};