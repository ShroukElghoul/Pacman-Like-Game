#pragma once
#include "Cell.h"
class LadderCell :
	public Cell
{
public:
	LadderCell(int row, int col);
	~LadderCell();
	virtual bool ActOn(Player* p);

};