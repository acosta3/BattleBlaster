// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleBlasterGameInstance.h"

#include "Kismet/GameplayStatics.h"

void UBattleBlasterGameInstance::ChangeLevel(int32 Index)
{
	if(Index > 0 && Index <= LastLevelIndex)
	{
		CurrentLevel = Index;
		FString LevelNameString = FString::Printf(TEXT("Level_%d"), CurrentLevel);
		UGameplayStatics::OpenLevel(GetWorld(), *LevelNameString);
	}
}

void UBattleBlasterGameInstance::LoadNextLevel()
{
	if(CurrentLevel < LastLevelIndex)
	{
		ChangeLevel(CurrentLevel + 1);
	}
	else
	{
		RestartGame();
	}
	
}

void UBattleBlasterGameInstance::RestartCurrentLevel()
{
	ChangeLevel(CurrentLevel);
}

void UBattleBlasterGameInstance::RestartGame() 
{
	ChangeLevel(1);
}
