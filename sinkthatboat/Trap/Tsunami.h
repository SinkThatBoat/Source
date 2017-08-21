// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Trap/Trap.h"
#include "Tsunami.generated.h"

/**
 * 
 */
UCLASS()
class SINKTHATBOAT_API ATsunami : public ATrap
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void spawn(const FVector& location);

private:
	UFUNCTION()
	void moveForward();

};

	

