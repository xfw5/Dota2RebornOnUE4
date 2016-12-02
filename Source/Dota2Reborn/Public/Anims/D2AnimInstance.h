// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimInstance.h"
#include "D2AnimInstance.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = AnimInstance)
class DOTA2REBORN_API UD2AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	UFUNCTION()
	void AnimNotify_Melee(UAnimNotify* Notify);
};
