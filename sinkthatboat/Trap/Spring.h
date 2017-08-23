// 2017 . All rights reserved StB 

#pragma once

#include "Animals/Elephant.h"
#include "Trap/Trap.h"
#include "Spring.generated.h"

/**
 * 
 */
UCLASS()
class SINKTHATBOAT_API ASpring : public ATrap
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void throwAnimals();
	
};
