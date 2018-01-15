#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include "Transform.h"

using std::ostream;
using std::endl;
using std::vector;
using std::back_inserter;

int double_value(int& val_to_trans)
{
	return val_to_trans * 2;
}

void test_transform(ostream& out)
{
	out << "TESTING MY TRANSFORM FUNCTION" << endl;

	//Create a test vector
	static const int arr[] = { 1,2,4,8,16,32,64,128 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//Call the test function
	vector<int> result;
	my_transform(test.begin(), test.end(), back_inserter(result), double_value);

	//Print the results
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

	out << "After:  ";
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