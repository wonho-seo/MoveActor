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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ToolTip = "�̵� �ӵ�"))
	FVector MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ToolTip = "�ִ� �̵� �Ÿ�"))
	FVector MaxMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ToolTip = "���������� ������ �����մϴ�", ClampMin = "0.0"))
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
