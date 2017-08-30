// Fill out your copyright notice in the Description page of Project Settings.

#include "sinkthatboat.h"
#include "Panda.h"


//Constructor
APanda::APanda() {
	m_Weight = SEAL_WEIGHT;
	m_Cooldown = SEAL_COOLDOWN;
	setSpeed(SEAL_SPEED);
}

