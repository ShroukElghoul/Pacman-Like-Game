#include "LifeCell.h"
#include "Player.h"


LifeCell::LifeCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\LifeCell.jpg";
}
LifeCell::~LifeCell()
{
}
bool LifeCell::ActOn(Player* p)
{
	p->setlifeAdd();
	//Life cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}