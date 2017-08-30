#pragma once
/**
 * SinkThatBoat's macros
 **/
 
// Debug message display time
#define DEBUG_TIME 5.f
 
// Print to screen macro
#define DEBUG(x) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, DEBUG_TIME, FColor::Yellow, TEXT(x)); 
#define DEBUG_INT(x) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, DEBUG_TIME, FColor::Yellow, FString::FromInt(x)); 
#define DEBUG_BOOL(x) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, DEBUG_TIME, FColor::Yellow, TEXT(x?"True":"False")); 
#define DEBUG_FLOAT(x) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, DEBUG_TIME, FColor::Yellow, FString::Printf(TEXT("%f"), x)); 
#define DEBUG_VECTOR(x) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, DEBUG_TIME, FColor::Yellow, FString::Printf(TEXT("Vector(x : %f ; y : %f ; z : %f ;)"), x.X, x.Y, x.Z)); 
