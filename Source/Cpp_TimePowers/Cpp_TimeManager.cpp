// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_TimeManager.h"

// Sets default values
ACpp_TimeManager::ACpp_TimeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float ACpp_TimeManager::GetTimeDilation() {
	return currentTimeDilation;
}

void ACpp_TimeManager::BeginReverseTime() {
	currentTimeDilation = reverseTimeFactor;
}

void ACpp_TimeManager::EndReverseTime() {
	currentTimeDilation = normalTimeFactor;
}

// Called when the game starts or when spawned
void ACpp_TimeManager::BeginPlay()
{
	Super::BeginPlay();
	
	// Apply Normal Time Factor
	currentTimeDilation = normalTimeFactor;
}

