#include "Debug.h"

void Debug::Log(FString value){
	UE_LOG(LogClass, Log, TEXT("%s"), *value);
}

void Debug::Log(float value) {
	UE_LOG(LogClass, Log, TEXT("%s"), *FString::SanitizeFloat(value));
}

void Debug::Log(int value) {
	UE_LOG(LogClass, Log, TEXT("%s"), *FString::FromInt(value));
}

void Debug::Log(bool value) {
	UE_LOG(LogClass, Log, TEXT("%s"), *(value ? FString("true") : FString("false")));
}

void Debug::Error(FString value) {
	UE_LOG(LogClass, Error, TEXT("%s"), *value);
}

void Debug::Error(float value) {
	UE_LOG(LogClass, Error, TEXT("%s"), *FString::SanitizeFloat(value));
}

void Debug::Error(int value) {
	UE_LOG(LogClass, Error, TEXT("%s"), *FString::FromInt(value));
}

void Debug::Error(bool value) {
	UE_LOG(LogClass, Error, TEXT("%s"), *(value ? FString("true") : FString("false")));
}


void Debug::Warning(FString value) {
	UE_LOG(LogClass, Warning, TEXT("%s"), *value);
}

void Debug::Warning(float value) {
	UE_LOG(LogClass, Warning, TEXT("%s"), *FString::SanitizeFloat(value));
}

void Debug::Warning(int value) {
	UE_LOG(LogClass, Warning, TEXT("%s"), *FString::FromInt(value));
}

void Debug::Warning(bool value) {
	UE_LOG(LogClass, Warning, TEXT("%s"), *(value ? FString("true") : FString("false")));
}

