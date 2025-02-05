// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppearingActor.generated.h"

UCLASS()
class MOVEACTOR_API AAppearingActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAppearingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties", meta = (ClampMin = "0.0"))
	float AppearTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties", meta = (ClampMin = "0.0"))
	float DisappearTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties", meta = (ClampMin = "0.0"))
	float DelayTime;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void DoAppearing();
	void DoDisappearing();

	FTimerHandle AppearTimerHandle;
	FTimerHandle DisappearTimerHandle;

};
