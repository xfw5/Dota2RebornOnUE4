// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "D2ActorInterface.h"
#include "D2Neutral.generated.h"

/*
* Neutral refresh each internal in camp location.
*/
UCLASS(Blueprintable, classGroup = "D2Actor")
class DOTA2REBORN_API AD2Neutral : public ACharacter, public ID2ActorInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleInstanceOnly, Category = "Status")
	int HealthPoint;

	UPROPERTY(VisibleInstanceOnly, Category = "Status")
	ETeamType Team;

	UPROPERTY(BlueprintReadOnly, Category = "Abilities")
	TArray<UD2Ability*> Abilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Attr")
	FCreatureAttr Attributes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Behaviour")
	int MaxWalkAllowDistance;

public:
	// Sets default values for this pawn's properties
	AD2Neutral();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual ETeamType GetTeamNum() const override;


	virtual void SetTeamNum(ETeamType NewTeam) override;


	virtual int GetHealth() const override;


	virtual int GetMaxHealth() const override;


	virtual int GetSightDistance() const override;


	virtual TArray<UD2Ability *> GetAbilities() const override;


	virtual UD2Ability* GetAbility(uint32 AbilityGID) const override;


	virtual int GetAttackRange() const override;

};
