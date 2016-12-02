// Fill out your copyright notice in the Description page of Project Settings.

#include "Dota2Reborn.h"
#include "D2Helper.h"
#include "D2ActorInterface.h"

void D2Helper::FilterHitResultByTeam(TArray<FHitResult> HitResult, ETeamType Team)
{
	for (int i = HitResult.Num(); i >= 0; i--)
	{
		const FHitResult &TestHit = HitResult[i];
		ID2ActorInterface* D2Actor = Cast<ID2ActorInterface>(TestHit.GetActor());
		if (D2Actor && D2Actor->GetTeamNum() == Team) HitResult.RemoveAt(i);
	}
}
