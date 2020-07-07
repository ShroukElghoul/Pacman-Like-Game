#pragma once
#include "Cell.h"
class HealthCell : public Cell
{
public:
	HealthCell(int row, int col);
	~HealthCell();
	virtual bool ActOn(Player* p);

};