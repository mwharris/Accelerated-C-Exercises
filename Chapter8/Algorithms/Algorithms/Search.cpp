#include "stdafx.h"
#include <iostream>
#include <string>

#include "Search.h"

using std::ostream;
using std::endl;
using std::string;

void test_search(ostream& out)
{
	out << endl << "TESTING MY SEARCH FUNCTION" << endl;

	//Create a test vector
	string str = "My name is Michael Harris and I am gay.";
	string search = "Michael";
	string::const_iterator expected = str.begin() + 11;

	//Run the test function
	string::iterator it = my_search(str.begin(), str.end(), search.begin(), search.end());

	//Test we received the correct input
	out << "Expected: " << *expected << ", Result: " << *it << endl;
}