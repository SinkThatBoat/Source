// Fill out your copyright notice in the Description page of Project Settings.

#include "sinkthatboat.h"
#include "Elephant.h"


//Constructor
AElephant::AElephant() {
	_Cooldown = ELEPHANT_COOLDOWN;
	setSpeed(ELEPHANT_SPEED);
	_Weight = ELEPHANT_WEIGHT;
}

