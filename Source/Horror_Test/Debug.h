#include "CoreMinimal.h"

class HORROR_TEST_API Debug {
	public:
	UFUNCTION(BlueprintCallable) static void Log(FString);
	UFUNCTION(BlueprintCallable) static void Log(int);
	UFUNCTION(BlueprintCallable) static void Log(float);
	UFUNCTION(BlueprintCallable) static void Log(bool);

	UFUNCTION(BlueprintCallable) static void Error(FString);
	UFUNCTION(BlueprintCallable) static void Error(int);
	UFUNCTION(BlueprintCallable) static void Error(float);
	UFUNCTION(BlueprintCallable) static void Error(bool);
};
