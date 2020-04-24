#include <random>
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

//bugs
//escaped characters can be input
//inputting numbers outside integer range will break things

bool isNumeric(string str) 
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
		{
			return false; //when one non numeric value is found, return false
		}
	}
	return true;
}

int main()
{
	cout << "Rock Paper Scissors:" << endl;

	//game starts, ask for number of players (1-2)
	string input = "";
	do
	{
		cout << "Enter player count..." << endl;
		cin >> input;
	} while (isNumeric(input) == false);

	//assume the player entered a valid number
	int playerCount;
	if (input == "2")
	{
		playerCount = 2;
	}
	else
	{
		playerCount = 1;
	}
	

	//ask for maximum win count before ending set
	do
	{
		cout << "Enter number of rounds to win set..." << endl;
		cin >> input;
	} while (isNumeric(input) == false);

	int roundsToWin = stoi(input);

	int playerOneWinCount = 0;
	int playerTwoWinCount = 0;

	int rock = 1;
	int paper = 2;
	int scissors = 3;

	//main game loop
	while (playerOneWinCount < roundsToWin && playerTwoWinCount < roundsToWin)
	{
		int playerOneChoice = 0;
		int playerTwoChoice = 0;

		//player 1 turn
		input = "";
		cout << "Player 1's Turn" << endl;
		do
		{
			cout << "1: Rock, 2: Paper, 3: Scissors" << endl;
			cin >> input;
		} while (isNumeric(input) == false || stoi(input) < 1 || stoi(input) > 3); //relies on short-circuiting otherwise stoi() dies

		playerOneChoice = stoi(input);

		//player 2/ai turn
		input = "";
		cout << "Player 2's Turn" << endl;
		if (playerCount == 1)
		{
			//pick player 2's move randomly
			srand(time(0));

			int max = 3;
			int min = 1;
			int randomNumber = rand() % (max - min + 1) + min;

			cout << to_string(randomNumber) << endl;
			input = to_string(randomNumber);
		}
		else
		{
			do
			{
				cout << "1: Rock, 2: Paper, 3: Scissors" << endl;
				cin >> input;
			} while (isNumeric(input) == false || stoi(input) < 1 || stoi(input) > 3);
		}
		
		playerTwoChoice = stoi(input);

		//player 1 wins
		if (playerOneChoice == playerTwoChoice + 1 || playerOneChoice == playerTwoChoice - 2)
		{
			cout << "Player 1 Wins!" << endl;
			playerOneWinCount++;
		}
		//player 2 wins
		else if (playerTwoChoice == playerOneChoice + 1 || playerTwoChoice == playerOneChoice - 2)
		{
			cout << "Player 2 Wins!" << endl;
			playerTwoWinCount++;
		}
		else //(playerOneChoice == playerTwoChoice)
		{
			cout << "Tie!" << endl;
		}

		cout << "Win Count: Player 1 (" << to_string(playerOneWinCount) << ") | Player 2 (" << to_string(playerTwoWinCount) << ")" << endl << endl;
	}

	cout << "Game Over" << endl;
}