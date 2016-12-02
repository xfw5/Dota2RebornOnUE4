// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "D2CreepsController.generated.h"

class UBlackboardComponent;
class UBehaviorTreeComponent;

/**
 * 
 */
UCLASS()
class DOTA2REBORN_API AD2CreepsController : public AAIController
{
	GENERATED_UCLASS_BODY()
	
private:
	UPROPERTY(transient)
	UBlackboardComponent* BlackboardComp;

	UPROPERTY(transient)
	UBehaviorTreeComponent* BehaviorComp;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Mission")
	FName MarchLocation;

public:
	/* Cache */
	UPROPERTY(Transient, BlueprintReadOnly, category = "Creep")
	class AD2Creep* Creep;

	virtual void Possess(APawn* InPawn) override;

	virtual void UnPossess() override;

};
