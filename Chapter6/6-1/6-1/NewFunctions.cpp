#include "stdafx.h"
#include <algorithm>

#include "NewFunctions.h"

using std::vector;
using std::string;
using std::max;

typedef string::size_type str_sz;

//Determine the longest string in vector
str_sz width_new(const vector<string> v)
{
	str_sz maxLength = 0;
	for (vector<string>::const_iterator iter = v.begin(); iter < v.end(); iter++)
	{
		maxLength = max(maxLength, iter->size());
	}
	return maxLength;
}

//Frame a given vector in a border
vector<string> frame_new(const vector<string>& words)
{
	vector<string> ret;

	//Find the max length string
	str_sz maxLen = width_new(words);
	string topBottom = string(maxLen + 4, '*');

	//Create the top border
	ret.push_back(topBottom);

	//Create the in-between rows
	for (vector<string>::const_iterator iter = words.begin(); iter < words.end(); iter++)
	{
		string front = "* ";
		string back = " *";
		ret.push_back(front + (*iter) + string(maxLen - iter->size(), ' ') + back);
	}

	//Create the bottom border
	ret.push_back(topBottom);

	return ret;
}

//Concatenate two vectors "horizontally"
vector<string> hcat_new(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	//Get the longest word length in left
	str_sz maxLen = width_new(left) + 1;

	vector<string>::const_iterator l = left.begin();
	vector<string>::const_iterator r = right.begin();
	vector<string>::size_type i = 0;
	vector<string>::size_type j = 0;
	while (l < left.end() || r < right.end())
	{
		string s;

		//Start off with the left-side if there exists one
		if (l < left.end())
		{
			s = *l;
			l++;
		}

		//Add padding
		s += string(maxLen - s.size(), ' ');

		//Now add the right side
		if (r < right.end())
		{
			s += *r;
			r++;
		}

		ret.push_back(s);
	}

	return ret;
}