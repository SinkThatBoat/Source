// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Trap/Trap.h"
#include "Pitfall.generated.h"

/**
 * 
 */
UCLASS()
class SINKTHATBOAT_API APitfall : public ATrap
{
	GENERATED_BODY()
	
public:
	APitfall();

private:
	UFUNCTION(BlueprintCallable)
	void throwPitfall();

};