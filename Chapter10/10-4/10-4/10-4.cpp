#include "stdafx.h"
#include <list>
#include <string>
#include <iostream>
#include <vector>

#include "String_List.h"
#include "Str_Node.h"
#include "Iterator.h"
#include "ReverseIterator.h"

using std::list;
using std::string;
using std::cout;
using std::endl;
using std::vector;

void split(const string& s, String_List& ret)
{
	typedef list<string>::size_type str_sz;

	str_sz i = 0;
	while (i < s.size())
	{
		//Move i until we hit the start of a word
		while (i < s.size() && isspace(s[i]))
		{
			i++;
		}
		//Create a second index to find the next whitespace
		str_sz j = i;
		while (j < s.size() && !isspace(s[j]))
		{
			j++;
		}
		//If our two indices are valid
		if (i != j)
		{
			//Add this word to our return vector
			ret.push_back(s.substr(i, j - i));
			//Advance i to start at this index next iteration
			i = j;
		}
	}
}

int main()
{
	string split_me = "Why am I so bad at fantasy football?";

	String_List words;
	split(split_me, words);

	for (Iterator it = words.begin(); it != words.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}