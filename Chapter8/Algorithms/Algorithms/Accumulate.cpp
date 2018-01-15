#include "stdafx.h"
#include <iostream>
#include <vector>

#include "Accumulate.h"

using std::ostream;
using std::endl;
using std::vector;

void test_accumulate(ostream& out)
{
	out << "TESTING MY ACCUMULATE FUNCTION" << endl;

	//Create a test vector
	static const int arr[] = { 1,1,1,2,2,1,2,1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//Run the test function
	int result = accumulate(test.begin(), test.end(), 0);
	
	//Print the results
	out << "Expected: " << 1 + 1 + 1 + 2 + 2 + 1 + 2 + 1 << endl;
	out << "Actual:   " << result << endl;
}