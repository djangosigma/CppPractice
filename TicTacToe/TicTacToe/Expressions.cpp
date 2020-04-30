#include <string>

#include "Expressions.h"

using namespace std;

namespace Expressions
{
	bool isNumeric(string str)
	{
		for (unsigned int i = 0; i < str.length(); i++)
		{
			if (isdigit(str[i]) == false)
			{
				return false; //when one non numeric value is found, return false
			}
		}
		return true;
	}
}
