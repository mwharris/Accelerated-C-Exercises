#include "stdafx.h"
#include <string>
#include <iostream>

#include "Ls.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
	Ls<string> l;
	l.push_back("one");
	l.push_back("two");
	l.push_back("three");
	l.push_back("four");
	l.push_back("five");
	l.push_back("six");
	l.push_back("seven");
	l.push_back("eight");
	l.push_back("nine");
	l.push_back("ten");
	cout << "l size is: " << l.size() << endl;
	cout << "l max size is: " << l.max_size() << endl;

	l.erase(l.begin(), l.end());

	l.~Ls();

    return 0;
}

