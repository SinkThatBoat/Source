// Fill out your copyright notice in the Description page of Project Settings.

#include "sinkthatboat.h"
#include "Pitfall.h"



void APitfall::resetCooldown() {
	_Cooldown = PITFALL_COOLDOWN;
}


APitfall::APitfall() {
	resetCooldown();
}


