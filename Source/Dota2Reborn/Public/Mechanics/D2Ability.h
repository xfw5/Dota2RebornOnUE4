// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "D2Ability.generated.h"


UCLASS(Blueprintable,  ClassGroup=("Ability"), meta=(BlueprintSpawnableComponent) )
class DOTA2REBORN_API UD2Ability : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleInstanceOnly, Category = "Unique")
	uint32 GID;

	UPROPERTY(EditDefaultsOnly, Category = "Description")
	FText Name;

	UPROPERTY(EditDefaultsOnly, Category = "Description")
	FText Description;
public:	
	// Sets default values for this component's properties
	UD2Ability();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	FORCEINLINE const uint32 GetGID() const { return GID; }
	
};
