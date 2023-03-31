""// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include <Kismet/gameplayStatics.h>
#include "Engine/World.h"
#include  "MyPointLight.h"

void UMyBlueprintFunctionLibrary::Print(FString message)
{
#if UE_EDITOR
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, message);

#endif
	UE_LOG(LogTemp, Log, TEXT("%s"), *message);
}


void UMyBlueprintFunctionLibrary::ToggleAllLights()
{

	Print("[LIGHTS] Will switch all light...");


	UWorld* world = GEngine->GameViewport->GetWorld();

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(
		world,
		AMyPointLight::StaticClass(),
		Actors
	);

	for (AActor* tmpActor : Actors)
	{
		((AMyPointLight*)tmpActor)->ToggleLight();
	}

	Print("[LIGHTS] Done switching all lights.");
}

int UMyBlueprintFunctionLibrary::ReturnStuff(const FString inputValue, FString& result_out1, FString& result_out2)
{
	result_out1 = inputValue;
	result_out2 = "Diantre";
	return 3;
}
