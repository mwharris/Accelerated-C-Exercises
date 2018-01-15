#include "stdafx.h"
#include <algorithm>

#include "StrOps.h"

using std::string;
using std::vector;
using std::transform;
using std::max;

//Return the lower case version of a string
string to_lower_case(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

//Split a string sentence into it's individual words
vector<string> split(const string& s)
{
	vector<string> ret;
	typedef vector<string>::size_type str_sz;

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

	return ret;
}

//Create a string from a vector<string>
string vec_to_str(const vector<string>& v)
{
	string ret;
	for (vector<string>::const_iterator it = v.begin(); it < v.end(); it++)
	{
		if (it != v.end() - 1)
		{
			ret += *it + " ";
		}
		else
		{
			ret += *it;
		}
	}
	return ret;
}

//Determine the longest string in vector
vector<string>::size_type width(const vector<string> v)
{
	vector<string>::size_type maxLength = 0;
	for (vector<string>::const_iterator iter = v.begin(); iter < v.end(); iter++)
	{
		maxLength = max(maxLength, iter->size());
	}
	return maxLength;
}

//Concatenate two vectors "horizontally"
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;
	typedef vector<string>::size_type str_sz;

	//Get the longest word length in left
	str_sz maxLen = width(left) + 1;

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

//Frame a given vector in a border
vector<string> frame(const vector<string>& words, bool alignLeft)
{
	typedef string::size_type str_sz;
	vector<string> ret;

	//Find the max length string
	str_sz maxLen = width(words);
	string topBottom = string(maxLen + 4, '*');

	//Create the top border
	ret.push_back(topBottom);

	//Create the in-between rows
	for (vector<string>::const_iterator iter = words.begin(); iter < words.end(); iter++)
	{
		string front = "* ";
		string back = " *";
		if (alignLeft)
		{
			ret.push_back(front + (*iter) + string(maxLen - iter->size(), ' ') + back);
		}
		else
		{
			ret.push_back(front + string(maxLen - iter->size(), ' ') + (*iter) + back);
		}
	}

	//Create the bottom border
	ret.push_back(topBottom);

	return ret;
}