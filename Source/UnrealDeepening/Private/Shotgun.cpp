#include "Shotgun.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

AShotgun::AShotgun()
{
	PrimaryActorTick.bCanEverTick = false;
}

// 전처리 단계 (디버그 메시지 및 로그)
void AShotgun::PreFire()
{
	Super::PreFire();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("반동!!"));
	}
	UE_LOG(LogTemp, Warning, TEXT("반동!!"));
}

// 발사 로직 (산탄 라인트레이스 계산)
void AShotgun::ExecuteFire()
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (!OwnerPawn) return;

	APlayerController* PC = Cast<APlayerController>(OwnerPawn->GetController());
	if (!PC) return;

	FVector CameraLocation;
	FRotator CameraRotation;
	PC->GetPlayerViewPoint(CameraLocation, CameraRotation);

	FVector ForwardVector = CameraRotation.Vector();
	FVector GunLocation = GetActorLocation();

	for (int32 i = 0; i < PelletCount; i++)
	{
		float HalfAngleRad = FMath::DegreesToRadians(SpreadAngle / 2.0f);
		FVector ShootDirection = FMath::VRandCone(ForwardVector, HalfAngleRad);
		FVector EndLocation = CameraLocation + (ShootDirection * 5000.0f);

		FHitResult HitResult;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(OwnerPawn);
		CollisionParams.AddIgnoredActor(this);

		bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, EndLocation, ECC_Visibility, CollisionParams);

		if (bHit)
		{
			DrawDebugLine(GetWorld(), GunLocation, HitResult.ImpactPoint, FColor::Red, false, 2.0f);
		}
		else
		{
			DrawDebugLine(GetWorld(), GunLocation, EndLocation, FColor::Green, false, 2.0f);
		}
	}
}

// 반동 적용 단계
void AShotgun::ApplyRecoil()
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (!OwnerPawn) return;

	APlayerController* PC = Cast<APlayerController>(OwnerPawn->GetController());
	if (!PC) return;

	float RandomYaw = FMath::RandRange(-RecoilYawRange, RecoilYawRange);

	PC->AddPitchInput(RecoilPitchAmount);
	PC->AddYawInput(RandomYaw);
}