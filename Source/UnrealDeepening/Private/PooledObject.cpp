// Fill out your copyright notice in the Description page of Project Settings.


#include "PooledObject.h"
#include "MyObjectPool.h"

void UPooledObject::Init(UMyObjectPool* Owner)
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
