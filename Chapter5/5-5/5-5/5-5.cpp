#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
using std::max;
using std::cout;
using std::cin;
using std::endl;

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

//Frame a given vector in a border
vector<string> frame(const vector<string>& words, bool alignLeft, bool alignRight, bool alignCenter)
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
		else if (alignRight)
		{
			ret.push_back(front + string(maxLen - iter->size(), ' ') + (*iter) + back);
		}
		else
		{
			//Half the padding that we use for left/right alignments
			str_sz padding = (maxLen - iter->size()) / 2;
			//If there's a remainder in the division
			if ((maxLen - iter->size()) % 2 > 0)
			{
				//Add 1 to the back padding
				ret.push_back(front + string(padding, ' ') + (*iter) + string(padding + 1, ' ') + back);
			}
			//Else just pad it like normal
			else
			{
				ret.push_back(front + string(padding, ' ') + (*iter) + string(padding, ' ') + back);
			}
		}
	}

	//Create the bottom border
	ret.push_back(topBottom);

	return ret;
}

int main()
{
	vector<string> pic;

	//Fill out the test picture
	pic.push_back("I really want to be a smart game dev.");
	pic.push_back("Hopefully I can get this job.");
	pic.push_back("And hopefully this test is not too hard.");
	pic.push_back("But I'll try my best either way.");
	pic.push_back("Because that's what would make my dad proud.");

	//Center it
	vector<string> centered = frame(pic, false, false, true);

	//Print it
	for (vector<string>::const_iterator it = centered.begin(); it < centered.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}