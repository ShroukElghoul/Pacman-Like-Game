#pragma once
#include "Cell.h"
class ObstacleCell :
	public Cell
{
public:
	ObstacleCell(int row, int col);
	~ObstacleCell();
	virtual bool ActOn(Player* p);

};