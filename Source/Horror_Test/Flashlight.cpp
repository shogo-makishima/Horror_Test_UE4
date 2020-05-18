// Fill out your copyright notice in the Description page of Project Settings.


#include "Flashlight.h"
#include "Horror_Test/Debug.h"
#include "Math/UnrealMathUtility.h"

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
	// m_SpotLight->AttachTo(RootComponent);
	m_SpotLight->SetRelativeLocation(FVector(10.0f, 0.0f, 0.0f));
	m_SpotLight->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	
}

void AFlashlight::Initialization( ) {
	m_SpotLight->InnerConeAngle = m_innerAngle;
	m_SpotLight->OuterConeAngle = m_outerAngle;
	m_SpotLight->Intensity = m_intensity;
	m_SpotLight->AttenuationRadius = m_attenuationRadius;

	m_SpotLight->SetLightColor(m_color);

	m_SpotLight->SetVisibility(false);
	m_SpotLight->SetActive(true);
}

// Called when the game starts or when spawned
void AFlashlight::BeginPlay( ) {
	Super::BeginPlay( );
	
	m_charge = m_maxCharge;
	m_timer_temp = m_timer;
	m_active = true;

	Initialization( );
}

// Called every frame
void AFlashlight::Tick(float DeltaTime) {
	if (m_charge > 0 && m_SpotLight->IsVisible( )) {
		m_timer -= DeltaTime;

		if (m_timer <= 0) {
			DownCharger( );
			changeColor( );
			m_timer = m_timer_temp;
		}
	}

	Super::Tick(DeltaTime);
}

#if WITH_EDITOR
void AFlashlight::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) {
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void AFlashlight::RestoreCharge(float value = NULL) {
	if (value == NULL) m_charge = m_maxCharge;
	else {
		if (value + m_charge > m_maxCharge) m_charge = m_maxCharge;
		else m_charge += value;
	}
}

void AFlashlight::OnOffFlashLight( ) {
	if (m_charge <= 0) setFlashLightActive(false);
	else if (m_charge > 0) setFlashLightActive(!m_SpotLight->IsVisible( ));
	
}

void AFlashlight::setFlashLightActive(bool value) {
	if (m_SpotLight != NULL) m_SpotLight->SetVisibility(value);
	else Debug::Error(FString("m_SpotLight not found!"));
}

void AFlashlight::changeColor( ) {
	Debug::Log(FMath::Lerp(m_minCharge, m_maxCharge, m_charge));
}

void AFlashlight::DownCharger( ) {
	if (m_charge >= 1) m_charge--;
	if (m_charge <= 0) setFlashLightActive(false);

	Debug::Log(m_charge);
}