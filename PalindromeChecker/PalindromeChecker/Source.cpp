#include <iostream>
#include <string>

using namespace std;

int main(int argCount, char* argVector[]) 
{
	
	for (int i = 1; i < argCount; i++) 
	{
		bool result = true;
		int stringLength = string(argVector[i]).length();

		for (int j = 0; j < stringLength/2; j++)
		{
			if (argVector[i][j] != argVector[i][stringLength - j - 1])
			{
				result = false;
				break;
			}
		}
		cout << string(argVector[i]) << " " << to_string(result) << endl;
	}
	
	return 0;
}