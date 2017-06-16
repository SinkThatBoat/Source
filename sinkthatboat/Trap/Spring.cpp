// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "Spring.h"

void ASpring::throwAnimals() {
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (int32 i = 0; i < Actors.Num(); ++i) {
		AAnimal *Animal = Cast<AAnimal>(Actors[i]);
		//Doesn't launch elephants & traps
		if (Animal && !Cast<AElephant>(Animal)) {
			Animal->GetMovementComponent()->StopMovementImmediately();
			Animal->LaunchCharacter(FVector(SPRING_THROW, 0, SPRING_THROW), false, false);
		}
	}
}