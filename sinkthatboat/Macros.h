/**
 * SinkThatBoat's macros
 **/
 
//Print to screen macro
#define DEBUG(x) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT(x)); 
#define DEBUG_INT(x) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::FromInt(x)); 
#define DEBUG_FLOAT(x) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("%f"), x)); 
