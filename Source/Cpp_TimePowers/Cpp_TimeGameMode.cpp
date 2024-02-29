// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_TimeGameMode.h"

void ACpp_TimeGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) {

	Super::InitGame(MapName, Options, ErrorMessage);

	// Init TimeManager
	TimeManager = Cast<ACpp_TimeManager>(GetWorld()->SpawnActor(ACpp_TimeManager::StaticClass()));
	if (!TimeManager) {
		UE_LOG(LogTemp, Error, TEXT("Failed To Create Cpp_TimeManager"));
	}
}

ACpp_TimeManager* ACpp_TimeGameMode::GetTimeManager()
{
	// Check if TimeManager isn't null
	if (!TimeManager) {
		UE_LOG(LogTemp, Error, TEXT("Tried To Call GetTimeManager() BEFORE IT EXISTS!"));
	}
	return TimeManager;
}
