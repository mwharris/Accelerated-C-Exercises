#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iomanip>

#include "Copy.h"

using std::endl;
using std::vector;
using std::back_inserter;

void test_copy(std::ostream& out)
{
	out << endl << "TESTING MY COPY FUNCTION" << endl;

	//Set up vector to copy
	vector<int> source;
	source.push_back(4);
	source.push_back(2);
	source.push_back(8);
	source.push_back(6);
	source.push_back(0);

	//Destination vector
	vector<int> dest;

	//Copy the vector to dest
	my_copy(source.begin(), source.end(), back_inserter(dest));

	//Print source vector
	out << "Source vector: ";
	for (vector<int>::const_iterator it = source.begin(); it != source.end(); it++)
	{
		if (it == source.begin())
		{
			out << *it;
		}
		else
		{
			out << ", " << *it;
		}
	}
	out << endl;

	//Print the destination vector to check results
	out << "Dest vector:   ";
	for (vector<int>::const_iterator it = dest.begin(); it != dest.end(); it++)
	{
		if (it == dest.begin())
		{
			out << *it;
		}
		else
		{
			out << ", " << *it;
		}
	}
	out << endl;
}