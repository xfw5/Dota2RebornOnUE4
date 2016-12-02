// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "D2Type.h"
#include "D2ActorInterface.generated.h"

class UD2Ability;

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType, meta = (CannotImplementInterfaceInBlueprint))
class UD2ActorInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class DOTA2REBORN_API ID2ActorInterface
{
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual ETeamType GetTeamNum() const = 0;
	virtual void SetTeamNum(ETeamType NewTeam) = 0;

	virtual int GetHealth() const = 0;
	virtual int GetMaxHealth() const = 0;
	virtual int GetSightDistance() const = 0;
	virtual int GetAttackRange() const = 0;

	virtual TArray<UD2Ability*> GetAbilities() const = 0;
	virtual UD2Ability* GetAbility(uint32 AbilityGID) const = 0;
};
