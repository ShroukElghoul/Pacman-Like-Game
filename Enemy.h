#pragma once
#include "Cell.h"
#include "GUI.h"
class Grid;
class Enemy
{
	Cell PositionEnemyCell;
public:
	Enemy(Cell pos);
	Enemy();
	~Enemy();
	void setEnemyPosition(Cell);
	void MoveEnemy(Grid* pGrid, int x);
};

