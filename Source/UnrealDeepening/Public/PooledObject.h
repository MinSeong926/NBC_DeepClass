
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PooledObject.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALDEEPENING_API UPooledObject : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	void Init(class UMyObjectPool* Owner);
	
	// ÀÚ¸ê ¹öÆ°
	UFUNCTION(BlueprintCallable)
	void RecycleSelf();

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	bool bIsPoolActive;

private:

	TObjectPtr<class UMyObjectPool> ObjectPool;

	//ÀÚ¸ê¹öÆ°
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
};
