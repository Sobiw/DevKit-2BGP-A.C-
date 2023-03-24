// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPointLight.h"

// Sets default values
AMyPointLight::AMyPointLight()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->Intensity = 3000.0f;

	this->PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	this->PointLight->Intensity = this->Intensity;
	this->PointLight->SetVisibility(true);
	this->PointLight->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyPointLight::BeginPlay()
{
	Super::BeginPlay();
	
	this->PointLight->SetVisibility(this->IsVisibleAtStart);
}

// Called every frame
void AMyPointLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPointLight::ToggleLight()
{
	this->PointLight->ToggleVisibility();
}

