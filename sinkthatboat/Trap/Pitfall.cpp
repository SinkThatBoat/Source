// Fill out your copyright notice in the Description page of Project Settings.

#include "sinkthatboat.h"
#include "Pitfall.h"



APitfall::APitfall() {

}


// Called every frame
void APitfall::Tick(float DeltaTime) {
	
	//Catch all the animals
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (auto& Actor : Actors) {
		AAnimal *Animal = Cast<AAnimal>(Actor);
		if (Animal  && !Cast<AChicken>(Actor)) {
			FVector position = Animal->GetActorLocation();
			position.Z -= 100;
			Animal->SetActorLocation(position);
		}
	}
}