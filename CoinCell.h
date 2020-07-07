#pragma once
#include "Cell.h"
class CoinCell :
	public Cell
{
public:
	CoinCell(int row, int col);
	~CoinCell();
	virtual bool ActOn(Player* p);

};
