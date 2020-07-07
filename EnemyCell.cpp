#include "EnemyCell.h"

EnemyCell::EnemyCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\EnemyCell.jpg";
}
EnemyCell::~EnemyCell()
{
}

bool EnemyCell::ActOn(Player* p) {

	p->sethealthEnemy();

	return false;
}