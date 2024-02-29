// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cpp_TimeGameMode.h"
#include "Cpp_TimeManager.h"
#include "Components/ActorComponent.h"
#include "Cpp_TimeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_TIMEPOWERS_API UCpp_TimeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCpp_TimeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Time")
	ACpp_TimeManager* TimeManager = nullptr;
};
