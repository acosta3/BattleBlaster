// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle FireTimerHandle;
	GetWorldTimerManager().SetTimer(FireTimerHandle,this,&ATower::CheckFireCondition, FireRate,true);
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (Tank)
	{
		FVector TankLocation = Tank->GetActorLocation();
		FVector TowerLocation = GetActorLocation();
		float DistanceToTank = FVector::Dist(TankLocation, TowerLocation);
		if (DistanceToTank <= Distance)
		{
			RotateTurret(Tank->GetActorLocation());
		}
	}

	
}

void ATower::CheckFireCondition()
{
	if (Tank)
	{
		FVector TankLocation = Tank->GetActorLocation();
		FVector TowerLocation = GetActorLocation();
		float DistanceToTank = FVector::Dist(TankLocation, TowerLocation);
		if (DistanceToTank <= Distance)
		{
			Fire();
		}
	}
}
