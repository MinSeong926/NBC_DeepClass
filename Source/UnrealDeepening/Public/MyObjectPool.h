// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PooledObjectData.h"
#include "MyObjectPool.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPoolerCleanupSignature);

USTRUCT(BlueprintType)
struct FSingleObjectPool
{
	GENERATED_BODY()

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	TArray<TObjectPtr<class UPooledObject>> PooledObjects;
};

UCLASS()
class UNREALDEEPENING_API UMyObjectPool : public UActorComponent
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:


	UPROPERTY()
	FPoolerCleanupSignature OnPoolerCleanup;

	UFUNCTION(BlueprintCallable)
	void Broadcast_PoolerCleanup();

	UFUNCTION(BlueprintCallable)
	AActor* GetPooledActor(FString Name);

	UFUNCTION(BlueprintCallable)
	void RecyclePooledObject(class UPooledObject* PoolCompRef);

	UFUNCTION(BlueprintCallable)
	void RecycleActor(AActor* PooledActor);

	//레시피
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPooledObjectData> PooledObjectData;

protected:

	//만들어 둔 액터에 붙어있는 컴포넌트를 모아둔 장소
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FSingleObjectPool> Pools;

private:
	void RegenItem(int PoolIndex, int PositionIndex);

};
