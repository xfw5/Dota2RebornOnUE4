// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "D2ActorInterface.h"
#include "D2Type.h"
#include "D2Attachment.h"
#include "D2Creep.generated.h"

/*
* Creeps spawn from brewery each internal. Creeps do not gain experience and cannot level up.
* There are 3 type creep: normal creep, super creep and mega creep.
* When barrack down it will spawn super creeps and if all barracks down will spawn mega creeps.
*/
UCLASS(Blueprintable, classGroup = "D2Actor")
class DOTA2REBORN_API AD2Creep : public ACharacter, public ID2ActorInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleInstanceOnly, Category = "Status")
	int HealthPoint;

	UPROPERTY(VisibleInstanceOnly, Category = "Status")
	ETeamType Team;

	UPROPERTY(BlueprintReadOnly, Category = "Abilities")
	TArray<UD2Ability*> Abilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attr")
	FCreatureAttr Attributes;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Mission")
	FVector MarchLocation;

public:
	UPROPERTY(EditDefaultsOnly, category = "Behavior")
	class UBehaviorTree* BehaviorTree;

	// Sets default values for this pawn's properties
	AD2Creep();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void SetWeaponAttachment(UD2Attachment* Attachment);

	FORCEINLINE void SetMarchLocation(const FVector& Location) { MarchLocation = Location; }
	FORCEINLINE const FVector GetMarchLocation() const { return MarchLocation; }

	// begin ID2ActorInterface
	virtual ETeamType GetTeamNum() const override;
	
	virtual void SetTeamNum(ETeamType NewTeam) override;

	virtual int GetHealth() const override;
	
	virtual int GetMaxHealth() const override;
	
	virtual TArray<UD2Ability*> GetAbilities() const override;
	
	virtual UD2Ability* GetAbility(uint32 AbilityGID) const override;

	virtual int GetSightDistance() const override;
	// end ID2ActorInterface

	virtual int GetAttackRange() const override;

};
