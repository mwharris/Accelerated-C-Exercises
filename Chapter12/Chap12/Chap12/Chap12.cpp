#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <iterator>

#include "Str.h"
#include "Str2.h"
#include "Vec.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ostream_iterator;

int main()
{
	Vec<Str> v;
	Str s;
	cout << "Type some strings followed by end-of-file: ";
	while (cin >> s)
	{
		v.push_back(s);
	}
	if (cin) 
	{
		cout << endl << "No failure state" << endl;
	}
	else 
	{
		cout << endl << "Failure state" << endl;
	}

	return 0;
}