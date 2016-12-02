// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "D2CreepsDirector.h"
#include "D2Creep.h"
#include "D2Type.h"
#include "D2Barrack.generated.h"

/*
* When barrack down, the enemy barracks will spawn super creeps,
* and spawn mega creeps if all barracks down.
*/
UCLASS()
class DOTA2REBORN_API AD2Barrack : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "CreepsDirector", meta = (AllowPrivateAccess = "true"))
	UD2CreepsDirector* CreepsDirector;

protected:
	UPROPERTY(EditInstanceOnly, Category = "Team")
	ETeamType Team;

	UPROPERTY(EditInstanceOnly, Category = "Enemy")
	AActor* EnemyHome;
public:	
	// Sets default values for this actor's properties
	AD2Barrack();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void SpawnCreeps();
};
