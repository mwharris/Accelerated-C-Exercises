#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;

const int max = 1000;
const int maxColPad = 10;

int main()
{
	//Determine the maximum sizes we'll need
	string maxLeftStr = std::to_string(max);
	string maxRightStr = std::to_string(max * max);

	for (int i = 1; i <= max; i++)
	{
		//Determine the square value
		int square = i * i;

		//Turn the value and the square into strings
		string leftNumStr = std::to_string(i);
		string rightNumStr = std::to_string(square);
		
		//Print the row
		std::streamsize padding = (maxColPad - maxLeftStr.size()) - leftNumStr.size() + (rightNumStr.size() - 1);
		cout << i << setw(padding) << square << setw(0) << endl;
	}
    return 0;
}

