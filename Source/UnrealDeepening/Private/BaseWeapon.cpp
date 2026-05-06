#include "BaseWeapon.h"

ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseWeapon::Fire()
{
	if (CanFire())
	{
		PreFire();       // 발사 전처리 (로그, 이펙트)
		ExecuteFire();   // 실제 발사 로직 (라인 트레이스)
		ApplyRecoil();   // 반동 적용
	}
}

bool ABaseWeapon::CanFire() const
{
	return true;
}

void ABaseWeapon::PreFire()
{
}

void ABaseWeapon::ExecuteFire()
{
}

void ABaseWeapon::ApplyRecoil()
{
}