#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include "Remove.h"

using std::endl;
using std::ostream;
using std::vector;

void test_remove(ostream& out)
{
	out << "TESTING MY REMOVE FUNCTION" << endl;

	//Create a test vector
	static const int arr[] = { 1,1,1,2,2,1,2,1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));

	out << "Before: ";
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

	//Call the test function and remove the end
	out << "Removing twos..." << endl;
	vector<int>::const_iterator it = my_remove(test.begin(), test.end(), 2);
	test.erase(it, test.end());

	out << "After: ";
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
}