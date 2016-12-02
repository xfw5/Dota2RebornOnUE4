// Fill out your copyright notice in the Description page of Project Settings.

#include "Dota2Reborn.h"
#include "D2CreepsDirector.h"
#include "D2Creep.h"

// Sets default values for this component's properties
UD2CreepsDirector::UD2CreepsDirector()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CreepType = ECreepType::Normal;
}


// Called when the game starts
void UD2CreepsDirector::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UD2CreepsDirector::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UD2CreepsDirector::SpawnCreeps(const ETeamType &Team, const FVector &Location, const FRotator &Rotation, const FVector &MarchLocation)
{
	UWorld* World = GetWorld();
	if (World)
	{
		for (const FCreepsSpawnDes& Des : Creeps)
		{
			for (uint8 i = 0; i < Des.SpawnCount; i++)
			{
				FActorSpawnParameters SpawnInfo;
				SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

				AD2Creep* Creep = World->SpawnActor<AD2Creep>(Des.CreepClass, Location, Rotation, SpawnInfo);
				if (Creep != nullptr)
				{
					Creep->SetTeamNum(Team);
					Creep->SetMarchLocation(MarchLocation);

					Creep->SpawnDefaultController();

					if (AttachmentArmor != nullptr)
					{
						AttachArmor(Creep);
					}

					if (AttachmentSmithy != nullptr)
					{
						AttachSmithy(Creep);
					}

					if (CreepType == ECreepType::Super)
					{
						ApplyCreepsBuff(SuperCreeps);
					}else if (CreepType == ECreepType::Mega)
					{
						ApplyCreepsBuff(MegaCreeps);
					}
				}
			}
		}
	}
}

void UD2CreepsDirector::ApplyCreepsBuff(const FCreepBufferData &BuffData)
{
	
}

void UD2CreepsDirector::AttachArmor(AD2Creep* creep)
{
	UD2Attachment* WeaponArmor = NewObject<UD2Attachment>(creep, *this->AttachmentArmor);
	creep->SetWeaponAttachment(WeaponArmor);
}

void UD2CreepsDirector::AttachSmithy(AD2Creep* creep)
{
	UD2Attachment* WeaponSmithy = NewObject<UD2Attachment>(creep, *this->AttachmentSmithy);
	creep->SetWeaponAttachment(WeaponSmithy);
}

