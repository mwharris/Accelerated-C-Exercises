#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::copy;

char* duplicate_chars(const char* p)
{
	//Get the full length that p points to, add 1 for null character
	size_t length = strlen(p) + 1;
	//Allocate enough space for the entirety of the character array
	char* result = new char[length];
	//Copy into newly allocated space and return pointer to the first element
	copy(p, p + length, result);
	return result;
}

int main()
{
	char* c = duplicate_chars("fuck you lookin' at nigga");
	cout << *c << endl;
    return 0;
}