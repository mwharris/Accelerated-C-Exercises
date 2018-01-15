#include "stdafx.h"
#include <iostream>
#include <vector>

#include "Partition.h"

using std::ostream;
using std::endl;
using std::vector;
bool is_even(const int& elem)
{
	if (elem % 2 == 0)
	{
		return true;
	}
	return false;
}

void test_partition(ostream& out)
{
	out << "TESTING MY PARTITION FUNCTION" << endl;

	//Create a test vector
	static const int arr[] = { 1,2,1,2,2,1,2,1,1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//Print our original vector
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

	//Call our test function
	my_partition(test.begin(), test.end(), is_even);

	//Print our resulting vector
	out << "After:  ";
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