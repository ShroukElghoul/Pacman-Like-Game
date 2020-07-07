#include "LadderCell.h"



LadderCell::LadderCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\LadderCell.jpg";
}


LadderCell::~LadderCell()
{
}
bool LadderCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}