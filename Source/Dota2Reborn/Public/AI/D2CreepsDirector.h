// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "D2Type.h"
#include "D2CreepsDirector.generated.h"

class AD2Creep;

USTRUCT()
struct FCreepsSpawnDes
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Creeps")
	uint8 SpawnCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Creeps")
	TSubclassOf<AD2Creep> CreepClass;
};

UCLASS(ClassGroup=(D2), meta=(BlueprintSpawnableComponent) )
class DOTA2REBORN_API UD2CreepsDirector : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, category = "Creeps")
	ECreepType CreepType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Creeps")
	uint8 SpawnInternal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Creeps")
	TArray<FCreepsSpawnDes> Creeps;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Creep Buff")
	FCreepBufferData SuperCreeps;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Creep Buff")
	FCreepBufferData MegaCreeps;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Weapon Attachment")
	TSubclassOf<class UD2Attachment> AttachmentArmor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = "Weapon Attachment")
	TSubclassOf<class UD2Attachment> AttachmentSmithy;

	void AttachArmor(AD2Creep* creep);

	void AttachSmithy(AD2Creep* creep);

public:	
	// Sets default values for this component's properties
	UD2CreepsDirector();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void SpawnCreeps(const ETeamType &Team, const FVector &Location, const FRotator &Rotation, const FVector &MarchLocation);
	
	void ApplyCreepsBuff(const FCreepBufferData &BuffData);
};
