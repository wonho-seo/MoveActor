// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinnerActor.generated.h"

UCLASS()
class MOVEACTOR_API ASpinnerActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpinnerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USceneComponent* RootComponet;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float SpinSpeed;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FVector NowRotate;
};
