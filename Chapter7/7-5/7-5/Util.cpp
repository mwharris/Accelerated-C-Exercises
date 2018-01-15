#include "stdafx.h"
#include <cstdlib>
#include "Util.h"

using std::vector;
using std::string;

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

bool is_indicator(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

//Return a random integer between [0 and n)
int nrand(int n)
{
	int ret;

	//Separate RAND_MAX into an n-amount of buckets
	const int bucket_size = RAND_MAX / n;

	//Randomly choose numbers between 0 and RAND_MAX.
	//Divide the random value by the amount of buckets we have in order to determine which bucket it lands.
	//Stop once we get a value that lands in our range of buckets (0 - n)
	do ret = rand() / bucket_size;
	while (ret >= n);

	return ret;
}