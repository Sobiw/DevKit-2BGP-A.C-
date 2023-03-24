// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLightSwitch.h"

// Sets default values
AMyLightSwitch::AMyLightSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetActorEnableCollision(true);

	this->SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision Component"));
	this->SphereCollider->InitSphereRadius(300.0f);
	this->SphereCollider->SetGenerateOverlapEvents(true);
	this->SphereCollider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));


	this->SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &AMyLightSwitch::OnOverlapBegin);

	this->SphereCollider->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyLightSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyLightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyLightSwitch::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult)
{
	UMyBlueprintFunctionLibrary::ToggleAllLights();
}
