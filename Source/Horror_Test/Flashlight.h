// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SpotLightComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Flashlight.generated.h"

UCLASS()
class HORROR_TEST_API AFlashlight : public AActor {
	GENERATED_BODY( )

	public:
	// Sets default values for this actor's properties
	AFlashlight( );

	UPROPERTY(BlueprintReadWrite, Category = "Info") USpotLightComponent* m_SpotLight;
	UPROPERTY(EditAnywhere, Category = "Info") bool b_state = false;
	UPROPERTY(EditAnywhere, Category = "Info") float m_maxCharge;
	UPROPERTY(EditAnywhere, Category = "Info") float m_minCharge = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Info") float m_charge;
	UPROPERTY(EditAnywhere, Category = "Info") float m_timer;

	UPROPERTY(EditAnywhere, Category = "Light") float m_intensity;
	UPROPERTY(EditAnywhere, Category = "Light") float m_innerAngle;
	UPROPERTY(EditAnywhere, Category = "Light") float m_outerAngle;
	UPROPERTY(EditAnywhere, Category = "Light") float m_attenuationRadius;
	UPROPERTY(EditAnywhere, Category = "Light") FLinearColor m_color;

	private:
	UStaticMeshComponent* m_MeshComponent;
	float m_timer_temp;
	bool m_active = true;

	void DownCharger( );
	void setFlashLightActive(bool);
	void changeColor( );

	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay( ) override;

	public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	#endif

	void Initialization( );
	void OnOffFlashLight( );
	void RestoreCharge(float);
};
