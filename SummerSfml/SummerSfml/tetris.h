#pragma once
#include <vector>
using namespace std;


class Tetris
{
public:
	sf::Sprite sprite;
	bool rotate;
	bool canMove;
	bool canMoveDown;
	int space;
	int movement;
	int goingDown;
	sf::Vector2f vector;
	bool getRotate();
	void checkRotation(Tetris newTile, sf::Sprite sprite);
	int getSpace();
	bool canGoThere = true;

};

class Board
{
public:
	bool rotate;
	bool canMove;
	bool canMoveDown;
	int space;
	int movement;
	int goingDown;
	 vector<vector<Tetris>> boardVector;
	 sf::Sprite sprite;
	 void setBoard(sf::RenderWindow &window, sf::Sprite sprite, Board &boardObj);
};