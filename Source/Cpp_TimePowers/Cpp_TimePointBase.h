// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Cpp_TimePointBase.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CPP_TIMEPOWERS_API UCpp_TimePointBase : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "TimePoint")
	float TimePoint = 0.0f;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "TimePoint")
	UCpp_TimePointBase* Interpolate(const UCpp_TimePointBase* other, float distance);

private:
	virtual UCpp_TimePointBase* Interpolate_Implementation(const UCpp_TimePointBase* other, float distance) const;
};
