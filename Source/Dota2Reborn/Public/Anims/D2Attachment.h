// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SkeletalMeshComponent.h"
#include "D2Attachment.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = Attachment)
class DOTA2REBORN_API UD2Attachment : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Attachment")
	FName AttachPoint;
};
