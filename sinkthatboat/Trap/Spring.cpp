// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "Spring.h"

void ASpring::throwAnimals() {
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (auto& Actor : Actors) {
		AAnimal *Animal = Cast<AAnimal>(Actor);

		//Doesn't launch elephants & traps
		if (Animal && !Cast<AElephant>(Animal)) {
			Animal->GetMovementComponent()->StopMovementImmediately();
			Animal->LaunchCharacter(FVector(SPRING_THROW, 0, SPRING_THROW), false, false);
			freePlace(m_Index);
		}
	}
}