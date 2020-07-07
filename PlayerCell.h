#pragma once
#include "cell.h"
#include "Player.h"
class PlayerCell :	public Cell
{
public:
	PlayerCell(int row, int col);
	virtual ~PlayerCell();

	virtual bool ActOn(Player* p);
	virtual bool ActOnEnemy(Enemy* p);

};

