// 2017 . All rights reserved StB 

#include "sinkthatboat.h"
#include "ANIM_Animal.h"
#include "Animals/Animal.h"


AAnimal* UANIM_Animal::getAnimal() const {
	return Cast<AAnimal>(TryGetPawnOwner());
}

void UANIM_Animal::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	// Update the speed of the animal
	const AAnimal* const Animal = getAnimal();
	if (Animal) {
		m_Speed = Animal->GetVelocity().Size();
	}
}