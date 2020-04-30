//file GameUtilities.h
#pragma once

#include <vector>

using namespace std; //i thought you weren't supposed to use namespaces in header files but this just throws a ton of errors otherwise

class GameUtilities
{
public:
	vector<vector<int>> grid;
	GameUtilities(); //constructor
	void CreateBoard(int rowCount = 8, int columnCount = 8); //default arguments determined in the header, not the source
	void PrintBoard();
	bool UpdateBoard(int x, int y, int playerId);
	bool PlayerWon(int x, int y, int playerId);
};