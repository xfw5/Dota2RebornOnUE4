// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTService.h"
#include "BTService_SearchTargetInSight.generated.h"

/**
 * 
 */
UCLASS()
class DOTA2REBORN_API UBTService_SearchTargetInSight : public UBTService
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	FBlackboardKeySelector DesireTarget;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	void SearchTargetInSightRange(UBehaviorTreeComponent& OwnerComp);
};
