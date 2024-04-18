// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include <Kismet/GameplayStatics.h>
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	RootComponent = ProjectileMesh;
	movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("movement"));
	TrailParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("TrailParticles"));
	TrailParticles->SetupAttachment(RootComponent);
	movement->MaxSpeed = 3000;
	movement->InitialSpeed = 2500;



}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("setting up ad dynamics"));
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	if(LaunchSound) UGameplayStatics::PlaySoundAtLocation(this, LaunchSound, GetActorLocation());
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent* HitComp,AActor* otherActor,UPrimitiveComponent* OtherComp,FVector NormalImpule,const FHitResult& Hit)
{

	UE_LOG(LogTemp, Warning, TEXT("Onhit"));
	auto MyOwner = GetOwner();
	if (MyOwner == nullptr) 
	{
		Destroy(); 
		return;
	}
	auto instigator =  MyOwner->GetInstigatorController();
	auto DamageTypeClass = UDamageType::StaticClass();

	if (otherActor && otherActor != this && otherActor != MyOwner) {
		UGameplayStatics::ApplyDamage(otherActor, Damage, instigator, this, DamageTypeClass);
		UGameplayStatics::SpawnEmitterAtLocation(this, HitEffect,GetActorLocation());
		if (HitSound) UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
		Destroy();
	}
	
	//
	//ApplyDamage()

}
