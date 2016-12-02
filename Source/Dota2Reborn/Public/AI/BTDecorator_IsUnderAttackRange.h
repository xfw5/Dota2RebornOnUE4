// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsUnderAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class DOTA2REBORN_API UBTDecorator_IsUnderAttackRange : public UBTDecorator
{
	GENERATED_BODY()
		
protected:
	UPROPERTY(EditAnywhere, category = "Target")
	FBlackboardKeySelector Target;

	UPROPERTY(EditAnywhere, category = "Factor", meta = (UIMin = "0.5", UIMax = "1.5"))
	float DistanceFactor;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
