// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MathUtil.h"
#include "GameFramework/Actor.h"
#include "Cpp_TimeManager.generated.h"

UCLASS()
class CPP_TIMEPOWERS_API ACpp_TimeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACpp_TimeManager();

	// Event Tick
	void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Time")
	float GetTimeDilation();

	UFUNCTION(BlueprintCallable, Category = "Time")
	bool GetTimeControlStatus();

	UFUNCTION(BlueprintCallable, Category = "Time")
	float GetCurrentRecordedTime() const { return currentRecordedTime;}

	// Time Control Functions
	UFUNCTION(BlueprintCallable, Category = "Time")
	void BeginReverseTime();
	UFUNCTION(BlueprintCallable, Category = "Time")
	void EndReverseTime();

	// Time Control
	UFUNCTION(BlueprintCallable, Category = "Time")
	void EnableTimeControl();
	UFUNCTION(BlueprintCallable, Category = "Time")
	void DisableTimeControl();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	// Current time dilation
	UPROPERTY(BlueprintReadOnly, Category = "Time")
	float currentTimeDilation = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Time")
	float currentRecordedTime = 0.0f;

	// State Helper
	UPROPERTY(BlueprintReadOnly, Category = "Time")
	bool bIsTimeControlEnabled = false;

public:
	// Time Magic Values
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float normalTimeFactor = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float reverseTimeFactor = -3.0f;

	// Reversing Time Thresholds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float reverseTimeMin = 3.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float reverseTimeMax = 15.0f;
};
