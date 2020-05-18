// Fill out your copyright notice in the Description page of Project Settings.


#include "Flashlight.h"
#include "Horror_Test/Debug.h"

// Sets default values
AFlashlight::AFlashlight( ) {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*
	m_MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FlashLightBody"));
	m_MeshComponent->SetWorldScale3D(FVector(2.f, 2.0f, 2.f));
	RootComponent = m_MeshComponent;
	*/

	m_SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	m_SpotLight->AttachTo(RootComponent);
	m_SpotLight->InnerConeAngle = m_innerAngle;
	m_SpotLight->OuterConeAngle = m_outerAngle;
	m_SpotLight->Intensity = m_intensity;
	m_SpotLight->SetRelativeLocation(FVector(10.0f, 0.0f, 0.0f));
	m_SpotLight->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	m_SpotLight->SetVisibility(true);
	m_SpotLight->SetLightColor(m_color);
	m_SpotLight->SetActive(true);
}

// Called when the game starts or when spawned
void AFlashlight::BeginPlay( ) {
	Super::BeginPlay( );
}

// Called every frame
void AFlashlight::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	Debug::Log(m_SpotLight->Intensity);
	Debug::Log(m_SpotLight->InnerConeAngle);
	Debug::Log(m_SpotLight->OuterConeAngle);
}

#if WITH_EDITOR
void AFlashlight::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) {
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void AFlashlight::ChangeStateFlashLight( ) {
	b_state = !b_state;

	if (m_SpotLight != NULL) m_SpotLight->ToggleVisibility(b_state);
	else Debug::Error(FString("m_SpotLight not found!"));
}

