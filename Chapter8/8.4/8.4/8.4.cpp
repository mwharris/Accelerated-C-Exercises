#include "stdafx.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::string;
using std::find_if;
using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;

bool not_space(char c)
{
	return !isspace(c);
}

bool space(char c)
{
	return isspace(c);
}

template <class Out>
void split(const string& s, Out os)
{
	string::const_iterator i = s.begin();

	while (i != s.end())
	{
		//Find the start of a word
		i = find_if(i, s.end(), not_space);
		//Find the end of this word
		string::const_iterator j = find_if(i, s.end(), space);
		if (i != s.end())
		{
			//Add it to the passed-in output stream
			*os++ = string(i, j);
		}
		//Update i
		i = j;
	}
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		split(s, ostream_iterator<string>(cout, "\n"));
	}
    return 0;
}

