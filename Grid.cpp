#include "Grid.h"
#include "Enemy.h"
#include "Player.h"
#include "EmptyCell.h"
#include "PlayerCell.h"
#include <time.h>
#include <cstdlib>
#include <string>
using namespace std;

Grid::Grid() 
{
	// initializes all the GameObject pointer of the List to NULL
	for (int i = 0; i < NumRowCells; i++)
	{
		for (int j = 0; j < NumColumnCells; j++)		{
			
			GameCells[i][j] = new EmptyCell(i,j);	//start with all cells as empty cells
		}
	}
	pGUI = new GUI;
	DrawAllCells();
	
}



/////////////////////////////////////////////////////////////////////////////////////////////
// Moves the entered position in the passed direction if possible
// updates currentCell if move takes place
// Note: It returns bool indicating if a move occured or not

int* Grid::getRandMoveEnemy()
{
	srand(time(NULL));
	int* rand_num = new int[getEnemyNum()];

	for (int i = 0;i < getEnemyNum();i++) {
		int x = rand() % 8;
		rand_num[i] = x;
	}
	return rand_num;
}
void Grid::setEnemyNum(int i)
{
	num_of_enemy = i;
}
int Grid::getEnemyNum()
{
	return num_of_enemy;
}

//bool Grid::MoveIfPossible(Cell* pCurrentCell, ActionType dir) 
//{
//	
//	//Calculate the row and col of the cell to move to
//	//First initialize them as current row and col
//	int playerOldRow = pCurrentCell->getRow();
//	cout << "getRow = " << pCurrentCell->getRow() << endl;
//
//	int playerOldCol = pCurrentCell->getCol();
//
//	setTargetPlayerRow(playerOldRow);
//	setTargetPlayerCol(playerOldCol);
//
//
//	
//	switch(dir)
//	{
//	case MOVE_UP:
//		setTargetPlayerRow(getTargetPlayerRow() - 1);
//		break;
//	case MOVE_DOWN:
//		setTargetPlayerRow(getTargetPlayerRow() + 1);
//		break;
//	case MOVE_LEFT:
//		setTargetPlayerCol(getTargetPlayerCol() - 1);
//		break;
//	case MOVE_RIGHT:
//		setTargetPlayerCol(getTargetPlayerCol() + 1);
//		break;
//	}
//	cout << "target = " << getTargetPlayerCol() << endl;
//
//
//	if( !IsValidCell(getTargetPlayerRow(), getTargetPlayerCol()))
//		return false;
//
//	//get the target cell
//	Cell *pTargetCell = GameCells[getTargetPlayerRow()][getTargetPlayerCol()];
//
//	if (!pTargetCell->ActOn(player)) {
//		setTargetPlayerRow(playerOldRow);
//		setTargetPlayerCol(playerOldCol);
//		return false;
//	}	//The target cell is an obstacle ==> no action should be taken
//		
//		
//
//	//The target cell is not an obstacle and has acted on the player
//	//The player position should be updated to the target cell
//	
//	//Player should be moved to the target cell
//	//1-delete the target cell and make it point to the PlayerCell
//	setCell(getTargetPlayerRow(),getTargetPlayerCol(), pCurrentCell);
//
//	//2- update player position
//	pCurrentCell->SetRow(getTargetPlayerRow());
//	pCurrentCell->SetCol(getTargetPlayerCol());
//
//	//3- Convert the old player position to an Empty cell
//	GameCells[playerOldRow][playerOldCol] = new EmptyCell(playerOldRow,playerOldCol);
//
//	//4- Redraw both cells
//	pGUI->DrawCell(GameCells[getTargetPlayerRow()][getTargetPlayerCol()]);
//	pGUI->DrawCell(GameCells[playerOldRow][playerOldCol]);
//
//	return true;
//}

//bool Grid::MoveEnemyIfPossible(Cell * pCurrentCell, int dir)
//{
//
//	//Calculate the row and col of the cell to move to
//	//First initialize them as current row and col
//
//	int enemyOldRow = pCurrentCell->getRow();
//	cout << "getRow" << pCurrentCell->getRow() << endl;
//	int enemyOldCol = pCurrentCell->getCol();
//
//	setTargetEnemyRow(enemyOldRow);
//	setTargetEnemyCol(enemyOldCol);
//
//
//	switch (dir)
//	{
//	case 0:// up
//		setTargetEnemyRow(getTargetEnemyRow()-1);
//		break;
//	case 1:// diagonal left up
//		setTargetEnemyRow(getTargetEnemyRow() - 1);
//		setTargetEnemyCol(getTargetEnemyCol() - 1);
//		break;
//	case 2://move left
//		setTargetEnemyCol(getTargetEnemyCol() - 1);
//		break;
//	case 3://diagonal left down
//		setTargetEnemyRow(getTargetEnemyRow() + 1);
//		setTargetEnemyCol(getTargetEnemyCol() - 1);
//		break;
//	case 4:// down
//		setTargetEnemyRow(getTargetEnemyRow() + 1);
//		break;
//	case 5:// diagonal right down
//		setTargetEnemyRow(getTargetEnemyRow() + 1);
//		setTargetEnemyCol(getTargetEnemyCol() + 1);
//		break;
//	case 6://right
//		setTargetEnemyCol(getTargetEnemyCol() + 1);
//		break;
//	case 7://diagonal right up
//		setTargetEnemyRow(getTargetEnemyRow() - 1);
//		setTargetEnemyCol(getTargetEnemyCol() + 1);
//		break;
//	}
//	
//
//
//	if (!IsValidCell(getTargetEnemyRow(), getTargetEnemyCol()))
//		return false;
//
//
//
//	//get the target cell
//	Cell *pTargetCell = GameCells[getTargetEnemyRow()][getTargetEnemyCol()];
//
//	if (!pTargetCell->ActOnEnemy(enemy_pointers[0])) {
//		setTargetEnemyRow(enemyOldRow);
//		setTargetEnemyCol(enemyOldCol);
//		return false;
//	
//	}	//The target cell is an obstacle ==> no action should be taken
//		
//
//	//The target cell is not an obstacle and has acted on the player
//	//The player position should be updated to the target cell
//
//		//2- update player position
//	setCell(getTargetEnemyRow(), getTargetEnemyCol(), pCurrentCell);
//
//
//	//Player should be moved to the target cell
//	//1-delete the target cell and make it point to the PlayerCell
//	
//	pCurrentCell->SetRow(getTargetEnemyRow());
//	pCurrentCell->SetCol(getTargetEnemyCol());
//
//	//3- Convert the old player position to an Empty cell
//	GameCells[enemyOldRow][enemyOldCol] = new EmptyCell(enemyOldRow, enemyOldCol);
//
//	//4- Redraw both cells
//	pGUI->DrawCell(GameCells[getTargetEnemyRow()][getTargetEnemyCol()]);
//	pGUI->DrawCell(GameCells[enemyOldRow][enemyOldCol]);
//
//	return true;
//}
bool Grid::MoveIfPossible(Cell* pCurrentCell, ActionType dir)
{

	//Calculate the row and col of the cell to move to
	//First initialize them as current row and col
	int playerOldRow = pCurrentCell->getRow();
	int playerOldCol = pCurrentCell->getCol();

	int TargetRow = playerOldRow;
	int TargetCol = playerOldCol;


	switch (dir)
	{
	case MOVE_UP:
		TargetRow--;
		break;
	case MOVE_DOWN:
		TargetRow++;
		break;
	case MOVE_LEFT:
		TargetCol--;
		break;
	case MOVE_RIGHT:
		TargetCol++;;
		break;
	}

	if (!IsValidCell(TargetRow, TargetCol))
		return false;

	//get the target cell
	Cell *pTargetCell = GameCells[TargetRow][TargetCol];

	if (!pTargetCell->ActOn(player)) {
		 TargetRow = playerOldRow;
		 TargetCol = playerOldCol;//The target cell is an obstacle ==> no action should be taken
		return false;
	}
	//The target cell is not an obstacle and has acted on the player
	//The player position should be updated to the target cell

	//Player should be moved to the target cell
	//1-delete the target cell and make it point to the PlayerCell
	setCell(TargetRow, TargetCol, pCurrentCell);

	//2- update player position
	pCurrentCell->SetRow(TargetRow);
	pCurrentCell->SetCol(TargetCol);

	//3- Convert the old player position to an Empty cell
	GameCells[playerOldRow][playerOldCol] = new EmptyCell(playerOldRow, playerOldCol);

	//4- Redraw both cells
	pGUI->DrawCell(GameCells[TargetRow][TargetCol]);
	pGUI->DrawCell(GameCells[playerOldRow][playerOldCol]);

	return true;
}

bool Grid::MoveEnemyIfPossible(Cell * pCurrentCell, int dir)
{

	//Calculate the row and col of the cell to move to
	//First initialize them as current row and col
	int enemyOldRow = pCurrentCell->getRow();
	int enemyOldCol = pCurrentCell->getCol();

	int TargetRow = enemyOldRow;
	int TargetCol = enemyOldCol;


	switch (dir)
	{
	case 0:// up
		TargetRow--;
		break;
	case 1:// diagonal left up
		TargetRow--;
		TargetCol--;
		break;
	case 2://move left
		TargetCol--;
		break;
	case 3://diagonal left down
		TargetRow++;
		TargetCol--;
		break;
	case 4:// down
		TargetRow++;
		break;
	case 5:// diagonal right down
		TargetRow++;
		TargetCol++;
		break;
	case 6://right
		TargetCol++;;
		break;
	case 7://diagonal right up
		TargetRow--;
		TargetCol++;
		break;
	}



	if (!IsValidCell(TargetRow, TargetCol))
		return false;

	//get the target cell
	Cell *pTargetCell = GameCells[TargetRow][TargetCol];


	if (!pTargetCell->ActOnEnemy(enemy)) {
		 TargetRow = enemyOldRow;
		 TargetCol = enemyOldCol;//The target cell is an obstacle ==> no action should be taken
		return false;
	}
	//The target cell is not an obstacle and has acted on the player
	//The player position should be updated to the target cell

	//Player should be moved to the target cell
	//1-delete the target cell and make it point to the PlayerCell
	setCell(TargetRow, TargetCol, pCurrentCell);

	//2- update player position
	pCurrentCell->SetRow(TargetRow);
	pCurrentCell->SetCol(TargetCol);

	//3- Convert the old player position to an Empty cell
	GameCells[enemyOldRow][enemyOldCol] = new EmptyCell(enemyOldRow, enemyOldCol);

	//4- Redraw both cells
	pGUI->DrawCell(GameCells[TargetRow][TargetCol]);
	pGUI->DrawCell(GameCells[enemyOldRow][enemyOldCol]);

	return true;
}
void Grid::DrawAllCells() const	
{
	// Draw Empty Grid
	pGUI->ClearGridArea();

	// Draw all the GameObject of the Grid
	for (int i = 0; i < NumRowCells; i++)
		for (int j = 0; j < NumColumnCells; j++)
			pGUI->DrawCell(GameCells[i][j]);
}



void Grid::setCell(int row, int col, Cell* pCell)
{	
	if(GameCells[row][col])
		delete GameCells[row][col];	//if cell ptr is not null, delete it first
	
	GameCells[row][col] = pCell;

}


GUI * Grid::getGUI() const
{
	return pGUI;
}
///////////////////////////////////////////////////////////////////
//				Action-related functions
///////////////////////////////////////////////////////////////////

ActionType Grid::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pGUI->GetUserAction(); 
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void Grid::ExecuteAction(ActionType ActType) 
{
	
	// According to Action Type, create the corresponding action object	
	switch (ActType)
	{
	case LOAD:
		// Call Load function to load game from a file
		break;

	case SAVE:
		// Call Save function to Save current game to a file
		break;

	case START:	//start game 
		pGUI->setInterfaceMode(MODE_GAME);
		pGUI->CreateGameModeToolBar();
		break;

	case PAUSE:	//pause game
		cout << "in pause" << endl;
		pGUI->setInterfaceMode(MODE_MENU);
		pGUI->CreateMenu();


		break;

		///TODO: Add a case for EACH Action type
	case MOVE_UP:
	case MOVE_DOWN:
	case MOVE_RIGHT:
	case MOVE_LEFT:
	{
		player->Move(this, ActType);
		int* random = new int[getEnemyNum()];
		random = getRandMoveEnemy();

		for (int i = 0;i < getEnemyNum();i++) {
			//if (getTargetEnemyCol() != getTargetPlayerCol() || getTargetEnemyRow() != getTargetPlayerRow()) {

			enemy_pointers[i]->MoveEnemy(this, random[i]);
			//}
		}
		delete random;
		break;
	}
	case STATUS:	// a click on the status bar ==> no action
		return;
	}

}


Grid::~Grid()
{
	delete pGUI;
}

//////////////////////////////////////////////////////////////////////////////////


// Runs the application
int * Grid::getClickedCell(int w) const
{
	int x=-1;
	int y=-1;
	bool wait = 1;
	pGUI->GetPointClicked(x, y, w);
	ActionType t = pGUI->GetUserAction();
	switch (t) {
	case GRID_AREA:
	{int rrow = (y - StatusBarHeight) / GridCellWidth;
	int ccol = x / GridCellWidth;
	int row_col[2] = { rrow, ccol };

	int*p = row_col;
	return p;
	break;
	}
	case STATUS:
	{
		int rrow = y / GridCellWidth;
		int ccol = x / GridCellWidth;
		int row_col[2] = { rrow, ccol };

		int*p = row_col;
		return p;
		break;
	}
	default: return NULL;
	}
}

void Grid::RunApp()
{
	int i = 0,j=0;
	ActionType w;
	int* p;
	Cell z;

	while (1)
	{

		w = GetUserAction();
		if (w == LOAD || w == SAVE || w == PLAYER || w == EMPTYCELL || w == COIN || w == BOMB || w == HEALTH || w == LIFE || w == OBSTACLE || w == ENEMY || w == GOAL) {
			p = getClickedCell(1);

			if (p != NULL) {
				int row_clicked = p[0];
				int col_clicked = p[1];
				bool c = z.SetCol(col_clicked);
				bool r = z.SetRow(row_clicked);

				if (c == 1 && r == 1) {
					int qx = z.getRow();
					int qy = z.getCol();
					Cell* p_s = pGUI->status(w, qx, qy);
					setCell(qx, qy, p_s);
					if (w == PLAYER)
					{
						player = new Player(*p_s);
					}
					else if (w == ENEMY)
					{
						enemy_pointers[i] = new  Enemy(*p_s);
						setEnemyNum(i + 1);
						i++;
					}
					else if (w == COIN) {
						j++;
						Player::setCoinNum(j);
					}
					pGUI->DrawCell(p_s);
				}
			}
		}
		else if (w == EXIT)
			return;
		else {
			/*pGUI->CreateGameModeToolBar();*/
			//p = getClickedCell(1);
			string msg;
			string score = to_string(player->getscore());
			string health = to_string(player->gethealth());
			string lives = to_string(player->getlife());
			string rem_coins = to_string(player->getNumOfRemainingCoins(player->getscore()));

			if (player->getGame() == 1) {
				msg = ("           Congratulations!! You Won           ");
				msg.append("Score = ");
				msg.append(score);
			}
		

			else

			{

				msg=("Score = ");
				msg.append(score);
				msg.append("          Lives = ");
				msg.append(lives);
				msg.append("         Health = ");
				msg.append(health);
				msg.append("         Remaining Coins = ");
				msg.append(rem_coins);
			}

			pGUI->PrintMessage(msg);
			if (player->getGame() == 1) {
				Sleep(1000);
				return;
			}
			if (player->getlife() == 0) {
				pGUI->PrintMessage("GAME OVER");
				Sleep(1000);
				return;
			}

			ExecuteAction(w);
			
		}

		Sleep(100);

	}

}

////////////////////////////////////////////////////////////////////////////////////
bool Grid::IsValidCell(int row, int col) const
{
	return (row >= 0 && row < NumRowCells) 
			&& (col >=0 && col < NumColumnCells);
}

