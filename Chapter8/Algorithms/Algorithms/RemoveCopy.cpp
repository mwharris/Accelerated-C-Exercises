#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include "RemoveCopy.h"

using std::endl;
using std::vector;
using std::back_inserter;

void test_remove_copy(std::ostream& out)
{
	const int remove_val = 20;
	out << endl << "TESTING MY REMOVE/COPY FUNCTION" << endl;

	//Create test vectors
	vector<int> result;
	static const int arr[] = {10,20,30,30,20,10,10,20};
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//Run the remove/copy
	my_remove_copy(test.begin(), test.end(), back_inserter(result), remove_val);

	//Print source vector
	out << "Source vector: ";
	for (vector<int>::const_iterator it = test.begin(); it != test.end(); it++)
	{
		if (it == test.begin())
		{
			out << *it;
		}
		else
		{
			out << ", " << *it;
		}
	}
	out << endl;

	//Print the removed calue
	out << "Removing " << remove_val << "..." << endl;

	//Print the destination vector to check results
	out << "Dest vector:   ";
	for (vector<int>::const_iterator it = result.begin(); it != result.end(); it++)
	{
		if (it == result.begin())
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