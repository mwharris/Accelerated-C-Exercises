#include "stdafx.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::accumulate;
using std::copy;
using std::ostringstream;
using std::ostream_iterator;

void read_elements(vector<string>& elements)
{
	cout << "Please enter a list of string to concatenate: " << endl;
	
	string curr;
	while (cin >> curr)
	{
		elements.push_back(curr);
	}

	cin.clear();
}

string concatenate_v1(const vector<string>& elems)
{
	return accumulate(elems.begin(), elems.end(), string(""));
}

int main()
{
	string test = "Fuck ";
	vector<string> elements(10, test);

	string result = concatenate_v1(elements);

    return 0;
}

