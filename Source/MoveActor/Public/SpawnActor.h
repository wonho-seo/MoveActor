// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnActor.generated.h"

UCLASS()
class MOVEACTOR_API ASpawnActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UPrimitiveComponent* SpawnRangeBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	int32 SpawnCount;


private:
	void SpawningActor();
	const FVector GetRandomPointInMeshBounds(const FBoxSphereBounds& Bounds);
};
