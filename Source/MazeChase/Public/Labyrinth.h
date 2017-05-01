// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/ChildActorComponent.h"
#include "Cell.h"
#include "Minotaur.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Labyrinth.generated.h"

UCLASS()
class MAZECHASE_API ALabyrinth : public AActor
{
	GENERATED_BODY()
	
public:	
	ALabyrinth();

	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, category = "Maze")
	void demolish();

	UFUNCTION(BlueprintCallable, category = "Maze")
	void rebuild();

	void generateModel();
	void raiseWalls();
	void carveWalls();
	void createExit();
	void createDoors();
	void createTorches();
	void createPlayerStart();
	void spawnMinotaur();

	Cell getCell(int x, int y);

	UFUNCTION(BlueprintCallable, category = "Maze")
	int getWallsAt(int x, int y);

	// Create constants (ROWS, COLS) to store the size of the maze.
	static const int ROWS = 20;
	static const int COLS = 20;

	// Wall object
	UPROPERTY(EditAnywhere, Category = Config)
		TSubclassOf<AActor> wall_class_;
	UPROPERTY(EditAnywhere, Category = Config)
		TSubclassOf<AActor> exit_sign_;
	UPROPERTY(EditAnywhere, Category = Config)
		TSubclassOf<AActor> door_class_;
	UPROPERTY(EditAnywhere, Category = Config)
		TSubclassOf<AMinotaur> minotaur_class_;
	UPROPERTY(EditAnywhere, Category = Config)
		TSubclassOf<AActor> torch_class_;

	//Wall child actors
	AActor* wall_children_meshes_[ROWS][COLS][4];

	static const int WALL_SIZE = 500;

private:
	// Create a 2-D array ([ROWS][COLS]) of Cell objects.
	Cell maze_[ROWS][COLS];

	//Player starting position
	int hero_startX, hero_startY;

	//Minotaur starting position
	int minotaur_startX, minotaur_startY;

	//Exit position
	int exitX, exitY;

	//A Reference to the minotaur
	AMinotaur* minos_;
};
