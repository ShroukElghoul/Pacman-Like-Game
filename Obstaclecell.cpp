#include "ObstacleCell.h"
#include <iostream>
using namespace std;

ObstacleCell::ObstacleCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\ObstacleCell.jpg";
}


ObstacleCell::~ObstacleCell()
{
}

bool ObstacleCell::ActOn(Player* p)
{
	cout<<"obstacle"<<endl;
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return false;
}
