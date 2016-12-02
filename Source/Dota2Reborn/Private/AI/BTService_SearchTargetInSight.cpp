// Fill out your copyright notice in the Description page of Project Settings.

#include "Dota2Reborn.h"
#include "BTService_SearchTargetInSight.h"
#include "D2ActorInterface.h"
#include "D2Helper.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "D2CreepsController.h"
#include "D2Creep.h"


void UBTService_SearchTargetInSight::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	SearchTargetInSightRange(OwnerComp);
}

void UBTService_SearchTargetInSight::SearchTargetInSightRange(UBehaviorTreeComponent& OwnerComp)
{
	AActor* Owner = OwnerComp.GetOwner();
	const AAIController* AIController = Cast<AAIController>(Owner);
	if (AIController)
	{
		const APawn* Pawn = AIController->GetPawn();
		const ID2ActorInterface* D2Actor = Cast<ID2ActorInterface>(Pawn);
		if (D2Actor)
		{
			const int SightDist = D2Actor->GetSightDistance();
			const ETeamType Team = D2Actor->GetTeamNum();

			const FVector StartLocation = Owner->GetActorLocation();
			const FVector EndLocation = StartLocation + FVector(0, 0, 10);

			TArray<TEnumAsByte<EObjectTypeQuery>> ObjType;
			TEnumAsByte<EObjectTypeQuery> PawnType = UEngineTypes::ConvertToObjectType(ECC_Pawn);
			ObjType.Add(PawnType);
			FCollisionObjectQueryParams QueryParams(ObjType);
			QueryParams.IgnoreMask = (uint8)Team;

			TArray<FOverlapResult> OverlapResult;
			ECollisionChannel Channel = ECC_Visibility;
			UWorld* World = Owner->GetWorld();
			AActor* NearestActor = nullptr;
			float NearestDist = INFINITY;

			if (World->OverlapMultiByObjectType(OverlapResult, StartLocation, FQuat::Identity, QueryParams, FCollisionShape::MakeSphere(SightDist)))
			{
				for (int i = OverlapResult.Num() - 1; i >= 0; i--)
				{
					AActor* TestActor = OverlapResult[i].GetActor();
					ID2ActorInterface* TestD2Actor = Cast<ID2ActorInterface>(TestActor);
					if (TestD2Actor)
					{
						if (TestD2Actor->GetTeamNum() == Team) 
						{
							OverlapResult.RemoveAt(i);
							continue;
						}

						if (World->LineTraceTestByChannel(StartLocation, EndLocation, Channel))
						{
							OverlapResult.RemoveAt(i);
							continue;
						}

						float DistSq = FVector::DistSquared(StartLocation, TestActor->GetActorLocation());
						if (DistSq < NearestDist)
						{
							NearestActor = TestActor;
							NearestDist = DistSq;
						}
					}
				}
			}

			UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
			if (BlackboardComp != NULL)
			{
				BlackboardComp->SetValueAsObject(DesireTarget.SelectedKeyName, NearestActor);
			}
		}
	}
}