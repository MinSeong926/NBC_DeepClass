
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// 헤더에서 PooledObjectData 가져오기
#include "PooledObjectData.h"

#include "MyActorPool.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPoolerCleanupSignature);

USTRUCT(BlueprintType)

struct FSingleObjectPool
{
	GENERATED_BODY()

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	TArray<TObjectPtr<class UPooledObject>> PooledObjects;
};

UCLASS()
class UNREALDEEPENING_API AMyActorPool : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	UPROPERTY()
	FPoolerCleanupSignature OnPoolerCleanup;

	// 소환한 액터들을 이름과 매칭해서 가져가기
	UFUNCTION(BlueprintCallable)
	AActor* GetPooledActor(FString Name);

	UFUNCTION(BlueprintCallable)
	void RecycleActor(AActor* PooledActor);

	// 최종 회수
	UFUNCTION(BlueprintCallable)
	void RecyclePooledObject(class UPooledOjbect* PoolComref);

	// 집나갔던 액터들 전부 회수
	UFUNCTION(BlueprintCallable)
	void Broadcast_PoolerCleanup();

	// 밖에서 생성할 때 지정해주는 구조체
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPooledObjectData> PooledObjectData;
protected:
	
	// 만들어둔 액터에 붙어있는 컴포넌트를 모아두는 장소
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FSingleObjectPool> Pools;

private:

	// 즉시 만들기
	void RegenItem(int32 PoolIndex, int32 PositionIndex);
};
