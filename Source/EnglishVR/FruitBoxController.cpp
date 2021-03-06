
#include "FruitBoxController.h"

AFruitBoxController::AFruitBoxController() {
	PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<UDataTable> _DataTable(TEXT("DataTable'/Game/CSV/FruitsAndPath.FruitsAndPath'"));
    if (_DataTable.Succeeded()) {
        DataTable = _DataTable.Object;
    }

    FString ContextString;

    for (auto it : DataTable->GetRowMap()) {
        FAudioDataTableStruct* Row = DataTable->FindRow<FAudioDataTableStruct>(it.Key, ContextString, true);
        if (Row) {
            FruitType.Add(Row->FruitType);
            FruitPath.Add(Row->Path);
        }
    }
}

TArray<FString> AFruitBoxController::RandomFruitGeneration() {
    TArray<FString> tmp;
    int32 Rand = FMath::RandRange(0, FruitType.Num() - 1);

    counter++;

    if (!AllFruits.Contains(FruitPath[Rand])) {
        AllFruits.Add(FruitPath[Rand], 1);

        tmp.Add(FruitPath[Rand]);
        tmp.Add(FruitType[Rand]);
        UE_LOG(LogTemp, Warning, TEXT("Mesh � %d is %s %s"),counter, *tmp[0], *tmp[1]);
        return tmp;
    }

    int32 count = AllFruits.FindRef(FruitPath[Rand]);
    if (count >= 2)
        return tmp = RandomFruitGeneration();

    AllFruits.Add(FruitPath[Rand], 2);

    tmp.Add(FruitPath[Rand]);
    tmp.Add(FruitType[Rand]);
    UE_LOG(LogTemp, Warning, TEXT("Mesh%d is %s %s"), counter, *tmp[0], *tmp[1]);

    return tmp;
}

// Called when the game starts or when spawned
void AFruitBoxController::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AFruitBoxController::Tick(float DeltaTime)  {
	Super::Tick(DeltaTime);
}

