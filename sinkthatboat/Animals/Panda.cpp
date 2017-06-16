// Fill out your copyright notice in the Description page of Project Settings.

#include "sinkthatboat.h"
#include "Panda.h"


//Constructor
APanda::APanda() {
	_Weight = SEAL_WEIGHT;
	_Cooldown = SEAL_COOLDOWN;
	setSpeed(SEAL_SPEED);
}

