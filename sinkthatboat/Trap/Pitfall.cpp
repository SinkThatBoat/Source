// Fill out your copyright notice in the Description page of Project Settings.

#include "sinkthatboat.h"
#include "Pitfall.h"



APitfall::APitfall() {
	m_Content = 0;
}



// Called every frame
void APitfall::Tick(float DeltaTime) {
	
	Super::Tick(DeltaTime);

	//Catch all the overlapped animals
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (auto& Actor : Actors) {
		AAnimal *Animal = Cast<AAnimal>(Actor);
		if (Animal  && !Cast<AChicken>(Actor)) {
			FVector position = Animal->GetActorLocation();
			position.Z -= 100;
			Animal->SetActorLocation(position);

			if (!Animal->isDead()) {
				Animal->kill();
				m_Content++;
			}				
		}
	}


	if (m_Content > PITFALL_LIFE) {
		freePlace(m_Index);
		Destroy();
	}
}