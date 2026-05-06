#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS(Abstract)
class UNREALDEEPENING_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	ABaseWeapon();

	// 템플릿 메서드: 전체 발사 흐름을 고정합니다. (블루프린트에서 호출 가능)
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();

protected:
	// 하위 클래스(Shotgun, Rifle 등)에서 입맛에 맞게 구현할 세부 단계들
	virtual bool CanFire() const;
	virtual void PreFire();
	virtual void ExecuteFire();
	virtual void ApplyRecoil();
};