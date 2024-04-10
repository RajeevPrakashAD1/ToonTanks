// Fill out your copyright notice in the Description page of Project Settings.


#include "BhagwanPawn.h"
#include "Components/CapsuleComponent.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ABhagwanPawn::ABhagwanPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//creating componets decalared in .h
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));

	BaseMesh->SetupAttachment(CapsuleComp);
	TurretMesh->SetupAttachment(BaseMesh);
	
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);


}


void ABhagwanPawn::RotateTurret(FVector Target) {
	FVector toTarget = Target- TurretMesh->GetComponentLocation() ;
	FRotator LookAtRotation = FRotator(0,toTarget.Rotation().Yaw,0);
	TurretMesh->SetWorldRotation(FMath::RInterpTo(

		TurretMesh->GetComponentRotation(),
		LookAtRotation,
		UGameplayStatics::GetWorldDeltaSeconds(this),
		5
	
	));
	//UE_LOG(LogTemp, Display, TEXT("calling rotation"));


}

void ABhagwanPawn::Fire() {

	FVector Location = ProjectileSpawnPoint->GetComponentLocation();
	FRotator Rotation = ProjectileSpawnPoint->GetComponentRotation();
	GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
}


