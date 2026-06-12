// Fill out your copyright notice in the Description page of Project Settings.


#include "PooledObject.h"

void UPooledObject::Init(AMyObjectPool* Owner)
{
	bIsPoolActive = false;

	ObjectPool = Owner;
}

void UPooledObject::RecycleSelf()
{
	ObjectPool->RecyclePooledObject(this);
}

void UPooledObject::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	ObjectPool->OnPoolerCleanup.RemoveDynamic(this, &UPooledObject::RecycleSelf);

	Super::OnComponentDestroyed(bDestroyingHierarchy);
}
