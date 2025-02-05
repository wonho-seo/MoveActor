// Fill out your copyright notice in the Description page of Project Settings.


#include "AppearingActor.h"

// Sets default values
AAppearingActor::AAppearingActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshCompoent"));
	StaticMeshComponent->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void AAppearingActor::BeginPlay()
{
	Super::BeginPlay();
	if (AppearTime > 0)
	{
		GetWorld()->GetTimerManager().SetTimer(AppearTimerHandle, this, &AAppearingActor::DoAppearing, AppearTime + DisappearTime, true, DelayTime);
	}
	if (DisappearTime > 0)
	{
		GetWorld()->GetTimerManager().SetTimer(DisappearTimerHandle, this, &AAppearingActor::DoDisappearing, AppearTime + DisappearTime, true, DelayTime + AppearTime);
	}
}

// Called every frame
void AAppearingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAppearingActor::DoAppearing()
{
	StaticMeshComponent->SetVisibility(true);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void AAppearingActor::DoDisappearing()
{
	StaticMeshComponent->SetVisibility(false);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

