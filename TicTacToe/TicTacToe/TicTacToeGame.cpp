#include <cstdlib>
#include <string>
#include <iostream>
#include <time.h>
#include <vector>

#include "Expressions.h"
#include "GameUtilities.h"

using namespace std;
using namespace Expressions;

int main()
{
	GameUtilities TicTacToeGame = GameUtilities(); 
	string input = "";

	//create a board
	int rowNum = 3;
	int colNum = 3;
	TicTacToeGame.CreateBoard(rowNum, colNum);
	cout << "You are now playing Tic-Tac-Toe." << endl << endl;

	TicTacToeGame.PrintBoard();
	cout << endl << "Player 1 (X) -------- Player 2 (O)" << endl << endl;

	////Optionally add AI to replace player 2
	////get player count from user input
	//string input = "";
	//do
	//{
	//	cout << "Enter player count..." << endl;
	//	cin >> input;
	//} while (isNumeric(input) == false);

	//int playerCount;
	//if (input == "2")
	//{
	//	playerCount = 2;
	//}
	//else
	//{
	//	playerCount = 1;
	//}


	bool playAgain = false;
	bool gameOver = false;
	int turnCount = 0;
	int x;
	int y;
	bool playerChoseValidCoordinates = false;

	//main game loop
	do
	{
		//player 1 turn
		//get input from the player
		input = "";
		x = 999;
		y = 999;
		playerChoseValidCoordinates = false;
		do
		{
			do //he said "do do" lol
			{
				cout << "Player 1: Choose an X coordinate." << endl;
				cin >> input;

				if (isNumeric(input))
				{
					x = stoi(input) - 1; //minus 1 because arrays are 0-indexed
				}

			} while (x < 0 || x >= rowNum);

			input = "";
			do
			{
				cout << "Player 1: Choose a Y coordinate." << endl;
				cin >> input;

				if (isNumeric(input))
				{
					y = stoi(input) - 1;
				}

			} while (y < 0 || y >= rowNum);

			//validate input and update board
			playerChoseValidCoordinates = TicTacToeGame.UpdateBoard(x, y, 1);

		} while (playerChoseValidCoordinates == false);

		TicTacToeGame.PrintBoard();
		turnCount++;

		if (TicTacToeGame.PlayerWon(x, y, 1))
		{
			cout << "Player 1 Wins!" << endl;
			gameOver = true;
			break;
		}

		//check game state

		//player 2 turn
		//get input from the player
		input = "";
		x = 999;
		y = 999;
		playerChoseValidCoordinates = false;
		do
		{
			do
			{
				cout << "Player 2: Choose an X coordinate." << endl;
				cin >> input;

				if (isNumeric(input))
				{
					x = stoi(input) - 1; //minus 1 because arrays are 0-indexed
				}

			} while (x < 0 || x >= rowNum);

			input = "";
			do
			{
				cout << "Player 2: Choose a Y coordinate." << endl;
				cin >> input;

				if (isNumeric(input))
				{
					y = stoi(input) - 1;
				}

			} while (y < 0 || y >= rowNum);

			//validate input and update board
			playerChoseValidCoordinates = TicTacToeGame.UpdateBoard(x, y, 2);

		} while (playerChoseValidCoordinates == false);

		TicTacToeGame.PrintBoard();
		turnCount++;

		if (turnCount >= 9 || TicTacToeGame.PlayerWon(x, y, 2))
		{
			cout << "Player 2 Wins!" << endl;
			gameOver = true;
			break;
		}

	} while (gameOver == false);


}