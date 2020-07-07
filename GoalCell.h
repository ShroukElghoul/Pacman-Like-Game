#pragma once
#include "Cell.h"
class GoalCell :
	public Cell
{
public:
	GoalCell(int row, int col);
	~GoalCell();
	virtual bool ActOn(Player* p);

};