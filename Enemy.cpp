#include "Enemy.h"
#include "Grid.h"
#include "GUI.h"


Enemy::Enemy(Cell pos)
{
	PositionEnemyCell = pos;
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::setEnemyPosition(Cell pos)
{
	PositionEnemyCell = pos;
}

void Enemy::MoveEnemy(Grid * pGrid, int x)
{
	// Take a copy of the position before change
	Cell oldEnemyPosition = PositionEnemyCell;

	// Try to take a Move from Keyboard
	GUI* pGUI = pGrid->getGUI();
	//DIRECTION dir = pGUI->TakeMoveDirection(PositionCell);

	// Check if the Move is Possible (No Obstacles)
	pGrid->MoveEnemyIfPossible(&PositionEnemyCell, x);
}
