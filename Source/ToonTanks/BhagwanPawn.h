
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Projectile.h"
#include "BhagwanPawn.generated.h"


UCLASS()
class TOONTANKS_API ABhagwanPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABhagwanPawn();
	void HandleDestruction();


protected:
	void RotateTurret(FVector Target);
	void Fire();

	// Called to bind functionality to input
	
private:

	//defining different type of components to attach to base pawn
	//class Ucapsuele... is called forward decalaration where decalartion of header file id done where it us used
	//
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Component",meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AProjectile> ProjectileClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AProjectile> ProjectileClass2;

	UPROPERTY(EditAnyWhere)
	class UParticleSystem* DeathParticles;
	UPROPERTY(EditAnyWhere)
	class USoundBase* DeathSound;

};
