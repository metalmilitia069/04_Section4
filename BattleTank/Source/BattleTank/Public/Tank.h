// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward Declarations
//class UTankTurret;
class UTankBarrel;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;


private:
	ATank();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Setup)
	// UClass* ProjectileBlueprint; // There is an alternative to use this. Look at unreal documentation. This option makes ALL UNREAL CLASS available for choose at the new property bar
	TSubclassOf<AProjectile> ProjectileBlueprinto;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000; // ?? m/s

	UPROPERTY(EditAnywhere, Category = Firing)
	float ReloadTimeInSeconds = 3.f;

	
	UTankBarrel* Barrel = nullptr; // Local Barrel Reference for spawning projectile

	
	double LastFireTime = 0;

};
