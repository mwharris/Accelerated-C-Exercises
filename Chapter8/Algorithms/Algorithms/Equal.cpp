#include "stdafx.h"
#include <vector>
#include <iostream>

#include "Equal.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

void create_pass_vector(vector<int>&v)
{
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
}

void create_fail_vector(vector<int>&v)
{
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
}

void test_equal(std::ostream& out)
{
	out << endl << "TESTING MY EQUAL FUNCTION" << endl;

	//Create passing tests
	vector<int> pass_first, pass_second;
	create_pass_vector(pass_first);
	create_pass_vector(pass_second);

	//Create failing tests
	vector<int> fail;
	create_fail_vector(fail);

	//Run both tests
	bool should_pass = my_equal(pass_first.begin(), pass_first.end(), pass_second.begin());
	bool should_fail_1 = my_equal(pass_first.begin(), pass_first.end(), fail.begin());
	bool should_fail_2 = my_equal(fail.begin(), fail.end(), pass_second.begin());

	out << "Expected to be true:  " << should_pass << endl;
	out << "Expected to be false: " << should_fail_1 << endl;
	out << "Expected to be false: " << should_fail_2 << endl;
}