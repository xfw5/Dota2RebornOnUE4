// Fill out your copyright notice in the Description page of Project Settings.

#include "Dota2Reborn.h"
#include "D2Creep.h"
#include "D2Ability.h"

// Sets default values
AD2Creep::AD2Creep()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AD2Creep::BeginPlay()
{
	Super::BeginPlay();
	
	GetComponents(Abilities);
}

// Called every frame
void AD2Creep::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );


}

void AD2Creep::SetWeaponAttachment(UD2Attachment* Attachment)
{
	Attachment->RegisterComponent();
	Attachment->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, Attachment->AttachPoint);
}

ETeamType AD2Creep::GetTeamNum() const
{
	return Team;
}

void AD2Creep::SetTeamNum(ETeamType NewTeam)
{
	Team = NewTeam;
}

int AD2Creep::GetHealth() const
{
	return HealthPoint;
}

int AD2Creep::GetMaxHealth() const
{
	return Attributes.HitPoint.GetValue();
}

TArray<UD2Ability*> AD2Creep::GetAbilities() const
{
	return Abilities;
}

UD2Ability* AD2Creep::GetAbility(uint32 AbilityGID) const
{
	UD2Ability* TargetAbility = nullptr;
	for (UD2Ability* Ability: Abilities)
	{
		if (Ability->GetGID() == AbilityGID)
		{
			TargetAbility = Ability;
			break;
		}
	}

	return TargetAbility;
}

int AD2Creep::GetSightDistance() const
{
	return Attributes.SightDistance;
}

int AD2Creep::GetAttackRange() const
{
	return Attributes.AttackRange.GetValue();
}

