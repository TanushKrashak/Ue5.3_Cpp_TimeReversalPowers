// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_TimeManager.h"

// Sets default values
ACpp_TimeManager::ACpp_TimeManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Event Tick
void ACpp_TimeManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	// Store Recorded Time
	if (bIsTimeControlEnabled) {
		// Update the recorded time
		currentRecordedTime = TMathUtil<float>::Min(reverseTimeMax, currentRecordedTime + DeltaTime * currentTimeDilation);
		// Just in case the time is less than 0
		if (currentRecordedTime <= 0.0f) {
			EndReverseTime();
			currentRecordedTime = 0.0f;
		}
	}
}

// Called when the game starts or when spawned
void ACpp_TimeManager::BeginPlay()
{
	Super::BeginPlay();

	// Apply Normal Time Factor
	currentTimeDilation = normalTimeFactor;
}

// Gets the current time dilation
float ACpp_TimeManager::GetTimeDilation() {
	return currentTimeDilation;
}

// Gets whether the time control is enabled
bool ACpp_TimeManager::GetTimeControlStatus()
{
	return bIsTimeControlEnabled && currentRecordedTime >= reverseTimeMin;
}

// Enables the reversal of Time
void ACpp_TimeManager::BeginReverseTime() {
	if (GetTimeControlStatus())
		currentTimeDilation = reverseTimeFactor;
}

// Disables the reversal of Time
void ACpp_TimeManager::EndReverseTime() {
	currentTimeDilation = normalTimeFactor;
}

// Enables the time control
void ACpp_TimeManager::EnableTimeControl() {
	if (!bIsTimeControlEnabled) {
		bIsTimeControlEnabled = true;
	}
}

// Disables the time control
void ACpp_TimeManager::DisableTimeControl() {
	if (bIsTimeControlEnabled) {
		EndReverseTime();
		bIsTimeControlEnabled = false;
		currentRecordedTime = 0.0f;
	}
}


