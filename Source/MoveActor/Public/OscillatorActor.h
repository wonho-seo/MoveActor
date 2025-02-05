// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OscillatorActor.generated.h"

UCLASS()
class MOVEACTOR_API AOscillatorActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOscillatorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ToolTip = "이동 속도"))
	FVector MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ToolTip = "최대 이동 거리"))
	FVector MaxMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ToolTip = "도착지점의 오차를 설정합니다", ClampMin = "0.0"))
	float LerpEpsilon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VisibleOnly|Location")
	FVector StartActorLocation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VisibleOnly|Location")
	FVector NowActorLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VisibleOnly|Location")
	FVector EndActorLocation;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;

};
