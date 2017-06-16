// Fill out your copyright notice in the Description page of Project Settings.

#include "sinkthatboat.h"
#include "Pitfall.h"



APitfall::APitfall() {

}


// Called every frame
void APitfall::Tick(float DeltaTime) {
	
	//Catch all the animals
	TArray<AActor*> Actors;
	getOverlappingActors(Actors);

	for (auto& Actor : Actors) {
		AAnimal *Animal = Cast<AAnimal>(Actor);
		if (Animal) {
			FVector position = Animal->GetActorLocation();
			position.Y -= 1;
			Animal->SetActorLocation(position);
		}
	}
}