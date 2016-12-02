// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "D2Type.h"
#include "Dota2Reborn.h"

/**
 * 
 */
class DOTA2REBORN_API D2Helper
{
public:
	static void FilterHitResultByTeam(TArray<FHitResult> HitResult, ETeamType Team);
};
