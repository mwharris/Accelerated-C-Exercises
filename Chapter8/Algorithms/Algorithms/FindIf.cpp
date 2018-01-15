#include "stdafx.h"
#include <iostream>
#include <string>

#include "FindIf.h"

using std::ostream;
using std::endl;
using std::string;

bool is_space(const char& c)
{
	return isspace(c);
}

void test_find_if(ostream& out)
{
	out << endl << "TESTING MY FIND-IF FUNCTION" << endl;

	//Create test strings
	string pass = "jhgsdbfjhabsdfk jasdbfjbadskfba";
	string fail = "lakjsndflkjnasdlf";

	//Run the test function
	bool should_pass = my_find_if(pass.begin(), pass.end(), is_space);
	bool should_fail = my_find_if(fail.begin(), fail.end(), is_space);

	//Display the results
	out << "Expected to be true:  " << should_pass << endl;
	out << "Expected to be false: " << should_fail << endl;
}