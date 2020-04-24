#include <string>
#include <iostream>

using namespace std;

bool isNumeric(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string minValue, maxValue;
	int min, max;

	cout << "Fizzbuzz: You know the rules" << endl;

	do
	{
		cout << "Declare the minimum range:";
		cin >> min;
	} while (isNumeric(minValue) == false);
	min = stoi(minValue);

	do
	{
		cout << "Declare the maximum range:";
		cin >> max;
	} while (isNumeric(maxValue) == false);
	max = stoi(maxValue);

	//do the thing
	for (int i = min; i <= max; i++)
	{
		if (i % 3 == 0)
			cout << "fizz";
		if (i % 5 == 0)
			cout << "buzz";
		if (i % 3 != 0 && i % 5 != 0)
			cout << to_string(i);
		cout << endl;
	}
}