// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Engine/DataTable.h"
#include "AIController.h"
#include "Basket.h"
#include "Sound/SoundCue.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/Character.h"
#include "AudioDataTableStruct.h"
#include "MyCharacter.generated.h"

UENUM(BlueprintType)
enum class EStatesEnum : uint8 {
    NotActive UMETA(DisplayName = "NotActive"),
    Active    UMETA(DisplayName = "Active"),
    Finished  UMETA(DisplayName = "Finished"),
};

UCLASS(Abstract)
class ENGLISHVR_API AMyCharacter : public ACharacter {
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AMyCharacter();

    UPROPERTY(BlueprintReadWrite)
    UBoxComponent* Box;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UAudioComponent* Audio;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UDataTable* DataTable;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UDataTable* _Table;

    UPROPERTY(BlueprintReadWrite)
    bool IsCheck = false;

    UPROPERTY(BlueprintReadWrite)
    bool IsTmp = false;

    UPROPERTY(BlueprintReadWrite)
    bool IsEnd = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<AActor*> ToPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<AActor*> OutPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EStatesEnum EComeState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EStatesEnum ENegativeState;

    UPROPERTY(BlueprintReadWrite)
    EStatesEnum EPickupState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 WalkingCount;

    UPROPERTY(BlueprintReadWrite)
    ABasket* Basket;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FString, int32> FruitsCount;

    UPROPERTY(BlueprintReadWrite)
    TMap<FName, FName> DialogList;

    UFUNCTION(BlueprintCallable)
    void GoToMarket();

    UFUNCTION(BlueprintCallable)
    void GoAway();

    UFUNCTION(BlueprintCallable)
    void TakeBasket();

    UFUNCTION(BlueprintImplementableEvent)
    void PlayDialog(FName DialogName, bool _isCheck);

    UFUNCTION(BlueprintImplementableEvent)
    bool IsNotPlaying();

    UFUNCTION(BlueprintCallable)
    bool IsCorrectFruitsCount();

    UFUNCTION(BlueprintCallable)
    void RandomDialogGenerator(TArray<FName> SoundsName);

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:    
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
