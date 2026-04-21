
#include "CRActor.h"
#include "Engine/Engine.h"

void ACRActor::UseItem(FName ItemName) {
    // 가방(TArray)에 아이템이 존재하는지 1차 확인
    if (!InventoryBag.Contains(ItemName))
    {
        if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("가방에 없는 아이템입니다."));
        return;
    }

    // TMap에서 아이템의 상세 정보(Key값 기반)를 가져옴
    if (FItemData* ItemInfo = ItemDatabase.Find(ItemName))
    {
        // 요구 칭호가 없거나(None), 획득한 칭호 목록(TSet)에 해당 칭호가 있는지 검사
        if (ItemInfo->RequiredTitle.IsNone() || AcquiredTitles.Contains(ItemInfo->RequiredTitle))
        {
            // 사용 성공
            FString SuccessMsg = FString::Printf(TEXT("아이템 사용 성공! [정보: %s]"), *ItemInfo->ItemDescription);
            if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, SuccessMsg);

            // 사용한 아이템 가방에서 제거 (필요시 주석 해제)
            // InventoryBag.RemoveSingle(ItemName); 
        }
        else
        {
            // 칭호가 없어서 사용 불가
            FString FailMsg = FString::Printf(TEXT("사용 불가! '%s' 칭호가 필요합니다."), *ItemInfo->RequiredTitle.ToString());
            if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FailMsg);
        }
    }
}