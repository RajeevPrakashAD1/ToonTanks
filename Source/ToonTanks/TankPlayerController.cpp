// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::SetPlayerEnabledState(bool playerEnabled)
{
	if (playerEnabled)
	{
		GetPawn()->EnableInput(this);

	}
	else
	{
		GetPawn()->DisableInput(this);
	}
	bShowMouseCursor = playerEnabled;

}