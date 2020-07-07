#include "CoinCell.h"
#include "Player.h"


CoinCell::CoinCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\CoinCell.jpg";
}


CoinCell::~CoinCell()
{
}
bool CoinCell::ActOn(Player* p)
{
	p->setscore();
	cout << "score = " << p->getscore() << endl;

	return true;
}