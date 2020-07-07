#pragma once
#include "Cell.h"
class BombCell :
	public Cell
{
public:
	BombCell(int row, int col);
	~BombCell();
	virtual bool ActOn(Player* p);

};

