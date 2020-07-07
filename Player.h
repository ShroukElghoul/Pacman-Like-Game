#pragma once

#include "Cell.h"
#include "GUI.h"
class Grid;

class Player 
{
	int lives;    // number of lives (initially 3)
	int health; // player's health percentage (initially 100% -> full health)
	int score;  // player's score (initially 0)
	Cell PositionCell;
	int game ;// zero unless the player wins
	static int num_of_coins;


public:
	Player();
	Player(Cell pos); // Constructor
	void setscore();
	void setlifeAdd();
	void setlifeSub();
	void sethealth();
	void sethealthEnemy();

	int getscore();
	int getlife();
	int gethealth();

	void setGame(int i);
	int getGame();
	void setPosition(Cell);
	void Move(Grid* pGrid, ActionType MoveAction); 

	static void setCoinNum(int i);
	static int getCoinNum();// Moves the Player in a specific direction if possible
	static int getNumOfRemainingCoins(int score);

};

