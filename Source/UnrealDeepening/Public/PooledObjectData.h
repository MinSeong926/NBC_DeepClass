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

	//어떤 액터를 스폰할 것인가.
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorTemplate;

	//몇개를 스폰할 것인가
	UPROPERTY(EditAnywhere)
	int PoolSize;

	//없으면 추가로 생성할 예정인가
	UPROPERTY(EditAnywhere)
	bool bCanGrow;

	//액터의 이름은 무엇인가
	UPROPERTY(EditAnywhere)
	FString ActorName;
};