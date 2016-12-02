// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"

DOTA2REBORN_API DECLARE_LOG_CATEGORY_EXTERN(D2Log, Log, All)
DOTA2REBORN_API DECLARE_LOG_CATEGORY_EXTERN(D2Init, Log, All)
DOTA2REBORN_API DECLARE_LOG_CATEGORY_EXTERN(D2AI, Log, All)
DOTA2REBORN_API DECLARE_LOG_CATEGORY_EXTERN(D2CriticalErrors, Log, All);


#define COLLISION_PROJECTILE		ECC_GameTraceChannel1
#define COLLISION_GROUND			ECC_GameTraceChannel2
#define COLLISION_ATTACK_COMMAND	ECC_GameTraceChannel3