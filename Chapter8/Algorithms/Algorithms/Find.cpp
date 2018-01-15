#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

#include "Find.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void test_find(std::ostream& out)
{
	out << endl << "TESTING MY FIND FUNCTION" << endl;

	//Create a test vector to find
	vector<string> test;
	test.push_back("test_one");
	test.push_back("test_two");
	test.push_back("test_three");
	test.push_back("test_four");

	//Call our find function to pass and fail
	vector<string>::iterator pass_it = my_find(test.begin(), test.end(), "test_three");
	vector<string>::iterator fail_it = my_find(test.begin(), test.end(), "test_fuck");

	//Print results
	out << "Expected to be true: " << (pass_it != test.end()) << endl;
	out << "Expected to be false: " << (pass_it == test.end()) << endl;
}