// Fill out your copyright notice in the Description page of Project Settings.

#include "Dota2Reborn.h"
#include "D2CreepsController.h"
#include "D2Creep.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

AD2CreepsController::AD2CreepsController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackBoardComp"));

	BrainComponent = BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
}

void AD2CreepsController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	Creep = Cast<AD2Creep>(InPawn);
	if (Creep == nullptr)
	{
		UE_LOG(D2AI, Fatal, TEXT("Creeps Controller: Pawn is NOT a Creep type"));
		return;
	}

	if (Creep->BehaviorTree)
	{
		UBlackboardData* BlackboardAsset = Creep->BehaviorTree->BlackboardAsset;
		if (BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*BlackboardAsset);
			BlackboardComp->SetValueAsVector(MarchLocation, Creep->GetMarchLocation());
		}

		BehaviorComp->StartTree(*(Creep->BehaviorTree));
	}
}

void AD2CreepsController::UnPossess()
{
	Super::UnPossess();

	Creep = nullptr;

	BehaviorComp->StopTree();
}
