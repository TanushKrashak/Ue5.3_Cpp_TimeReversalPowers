// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_TimePointBase.h"


UCpp_TimePointBase* UCpp_TimePointBase::Interpolate_Implementation(const UCpp_TimePointBase* other, float distance) const {
	return DuplicateObject(this, nullptr);
}
