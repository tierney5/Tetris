#include <SFML/Graphics.hpp>
#include "tetris.h"
#include<iostream>
using namespace std;

	Board newTile;           //used to be a tiles object
	const int row = 30;
	const int column = 20;
	sf::RenderWindow window(sf::VideoMode(320, 480), "tetris!");


	int field[row][column] = { 0 };
	//bool canGoThere = true;
	//sf::Sprite sprite;
	//sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris");
	//reconfigure to use window instead of the weird field thing
	struct Point
	{
		int x, y;
	} b[4], a[4];

	int figures[7][4] =
	{
		1,3,5,7,
		2,4,5,7,
		3,5,4,6,
		3,5,4,7,
		2,3,5,7,
		3,5,7,6,
		2,3,4,5,
	};


	bool canMoveDown;
	bool check() //MAKE ALL OF THESE GOING THROUGH THE FOR LOOPS
	{
		for (int x = 0; x < column; x++)
		{
			for (int y = 0; y < row; y++)
			{
				newTile.boardVector[x][y].canMove = true; //need point of where in vector
				canMoveDown = true;
				for (int i = 0; i < 4; i++)
				{

					if (a[i].x < 0 || a[i].y >= row || b[i].y >= row)
						//|| b[i].y < 0)
						//|| a[i].x >= column)
					{
						canMoveDown = false;
						//newTile.canMove = false;
					}
					if (a[i].x < 0 || a[i].x >= column || b[i].x >= column)
					{
						newTile.boardVector[x][y].canMove = false;
						//canMoveDown = false;
					}
				}

				//make functions that include the object
				//this should connect the sprite to the movement and allow you to find out where it is so you can prevent it from 
				//hitting other blocks
				if (!canMoveDown)
				{

					newTile.boardVector[x][y].canMove = false;
				}

				//return false;
				return newTile.boardVector[x][y].canMove;
			}
		}
	}

	bool noTilePlacement()
	{

		for (int x = 0; x < column; x++)
		{
			for (int y = 0; y < row; y++)
			{
				newTile.boardVector[x][y].canMove = true; //need point of where in vector
				canMoveDown = true;
				for (int i = 0; i < 4; i++)
				{
					//check();
					/*if (!check())
					{
						cout << "true" << endl;
					}*/
					if (newTile.boardVector[x][y].canMove == false) //maybe try vector . contains again??
					{
						newTile.boardVector[x][y].canGoThere = false;
						cout << x << " " << y << endl;
					}
				}
		return newTile.boardVector[x][y].canGoThere;
			}
		}
		//cout << newTile.sprite.getGlobalBounds().width << endl;
		//bool canGoThere = true;
		//sf::Event event;
		//if (event.MouseButtonPressed)
		//{
		//	for (int i = 0; i < column; i++)
		//	{
		//		for (int j = 0; j < row; j++) //SWITCH COLUMN AND ROW EVERYWHERE BUT HERE
		//		{
		//			if (!newTile.boardVector[i][j].canMove) //used to be can move down to fix edge problem
		//				//&& !newTile.boardVector[i][j].canMoveDown)
		//				//!check() && field[i][j] != 0) //in theory this should tell where tiles are
		//			{
		//				//field[i][j].canGoThere = false;
		//				newTile.boardVector[i][j].canGoThere = false;
		//				cout << "false" << endl;
		//			}
		//			if (newTile.boardVector[i][j].canGoThere == false)
		//			{
		//				cout << i << " " << j << endl;
		//			}
		//			return newTile.boardVector[i][j].canGoThere;
		//		}
		//	}
		//}
	}


int main()
{

	//sf::RenderWindow window(sf::VideoMode(320, 480), "tetris!");
	sf::Texture tile;
	tile.loadFromFile("images/tetrisTiles.png");
	sf::Sprite block;
	block.setTexture(tile);
	block.setTextureRect(sf::IntRect(0, 0, 12, 13));
	newTile.sprite = block;
	newTile.setBoard(window, newTile.sprite, newTile);
	Board newTile;
	const int row = 30;
	const int column = 20;

	int field[row][column] = { 0 };

	//noTilePlacement();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (check())
			{
				newTile.canMove = true;
				newTile.canMoveDown = true;
				//newTile.rotate = true;
				newTile.movement = 0;
				newTile.goingDown = 0;
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Left)
					{
						newTile.movement = -1;
					}
					else if (event.key.code == sf::Keyboard::Right && newTile.canMove && canMoveDown) 
						//&& !noTilePlacement())
					{
						newTile.movement = 1;
					}
					//else if (event.key.code == sf::Keyboard::Down)
					//{
					//	check();
					//	newTile.goingDown = 1;
					//	//go down
					//}
				}

				//for (int i = 0; i < 4; i++)
				//{
				//	//if (check())
				//	//{
				//		a[i].x += newTile.movement;
				//	//}
				//	//if (canMoveDown)
				//	//{
				//	a[i].y += newTile.goingDown;

				//	//}
				//}
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up && canMoveDown)
				{
					newTile.rotate = true;
					
					//if(newTile.rotate)
					//block.rotate(90);
					//newTile.rotate = true;
					//newTile.checkRotation(newTile, block);
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					//check();
					newTile.goingDown = 1;
					//go down
				}
				for (int i = 0; i < 4; i++)
				{
					if (canMoveDown && newTile.canMove) 
						//&& noTilePlacement())
					{
						b[i] = a[i];
					}
					//if (noTilePlacement())
					//{
						a[i].x += newTile.movement;
					//}
					
					
					if (canMoveDown) 
						//&& noTilePlacement())
					{
						a[i].y += newTile.goingDown;

					}

				}
				if (!check())
				{
					for (int i = 0; i < 4; i++)
					{
						//b[i] = a[i];
					}
					//this is fucking up stopping at the bottom
				}
			}
			
		}

		if (noTilePlacement())
		{
			newTile.canMove = false;
		}

		if (newTile.rotate)
		{
			Point p = a[1];
			for (int i = 0; i < 4; i++)
			{
				int rotationPointY = a[i].x - p.x;
				int rotationPointX = a[i].y - p.y;
				a[i].x = p.x - rotationPointX;
				a[i].y = p.y + rotationPointY;
			}
		}
		int setup = 3;
		//if (4 > 3)
		//{
		if (canMoveDown && !check() && noTilePlacement())
		{
			for (int i = 0; i < 4; i++)
			{
				a[i] = b[i];
				//a[i].x += 1;
				a[i].y += 1;
			}
			//had it in bottom, causing problems when stopping on side
		}
			if (!check())
			{
				for (int i = 0; i < 4; i++)
				{
					/*a[i] = b[i];
					a[i].y += 1;*/
					field[b[i].y][b[i].x] = 3;
					/*for (int j = 0; j < 4; j++)
					{
						a[j].x = figures[setup][j] % 2;
						a[j].y = figures[setup][j] / 2;
					}*/

				}
				int n = rand() % 7;
				for (int j = 0; j < 4; j++)
				{
					a[j].x = figures[n][j] % 2;
					a[j].y = figures[n][j] / 2;
				}
			}
		//}

			bool fullLine = false;
			int placement = row-1;
			for (int i = row - 1; i > 0; i--)
			{
			int num = 0;
				for (int j = 0; j < column; j++)
				{
					if (field[i][j] == 0)
					{
						fullLine = false;
					}
					else if (field[i][j] !=0 && !canMoveDown)
					{
						num++;
					}
						field[placement][j] = field[i][j];//does literal exact opposite
				}
					if (num < column)
					{
						placement--;
					}
			}

			

		/*int setup = 3;
		if (a[0].x == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				a[i].x = figures[setup][i] % 2;
				a[i].y = figures[setup][i] / 2;
			}
		}*/

		newTile.movement = 0;
		newTile.goingDown = 0;
		newTile.rotate = 0;
		newTile.boardVector.clear();
		window.clear();

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (field[i][j] == 0)
				{
					continue;
				}
				block.setPosition(j * 12, i * 12);
				window.draw(block);
			}
		}
		newTile.movement = 0;
		newTile.goingDown = 0;
		newTile.rotate = 0;
		for (int i = 0; i < 4; i++)
		{
			block.setPosition(a[i].x * 12, a[i].y * 12);
			window.draw(block);
		}
		window.display();
	}

	return 0;
}