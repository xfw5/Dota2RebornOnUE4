// Fill out your copyright notice in the Description page of Project Settings.

#include "Dota2Reborn.h"
#include "BTDecorator_IsUnderAttackRange.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "D2ActorInterface.h"
#include "D2CreepsController.h"
#include "D2Creep.h"

bool UBTDecorator_IsUnderAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AActor* Actor = OwnerComp.GetOwner();
	const AD2CreepsController* CreepController = Cast<AD2CreepsController>(Actor);
	if (CreepController)
	{
		const AD2Creep* Creep = CreepController->Creep;
		if (Creep)
		{
			UObject* Obj = OwnerComp.GetBlackboardComponent()->GetValueAsObject(Target.SelectedKeyName);
			AActor* TestActor = Cast<AActor>(Obj);
			if (TestActor)
			{
				float DistSq = FVector::DistSquared(TestActor->GetActorLocation(), Actor->GetActorLocation());
				float AttackRange = Creep->GetAttackRange() * DistanceFactor;
				return DistSq < AttackRange * AttackRange;
			}
		}
	}

	return false;
}
