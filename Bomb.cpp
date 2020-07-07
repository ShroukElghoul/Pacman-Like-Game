#include "BombCell.h"
#include "Player.h"



BombCell::BombCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\BombCell.jpg";
}


BombCell::~BombCell()
{
}
bool BombCell::ActOn(Player* p)
{
	p->setlifeSub();
	cout << "life after bomb = " << p->getlife() << endl;
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}