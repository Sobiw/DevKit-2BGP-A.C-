// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class DEVKIT_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Custom CPP Editor Function Library v2")
		static void Print(FString message);


	UFUNCTION(BlueprintCallable, Category = "Custom CPP Editor Function Library")
		static void ToggleAllLights();

	UFUNCTION(BlueprintCallable, Category = "Custom CPP Editor Function Library")
		static int ReturnStuff(
			const FString inputValue,
			FString& result_out1,
			FString& result_out2
		);
	
};
