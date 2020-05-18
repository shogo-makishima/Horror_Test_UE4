// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Horror_Test/Debug.h"


// Sets default values
AMainCharacter::AMainCharacter( ) {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned
void AMainCharacter::BeginPlay( ) {
	Super::BeginPlay( );
}


// Called every frame
void AMainCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}


void AMainCharacter::ChangeStateFlashLight( ) {
	if (m_flashlight != NULL) m_flashlight->ChangeStateFlashLight( );
	else Debug::Error(FString("m_flashlight not found!"));

	/*b_state = !b_state;

	if (m_SpotLight != NULL) m_SpotLight->ToggleVisibility(b_state);
	else Debug::Error(FString("m_SpotLight not found!"));*/
}


// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("Vertical", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Horizontal", this, &AMainCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Mouse X", this, &AMainCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Mouse Y", this, &AMainCharacter::AddControllerPitchInput);

	// Set up "action" bindings.
	PlayerInputComponent->BindAction("ChageStateFlashlight", IE_Pressed, this, &AMainCharacter::ChangeStateFlashLight);
	// PlayerInputComponent->BindAction("ChageStateFlashlight", IE_Pressed, this, &AFlashlight::ChangeStateFlashLight);
}


void AMainCharacter::MoveForward(float Value) {
	FVector Direction = FRotationMatrix(Controller->GetControlRotation( )).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}


void AMainCharacter::MoveRight(float Value) {
	FVector Direction = FRotationMatrix(Controller->GetControlRotation( )).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

