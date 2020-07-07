#include "GUI.h"

GUI::GUI()
{

	// Colors

	MsgColor = DARKRED;		    // StatusBar Messages color
	BkGrndColor = DARKSLATEBLUE;	// Grid Background color
	StatusBarColor = GREY;       // StatusBar Background color

	GridLineColor = LIGHTGRAY;   // Vertical and Horizontal Lines
	ObstacleColor = BLACK;       // Background of Obstacles
	
	// Create the output window
	pWind = new window(WindWidth + 15, WindHeight, 5, 5); 

	// Change the title
	pWind->ChangeTitle("Game");
		
	CreateMenu();
	ClearGridArea();
	ClearStatusBar();

	InterfaceMode = MODE_MENU;
}


//window* GUI::CreateWind(int w, int h, int x, int y) const
//{ 
//	window* pW = new window(w, h, x, y);
//	/*pW->SetBrush(BkGrndColor);
//	pW->SetPen(BkGrndColor, 1);
//	pW->DrawRectangle(0, ToolBarHeight, w, h);	*/
//	return pW;
//}

//////////////////////////////////////////////////////////////////////////////////////////
// ================================== INPUT FUNCTIONS ===================================
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::GetPointClicked(int &x, int &y, bool wait) const
{
	if(wait)
		pWind->WaitMouseClick(x, y); // wait (pause) till a mouse click
	else
		pWind->GetMouseClick(x, y);	 // no wait
}

////////////////////////////////////////////////////////////////////////////////////////// 

string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	// ESCAPE key is pressed
			return "";	// returns nothing as user has cancelled label
		if(Key == 13 )	// ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	// BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		
		PrintMessage(Label);
	}
}

//======================================================================================//
//								Game  Functions									        //
//======================================================================================//

ActionType GUI::GetUserAction() const
{	
	int x = -1, y = -1;
	//Cell* p_dummy_status;

	//  ============ GUI in the MODE_MENU mode ============
	if ( InterfaceMode == MODE_MENU )	
	{
		pWind->WaitMouseClick(x, y);
		// [1] If user clicks on the Toolbar
		if ( y >= 0 && y < ToolBarHeight)
		{	
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==

			int ClickedItemOrder = (x / MenuItemWidth);

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_LOAD: return LOAD;
			case ITM_SAVE: return SAVE;
			case ITM_START: 
				pWind->FlushKeyQueue();
				pWind->FlushMouseQueue();

				return START;
			case ITM_PLAYER: 
				PrintMessage("you have clicked on player cell, please choose the cell");
				return PLAYER;
			case ITM_EMPTYCELL: 
				PrintMessage("you have clicked on an empty cell, please choose the cell" );
				return EMPTYCELL;
			case ITM_COIN:
				PrintMessage("you have clicked on coin cell, please choose the cell");
				return COIN;
			case ITM_BOMB:
				PrintMessage("you have clicked on a bomb cell, please choose the cell");
				return BOMB;
			case ITM_HEALTH: 
				PrintMessage("you have clicked on a health cell, please choose the cell");
				return HEALTH;
			case ITM_LIFE: 
				PrintMessage("you have clicked on a life cell, please choose the cell");
				return LIFE;
			case ITM_OBSTACLE:
				PrintMessage("you have clicked on an obstacle cell, please choose the cell");
				return OBSTACLE;
			case ITM_ENEMY: 
				PrintMessage("you have clicked on an enemy cell, please choose the cell");
				return ENEMY;
			case ITM_GOAL:
				PrintMessage("you have clicked on a goal cell, please choose the cell");
				return GOAL;


			case ITM_EXIT: return EXIT;

			///TODO: Add cases for the other items of Create-Grid Mode

			default: return EMPTY;	// A click on empty place in toolbar
			}
		}

		// [2] User clicks on the grid area
		if ( (y >= ToolBarHeight) && (y < WindHeight - StatusBarHeight))
		{
			return GRID_AREA;	
		}

		// [3] User clicks on the status bar
		return STATUS;
	}
	// ============ GUI in the GAME mode ============

	else	
	{

		char keyData;
		keytype Ktype = pWind->GetKeyPress(keyData);

		if(Ktype == ESCAPE )
		{
			pWind->FlushKeyQueue();
			pWind->FlushMouseQueue();
			return PAUSE;
		}
	
		if (Ktype == ARROW)		//move player using arrow keys
		switch(keyData)
		{
		case 2:	
			return MOVE_DOWN;
		case 4:	
			return MOVE_LEFT;
		case 6:	
			return MOVE_RIGHT;
		case 8:	
			return MOVE_UP;
		}


		return NO_MOVE; // if other keys is pressed OR if it can't move because of obstacle

		///TODO:
		// perform more checks iof needed and return the corresponding ActionType
	}	

}

Cell* GUI::status(ActionType p,int qx, int qy) const
{
	if (InterfaceMode == MODE_MENU)
	{
			

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (p)
			{
				{case EMPTYCELL:
					Cell* p_1 = new EmptyCell(qx, qy);
					return p_1;
					break;
				}
				{case PLAYER:
					Cell* p_1 = new PlayerCell(qx, qy);
					return p_1;
					break;
				}
				{case COIN:
					Cell* p_1 = new CoinCell(qx, qy);
					return p_1;
					break;
				}

				{case ENEMY:
					Cell* p_1 = new EnemyCell(qx, qy);
					return p_1;
					break;
				}
				{case HEALTH:
					Cell* p_1 = new HealthCell(qx, qy);
					return p_1;
					break;
				}
				{case GOAL:
					Cell* p_1 = new GoalCell(qx, qy);
					return p_1;
					break;
				}

				{case OBSTACLE:
					Cell* p_1 = new ObstacleCell(qx, qy);
					return p_1;
					break;
				}
				{case BOMB:
					Cell* p_1 = new BombCell(qx, qy);
					return p_1;
					break;
				}
				{case LIFE:
					Cell* p_1 = new LifeCell(qx, qy);
					return p_1;
					break;
				}
			default: return NULL;	// A click on empty place in toolbar
			}
		
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// ================================== OUTPUT FUNCTIONS ===================================
//////////////////////////////////////////////////////////////////////////////////////////

GUI_MODE GUI::getInterfaceMode() const
{
	return InterfaceMode;
}


void GUI::setInterfaceMode(GUI_MODE mode) 
{
	InterfaceMode = mode;
}

////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearStatusBar() const
{
	// Clear Status bar by drawing a filled rectangle with status bar background color
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, WindHeight - StatusBarHeight, WindWidth, WindHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearGridArea() const
{
	/*
	// Create a big rectangle with the background of the Grid
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, WindWidth, WindHeight - StatusBarHeight);
	*/
	// Set the pen of the vertical and horizontal lines of the Grid
	pWind->SetPen(GridLineColor,1);
	int x1, y1, x2, y2;

	// Draw Vertical Lines
	y1 = ToolBarHeight;
	y2 = WindHeight - StatusBarHeight;
	for (int i = 0; i < NumColumnCells; i++)
	{
		x1 = x2 = i * GridCellWidth; 
		pWind->DrawLine(x1, y1, x2, y2);
	}	
	
	// Draw Horizontal Lines
	x1 = 0;
	x2 = WindWidth;
	for (int i = 0; i < NumRowCells; i++) 
	{
		y1 = y2 = ToolBarHeight + i * GridCellWidth; 
		pWind->DrawLine(x1, y1, x2, y2);
	}	
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreateMenu() 
{
	InterfaceMode = MODE_MENU;

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way
	
	// First prepare List of images for each menu item
	// To control the order of these images in the menu, 
	// reoder them in UI_Info.h ==> enum MENU_ITEMS
	string MenuItemImages[MENU_ITM_COUNT];
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_START] = "images\\MenuItems\\Start.jpg";
	MenuItemImages[ITM_PLAYER] = "images\\Cells\\PlayerCell.jpg";
	MenuItemImages[ITM_EMPTYCELL] = "images\\Cells\\EmptyCell.jpg";
	MenuItemImages[ITM_COIN] = "images\\MenuItems\\Coin.jpg";
	MenuItemImages[ITM_BOMB] = "images\\Cells\\BombCell.jpg";
	MenuItemImages[ITM_HEALTH] = "images\\Cells\\HealthCell.jpg";
	MenuItemImages[ITM_LIFE] = "images\\Cells\\LifeCell.jpg";
	MenuItemImages[ITM_OBSTACLE] = "images\\Cells\\ObstacleCell.jpg";
	MenuItemImages[ITM_ENEMY] = "images\\Cells\\EnemyCell.jpg";
	MenuItemImages[ITM_GOAL] = "images\\Cells\\GoalCell.jpg";

	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Exit.jpg";

	///TODO: Prepare images for each menu item and add it to the list

	// Draw menu item one image at a time
	for(int i=0; i<MENU_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*MenuItemWidth, 0, MenuItemWidth, ToolBarHeight);

	// Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, WindWidth, ToolBarHeight);	

}


void GUI::CreateGameModeToolBar()
{
	pWind->SetPen(GridLineColor, 1);
	pWind->SetBrush(GridLineColor);
	pWind->DrawRectangle(0, MenuItemWidth, WindWidth, 0);
	PrintToolBarMessage();

	InterfaceMode = MODE_GAME;

	//string MenuItemImages[PLAY_ITM_COUNT];

	//MenuItemImages[ITM_CHOOSE_GRID] = "images\\Cells\\edit.jpg";
	//MenuItemImages[ITM_PAUSE] = "images\\MenuItems\\pause.jpg";

	//for (int i = 0; i < PLAY_ITM_COUNT; i++)
	//	pWind->DrawImage(MenuItemImages[i], i*MenuItemWidth, 0, MenuItemWidth, ToolBarHeight);

	// Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, WindWidth, ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(18, BOLD , BY_NAME, "Verdana");   
	pWind->DrawString(10, WindHeight - (int)(StatusBarHeight/1.3), msg);
}

void GUI::PrintToolBarMessage() const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(18, BOLD, BY_NAME, "Verdana");
	pWind->DrawString(350, 20, "To return to Grid Mode press ESC");
}
//======================================================================================//
//						Game Objects Drawing Functions   								//
//======================================================================================//

void GUI::DrawCell(const Cell * cell) const
{
	pWind->SetPen(ObstacleColor, 1);
	pWind->SetBrush(ObstacleColor);
	drawstyle style = FILLED;	

	int x = cell->getCol() * GridCellWidth;
	int y = ToolBarHeight + ( cell->getRow() * GridCellWidth );
	pWind->DrawImage(cell->getImage(),x+1, y+1, GridCellWidth-1, GridCellWidth-1) ;
}
//////////////////////////////////////////////////////////////////////////////////


//void GUI::ClearCell(const Cell & cell) const
//{
//	pWind->SetPen(GridLineColor, 1);
//	pWind->SetBrush(BkGrndColor);
//	int x1, y1, x2, y2;
//	x1 = cell.getCol() * GridCellWidth;
//	y1 = ToolBarHeight + ( cell.getRow() * GridCellWidth );
//	x2 = x1 + GridCellWidth;
//	y2 = y1 + GridCellWidth;
//	pWind->DrawRectangle(x1, y1, x2+1, y2+1);
//}

//////////////////////////////////////////////////////////////////////////////////////////




GUI::~GUI()
{
	delete pWind;
}
