// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleBlasterGameMode.h"
#include "Kismet/GameplayStatics.h"
#include"Tower.h"

void ABattleBlasterGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Towers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATower::StaticClass(), Towers);

	TowerCount = Towers.Num();
	UE_LOG(LogTemp, Warning, TEXT("Tower Count: %d"), TowerCount);	
	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (PlayerPawn) 
	{
		Tank = Cast<ATank>(PlayerPawn);
	}
	if (!Tank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank not found!"));
	}

	AActor* Tower = Towers[0];  

	int32 LoopIndex = 0;



		while (LoopIndex < TowerCount)
		{
			AActor* TowerActor = Towers[LoopIndex];
			if (TowerActor)
			{
				ATower* TowerPawn = Cast<ATower>(TowerActor);
				if (Tower)
				{
					TowerPawn->Tank = Tank;
				}
			}
			LoopIndex++;
		}

	

	


}