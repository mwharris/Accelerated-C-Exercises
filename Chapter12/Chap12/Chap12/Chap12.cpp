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
	string test = "fuck you asshole";
	Vec<char> v1(test.begin(), test.end());

	Str2 test2 = "finish this book";
	Vec<char> v2(test2.begin(), test2.end());

	cout << v1 << endl;
	cout << v2 << endl;

	return 0;
}