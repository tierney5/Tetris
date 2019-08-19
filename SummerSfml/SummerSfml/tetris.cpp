#include <SFML/Graphics.hpp>
#include "tetris.h"

void Tiles()
{
	
}

bool Tetris::getRotate()
{
	if (rotate == true)
	{
		return true;
	}
	else
		return false;
}

void Tetris::checkRotation(Tetris newTiles, sf::Sprite sprite)
{
	if (newTiles.rotate)
	{
		newTiles.sprite.rotate(10);
	}
}
void Board::setBoard(sf::RenderWindow &window, sf::Sprite sprite, Board &boardObj)
{
	for (int i = 0; i < 20; i++)
	{
		vector<Tetris> newVector;
		for (int j = 0; j < 30; j++)
		{
			Tetris newTile;
			newTile.sprite.setPosition(j * 12, i * 12);
			newTile.sprite = sprite;
			newTile.sprite.setPosition(j * 12, i * 12);

			newVector.push_back(newTile);
		}
		boardVector.push_back(newVector);
	}
}