// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animals/Chicken.h"
#include "Trap/Trap.h"
#include "Pitfall.generated.h"

/**
 * 
 */
UCLASS()
class SINKTHATBOAT_API APitfall : public ATrap {
	GENERATED_BODY()
	
public:
	APitfall();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	int m_Content;

};