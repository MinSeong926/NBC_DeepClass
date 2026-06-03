// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PooledObjectData.generated.h"



USTRUCT(BlueprintType)

struct FPooledObjectData
{

	GENERATED_BODY()

	FPooledObjectData()
	{
		ActorTemplate = nullptr;
		PoolSize = 1;
		bCanGrow = false;
		ActorName = "default";
	}

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorTemplate;

	UPROPERTY(EditAnywhere)
	int32 PoolSize;

	UPROPERTY(EditAnywhere)
	bool bCanGrow;

	UPROPERTY(EditAnywhere)
	FString ActorName;
};