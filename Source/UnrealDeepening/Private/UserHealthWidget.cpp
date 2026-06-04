// Fill out your copyright notice in the Description page of Project Settings.


#include "UserHealthWidget.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "MyActorComponent.h"
#include "Components/ProgressBar.h"

void UUserHealthWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (PlayerCharacter)
	{
		UMyActorComponent* HealthComp = PlayerCharacter->FindComponentByClass<UMyActorComponent>();
		if (HealthComp)
		{
			HealthComp->OnHealthDamaged.AddDynamic(this, &UUserHealthWidget::UpdateHealthUI);
		}
	}
}

void UUserHealthWidget::UpdateHealthUI(float CurrentHealth, float MaxHealth, float HealthChange)
{
	if (HealthProgressBar && MaxHealth > 0.f)
	{
		HealthProgressBar->SetPercent(CurrentHealth / MaxHealth);
	}
}