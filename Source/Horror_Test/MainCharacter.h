#pragma once

#include "Components/SpotLightComponent.h"
#include "Components/InputComponent.h"
#include "Horror_Test/Flashlight.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class HORROR_TEST_API AMainCharacter : public ACharacter {
	GENERATED_BODY( )

	public:
	// Sets default values for this character's properties
	AMainCharacter( );

	UPROPERTY(BlueprintReadWrite, Category = "Info") USpotLightComponent* m_SpotLight;
	UPROPERTY(BlueprintReadWrite, Category = "Info") AFlashlight* m_flashlight;
	UPROPERTY(BlueprintReadWrite, Category = "Info") bool b_state;

	private:
	float f_maxIntenisty;
	float f_minIntenisty;

	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay( ) override;

	public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION( ) void MoveForward(float Value);

	// Handles input for moving right and left.
	UFUNCTION( ) void MoveRight(float Value);

	void ChangeStateFlashLight( );
	void RestoreChargeFlashLight( );
};
