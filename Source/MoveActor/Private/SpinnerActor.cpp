// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinnerActor.h"

// Sets default values
ASpinnerActor::ASpinnerActor() : SpinSpeed(1.0f)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void ASpinnerActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpinnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SpinSpeed != 0.0f)
	{
		FRotator NowActorRotation = GetActorRotation();
		NowActorRotation.Yaw = FMath::Fmod(NowActorRotation.Yaw + DeltaTime * SpinSpeed, 360.0f);

		SetActorRotation(NowActorRotation);
	}
}

