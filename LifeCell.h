#pragma once
#include "Cell.h"
class LifeCell :
	public Cell
{
public:
	LifeCell(int row, int col);
	~LifeCell();
	virtual bool ActOn(Player* p);

};