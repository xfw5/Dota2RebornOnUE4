// Fill out your copyright notice in the Description page of Project Settings.

#include "Dota2Reborn.h"
#include "D2AnimInstance.h"


void UD2AnimInstance::AnimNotify_Melee(UAnimNotify* Notify)
{
	UE_LOG(D2Log, Warning, TEXT("Melee attack"));
}
