#include "Cell.h"
#include "Player.h"
#include "GUI.h"

Cell::Cell () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	row = -1; 
	col = -1;
	//rowE = -1;
	//colE = -1;

}

Cell::Cell (int r, int c)
{ 
	SetRow(r);
	SetCol(c);	
}

bool Cell::SetRow(int c) // the setter of row (the setter here sets only if in the the cell is in grid range)
{
	if (c >=0 && c < NumRowCells)
	{
		row = c;
		return true;
	}
	return false;
}

bool Cell::SetCol(int c) // the setter of col (the setter here sets only if in the the cell is in grid range)
{
	if (c >=0 && c < NumColumnCells)
	{
		col = c;
		return true;
	}
	return false;
}


int Cell::getRow() const // the getter of row
{
	return row;
}

int Cell::getCol() const // the getter of col
{
	return col;
}


bool Cell::ActOnEnemy(Enemy * p)
{

	return false;
}

string Cell::getImage() const
{
	return ImagePath;
}


bool Cell::operator == (const Cell & other) const
{
	return (row == other.getRow()) && (col == other.getCol());
}

bool Cell::operator != (const Cell & other) const
{
	return ! ((*this) == other);
}

//void Cell::set_player_enemy_check()
//{
//	player_enemy_collision = 0;
//}
//
//bool Cell::get_player_enemy_check()
//{
//	return player_enemy_collision;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////
//returns true if current cell is not an obstacle
bool Cell::ActOn(Player* p)
{	
	
	//ActOn overridden functions work fine in all the static cells, but it always comes to default in the enemy cell so I made the defauld state fits the enemy cell
	p->sethealthEnemy();
	cout << "Health after collision = " << p->gethealth() << endl;
	cout << "this is enemyCell ActOn" << endl;
	return false;	

}

Cell::~Cell()
{}


