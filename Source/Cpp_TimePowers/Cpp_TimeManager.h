// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cpp_TimeManager.generated.h"

UCLASS()
class CPP_TIMEPOWERS_API ACpp_TimeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACpp_TimeManager();

	UFUNCTION(BlueprintCallable, Category = "Time")
	float GetTimeDilation();

	// Time Control Functions
	UFUNCTION(BlueprintCallable, Category = "Time")
	void BeginReverseTime();
	UFUNCTION(BlueprintCallable, Category = "Time")
	void EndReverseTime();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	// Current time dilation
	UPROPERTY(BlueprintReadOnly, Category = "Time")
	float currentTimeDilation = 1.0f;

	// Time Magic Values
	UPROPERTY(BlueprintReadWrite, Category = "Time")
	float normalTimeFactor = 1.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Time")
	float reverseTimeFactor = -3.0f;
};
