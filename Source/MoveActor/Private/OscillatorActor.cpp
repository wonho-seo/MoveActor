// Fill out your copyright notice in the Description page of Project Settings.


#include "OscillatorActor.h"

// Sets default values
AOscillatorActor::AOscillatorActor() :
	MoveSpeed(FVector::ZeroVector),
	MaxMove(FVector::ZeroVector),
	LerpEpsilon(1.0f)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void AOscillatorActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AOscillatorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MoveSpeed != FVector::ZeroVector)
	{
		NowActorLocation = GetActorLocation();
		float Distance = FVector::Dist(NowActorLocation, EndActorLocation);

		if (Distance < LerpEpsilon)
		{
			SetActorLocation(EndActorLocation);

			FVector TempActorLocation = StartActorLocation;
			StartActorLocation = EndActorLocation;
			EndActorLocation = TempActorLocation;
		}
		else
		{
			SetActorLocation(FMath::Lerp(NowActorLocation, EndActorLocation, DeltaTime * MoveSpeed));
		}
	}
}

void AOscillatorActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	StartActorLocation = GetActorLocation();
	NowActorLocation = StartActorLocation;
	EndActorLocation = StartActorLocation + MaxMove;
}
