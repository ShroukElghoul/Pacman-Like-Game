#include "Player.h"
#include "Grid.h"
#include "GUI.h"

int Player::num_of_coins = 0;
Player::Player()
{

}

Player::Player(Cell pos)
{
	PositionCell = pos;
	lives = 4;
	health = 100;
	score = 0;
	game = 0;


	// Makes all the needed initialization
}

void Player::Move(Grid* pGrid, ActionType dir)
{
	// Take a copy of the position before change
	Cell oldPosition = PositionCell; 

	// Try to take a Move from Keyboard
	GUI* pGUI = pGrid->getGUI();
	//DIRECTION dir = pGUI->TakeMoveDirection(PositionCell);

	// Check if the Move is Possible (No Obstacles)
	pGrid->MoveIfPossible(&PositionCell, dir); // if the move is possible, position will be changed (passed by ref)

}

void Player::setGame(int i)
{
	game = i;
}

int Player::getGame()
{
	return game;
}

void Player::setPosition(Cell pos)
{
	PositionCell = pos;
}

void Player::setscore() {
	score = score + 10;
}
void Player::setlifeAdd()
{
	lives = lives + 1;
}
void Player::setlifeSub()
{
	lives = lives - 1;

}
void Player::sethealth()
{
	health = health + 30;
	if (health > 100) {
		health = health - 100;
		lives = lives + 1;
	}
	else if (health <= 0 && lives>0) {
		health = 100;
		lives = lives - 1;
	}

}

void Player::sethealthEnemy()
{
	health = health - 30;
	if (health <= 0 && lives > 0) {
		health = 100;
		lives = lives - 1;
	}
}

int Player::getscore() {
	return score;
}
int Player::getlife() {
	return lives;
}

int Player::gethealth() {
	return health;
}


void Player::setCoinNum(int i)
{
	num_of_coins = i;
}
int Player::getCoinNum()
{
	return num_of_coins;
}
int Player::getNumOfRemainingCoins(int score)
{
	return (0.1*((num_of_coins * 10) - score));
}