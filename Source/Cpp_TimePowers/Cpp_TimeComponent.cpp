// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_TimeComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UCpp_TimeComponent::UCpp_TimeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UCpp_TimeComponent::BeginPlay()
{
	Super::BeginPlay();

	// Get Time GameMode
	ACpp_TimeGameMode* GameMode = Cast<ACpp_TimeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode) {
		TimeManager = GameMode->GetTimeManager();
	}

	if (!TimeManager) {
		UE_LOG(LogTemp, Warning, TEXT("Actor \"%s\" Failed To Receive Global Time Manager"), *GetName())
	}
}
