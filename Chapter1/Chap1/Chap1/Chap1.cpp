#include "stdafx.h"
#include <iostream>
#include <string>

//const int padding = 3;

int main()
{
	using namespace std;

	cout << "Please enter your name: ";
	string name;
	cin >> name;

	cout << "Please enter the desired greeting spacing: ";
	int padding;
	cin >> padding;

	const int rows = (padding * 2) + 3;

	string greeting = "Hello " + name + "!";
	
	const string::size_type columns = greeting.size() + (padding * 2) + 2;

	for (int r = 0; r < rows; r++)
	{
		string row = "";
		for (string::size_type c = 0; c < columns; c++)
		{
			if (r == padding + 1 && c == padding + 1)
			{
				row = row + greeting;
				c += greeting.size() - 1;
			} 
			else if (r == 0 || r + 1 == rows || c == 0 || c + 1 == columns)
			{
				row = row + "*";
			}
			else 
			{
				row = row + " ";
			}
		}
		cout << row << endl;
	}

    return 0;
}

