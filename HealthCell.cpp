#include "HealthCell.h"
#include "Player.h"


HealthCell::HealthCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\HealthCell.jpg";
}


HealthCell::~HealthCell()
{
}
bool HealthCell::ActOn(Player* p)
{
	p->sethealth();
	//Health cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}