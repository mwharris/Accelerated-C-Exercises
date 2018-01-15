#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::istream;
using std::cin;
using std::max;

string::size_type read_words(istream& in, vector<string>& words)
{
	words.clear();

	string::size_type maxLength = 0;
	string word;
	while (cin >> word)
	{
		maxLength = max(maxLength, word.size());
		words.push_back(word);
	}

	cin.clear();

	return maxLength;
}
