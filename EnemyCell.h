#pragma once
#include "Cell.h"
#include "Enemy.h"
class EnemyCell :
	public Cell
{
public:
	EnemyCell(int row, int col);
	~EnemyCell();
	virtual bool ActOn(Player* p);

};