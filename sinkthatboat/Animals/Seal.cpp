// Fill out your copyright notice in the Description page of Project Settings.

#include "sinkthatboat.h"
#include "Seal.h"


//Constructor
ASeal::ASeal() {
	setSpeed(SEAL_SPEED);
	_Weight = SEAL_WEIGHT;
	_Cooldown = SEAL_COOLDOWN;
}

