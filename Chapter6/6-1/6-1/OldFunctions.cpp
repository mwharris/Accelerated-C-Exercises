#include "stdafx.h"
#include <algorithm>

#include "OldFunctions.h"

using std::vector;
using std::string;
using std::max;

typedef string::size_type str_sz;

//Determine the longest string in vector
str_sz width_old(const vector<string> v)
{
	str_sz maxLength = 0;
	for (vector<string>::const_iterator iter = v.begin(); iter < v.end(); iter++)
	{
		maxLength = max(maxLength, iter->size());
	}
	return maxLength;
}

//Frame a given vector in a border
vector<string> frame_old(const vector<string>& words)
{
	vector<string> ret;

	//Find the max length string
	str_sz maxLen = width_old(words);
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
vector<string> hcat_old(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	//Get the longest word length in left
	str_sz maxLen = width_old(left) + 1;

	vector<string>::size_type i = 0;
	vector<string>::size_type j = 0;
	while (i < left.size() || j < right.size())
	{
		string s;

		//Start off with the left-side if there exists one
		if (i < left.size())
		{
			s = left[i++];
		}

		//Add padding
		s += string(maxLen - s.size(), ' ');

		//Now add the right side
		if (j < right.size())
		{
			s += right[j++];
		}

		ret.push_back(s);
	}

	return ret;
}