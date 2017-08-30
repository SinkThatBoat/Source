// Fill out your copyright notice in the Description page of Project Settings.

#include "sinkthatboat.h"
#include "Seal.h"


//Constructor
ASeal::ASeal() {
	setSpeed(SEAL_SPEED);
	m_Weight = SEAL_WEIGHT;
	m_Cooldown = SEAL_COOLDOWN;
}

