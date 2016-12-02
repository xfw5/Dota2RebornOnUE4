// Fill out your copyright notice in the Description page of Project Settings.

#include "Dota2Reborn.h"
#include "D2Neutral.h"
#include "D2Ability.h"


// Sets default values
AD2Neutral::AD2Neutral()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Team = ETeamType::Neutral;
}

// Called when the game starts or when spawned
void AD2Neutral::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AD2Neutral::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

ETeamType AD2Neutral::GetTeamNum() const
{
	return Team;
}

void AD2Neutral::SetTeamNum(ETeamType NewTeam)
{
	Team = NewTeam;
}

int AD2Neutral::GetHealth() const
{
	return HealthPoint;
}

int AD2Neutral::GetMaxHealth() const
{
	return Attributes.HitPoint.GetValue();
}

int AD2Neutral::GetSightDistance() const
{
	return Attributes.SightDistance;
}

TArray<UD2Ability *> AD2Neutral::GetAbilities() const
{
	return Abilities;
}

UD2Ability* AD2Neutral::GetAbility(uint32 AbilityGID) const
{
	UD2Ability* TargetAbility = nullptr;
	for (UD2Ability* Ability : Abilities)
	{
		if (Ability->GetGID() == AbilityGID)
		{
			TargetAbility = Ability;
			break;
		}
	}

	return TargetAbility;
}

int AD2Neutral::GetAttackRange() const
{
	return Attributes.AttackRange.GetValue();
}

