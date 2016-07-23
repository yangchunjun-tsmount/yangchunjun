// Fill out your copyright notice in the Description page of Project Settings.

#include "Floating.h"
#include "FloatingMyActor.h"


// Sets default values
AFloatingMyActor::AFloatingMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingMyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;
	RunningTime += DeltaTime;
	ThePoint.X = NewLocation.X;
	ThePoint.Y = NewLocation.Y;
	ThePoint.Z = NewLocation.Z;
	SetActorLocation(NewLocation);
}

