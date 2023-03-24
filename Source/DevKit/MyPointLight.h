// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/PointLightComponent.h"

#include "MyPointLight.generated.h"



UCLASS()
class DEVKIT_API AMyPointLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPointLight();

	UPROPERTY(EditAnywhere, Category = "Custom light")
		float Intensity;

	UPROPERTY(EditAnywhere, Category = "Custom Light")
		bool IsVisibleAtStart;

	UPROPERTY(VisibleAnywhere, Category = "Custom light")
		UPointLightComponent* PointLight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Custom Light")
		virtual void ToggleLight();

};
