// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserHealthWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALDEEPENING_API UUserHealthWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void UpdateHealthUI(float CurrentHealth, float MaxHealth, float HealthChange);

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthProgressBar;
};
