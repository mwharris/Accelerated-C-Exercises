#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include "RemoveCopyIf.h"

using std::ostream;
using std::endl;
using std::vector;
using std::back_inserter;

bool is_two(const int& i)
{
	return i == 2;
}

void test_remove_copy_if(ostream& out)
{
	out << endl << "TESTING MY REMOVE/COPY-IF FUNCTION" << endl;

	//Create a test vector
	static const int arr[] = { 1,1,1,2,2,1,2,1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//Print the test vector
	out << "Original: ";
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
	out << endl << "Removing zeroes..." << endl;

	//Run the test function
	vector<int> result;
	my_remove_copy_if(test.begin(), test.end(), back_inserter(result), is_two);

	//Print the result vector
	out << "Result: ";
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