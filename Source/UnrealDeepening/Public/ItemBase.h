// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestMyInterface.h"
#include "ItemBase.generated.h"

UCLASS()
class UNREALDEEPENING_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:

	UFUNCTION()
	void PlayerDeathReceive(AController* InstigatorController);

protected:
	virtual void BeginPlay() override;
	
};
