// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnActor.h"
#include "Components/BoxComponent.h"

// Sets default values
ASpawnActor::ASpawnActor() : SpawnCount(1)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponents"));
	SetRootComponent(SceneRoot);

	SpawnRangeBox = CreateDefaultSubobject<UBoxComponent>(TEXT("RangeComponents"));
	SpawnRangeBox->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();

	SpawningActor();
}


const FVector ASpawnActor::GetRandomPointInMeshBounds(const FBoxSphereBounds& Bounds)
{
	FVector Origin = Bounds.Origin;
	FVector Extent = Bounds.BoxExtent;

	return Origin + FMath::RandPointInBox(FBox(-Extent, Extent));
}

void ASpawnActor::SpawningActor()
{
	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors);
	FBoxSphereBounds MeshBounds = SpawnRangeBox->Bounds;
	UWorld* World = GetWorld();
	if (World && SpawnRangeBox)
	{
		for (AActor* AttachedActor : AttachedActors)
		{
			if (AttachedActor)
			{
				for (int32 Count = 0; Count < SpawnCount; Count++)
				{
					FActorSpawnParameters SpawnAParams;
					SpawnAParams.Template = AttachedActor;

					AActor* SpawnedActor = World->SpawnActor<AActor>(AttachedActor->GetClass(), GetRandomPointInMeshBounds(MeshBounds), GetActorRotation(), SpawnAParams);
				}
			}
			AttachedActor->Destroy();
		}
	}

}
