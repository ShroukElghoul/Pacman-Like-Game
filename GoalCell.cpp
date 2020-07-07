#include "GoalCell.h"
#include <iostream>
#include "Player.h"
using namespace std;


GoalCell::GoalCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\GoalCell.jpg";
}


GoalCell::~GoalCell()
{
}
bool GoalCell::ActOn(Player* p)
{
	if (p->getNumOfRemainingCoins(p->getscore()) == 0)
	{
		p->setGame(1);
		return true;

	}
	//else if (p->getNumOfRemainingCoins(p->getscore()) > 0) {
	//	p->setGame(2);
	//	return false;

	//}
	else
		return false;
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
}