#include "GameUtilities.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

GameUtilities::GameUtilities() //creates a new instance of the GameUtilities class
{
	grid = vector<vector<int>>();
}

void GameUtilities::CreateBoard(int rowCount, int columnCount)
{
	//clear out any existing board
	grid.clear();

	for (int i = 0; i < rowCount; i++)
	{
		//add to the end of a vector
		grid.push_back(vector<int>());

		for (int j = 0; j < columnCount; j++)
		{
			grid[i].push_back(0);
		}
	}
}

void GameUtilities::PrintBoard()
{
	for (vector<int> currentRow : grid) // : operator works the same as "IN" operator in a foreach statement
	{
		string currentRowString = "";

		for (int currentCell : currentRow)
		{
			if (currentCell == 1)
			{
				currentRowString += "X";
			}
			else if (currentCell == 2)
			{
				currentRowString += "O";
			}
			else
			{
				currentRowString += "-";
			};
		}

		cout << currentRowString << endl;
	}

}

bool GameUtilities::UpdateBoard(int x, int y, int playerId)
{
	if (grid[x][y] == 0)
	{
		grid[x][y] = playerId;
		return true;
	}
	else
	{
		return false;
	}
}

bool GameUtilities::PlayerWon(int x, int y, int playerId)
{
	//check for row win
	if (grid[0][y] == playerId && grid[1][y] == playerId && grid[2][y])
	{
		return true;
	}

	//check for column win
	else if (grid[x][0] == playerId && grid[x][1] == playerId && grid[x][2])
	{
		return true;
	}

	//check for diagonal win

	else if (
				(grid[0][0] == playerId && grid[1][1] == playerId && grid[2][2] == playerId)
				||
				(grid[2][0] == playerId && grid[1][1] == playerId && grid[0][2] == playerId)
			)
	{
		return true;
	}

	return false;
}