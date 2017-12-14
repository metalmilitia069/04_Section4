// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is Used to Set Maximum Driving Force and to Apply Forces to the Tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Sets a Throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	//MAX FORCE PER TRACK IN NEWTONS
	UPROPERTY(EditAnywhere, Category = TankTrack)
	float TrackMaxDrivingForce = 400000.f; //Assume 40 tons tank and 1g accelleration
	
	
};
