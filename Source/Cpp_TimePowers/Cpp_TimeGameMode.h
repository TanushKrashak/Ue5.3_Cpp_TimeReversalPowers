// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Cpp_TimePowers/Cpp_TimeManager.h"
#include "GameFramework/GameModeBase.h"
#include "Cpp_TimeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CPP_TIMEPOWERS_API ACpp_TimeGameMode : public AGameModeBase {
	GENERATED_BODY()
	
public:
	// Called Before Actor Initialization
	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;


public:
	// Get Global Time Manager
	UFUNCTION(BlueprintPure, Category = "Time")
	ACpp_TimeManager* GetTimeManager();


protected:
	UPROPERTY(BlueprintReadOnly, Category = "Time")
	ACpp_TimeManager *TimeManager = nullptr;
};
