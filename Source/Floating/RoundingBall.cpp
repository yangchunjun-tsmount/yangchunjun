// Fill out your copyright notice in the Description page of Project Settings.

#include "Floating.h"
#include "RoundingBall.h"
//#include "FloatMyActor.h"


// Sets default values
ARoundingBall::ARoundingBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoundingBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoundingBall::Tick( float DeltaTime)
{
	Super::Tick( DeltaTime );
	FVector PointRE;
	FVector NewLocation = GetActorLocation();
	PointRE = NewLocation;
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;
	RunningTime += DeltaTime;
	NewLocation.X = PointRE.X + DeltaHeight * 20.0f;
	NewLocation.Y = PointRE.Y + DeltaHeight * 20.0f;
	SetActorLocation(NewLocation);

}

