#pragma once

#include "GUI.h"
#include "DEFS.h"
#include "Cell.h"
#include <math.h>

class Player;	//forward class declaration
class Enemy;
class Grid
{
	GUI * pGUI;   // a pointer to the the interface

	Cell*	GameCells[NumRowCells][NumColumnCells];	// Array of Pointers to Cell
	Player* player;
	Enemy* enemy;
	int num_of_enemy=0;
	Enemy* enemy_pointers[1];



public:
	Grid();	 

	int * getClickedCell(int w) const;
	// ========== Action-Related Functions ==========

	ActionType GetUserAction() const; // Reads the input command from the user and returns the corresponding action type

	void ExecuteAction(ActionType) ;  // Creates an action of the passed actionType and executes it

	void setCell(int r, int c, Cell* pCell);	//updates cell r,c to hold the new pointer pCell
	
	bool MoveIfPossible(Cell * pCurrentCell, ActionType dir); // Moves the entered position in the passed direction if no obstacles
	                                                       // updates currentCell if move takes place
	bool MoveEnemyIfPossible(Cell * pCurrentCell, int dir);                                                       // Note: It returns bool indicating if a move occured or not

	bool IsValidCell(int r, int c) const;

	void DrawAllCells() const; // Draws the Grid and All its GameObjects

	int* getRandMoveEnemy();

	void setEnemyNum(int i);
	int getEnemyNum();




	GUI * getGUI() const;	// Gets a Pointer to the GUI

	~Grid();
	void RunApp();	//Runs the application


};

