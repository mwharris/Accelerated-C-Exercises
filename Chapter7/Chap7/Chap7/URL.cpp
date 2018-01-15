#include "stdafx.h"
#include "URL.h"
#include <algorithm>

using std::string;
using std::vector;
using std::search;

typedef string::const_iterator iter;

bool not_url_char(char c)
{
	//Characters that don't belong in a URL
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	//If the character is NOT alpha-numeric or it IS contained in the check string
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_beg(string::const_iterator begin, string::const_iterator end)
{
	static const string sep = "://";

	iter i = begin;

	//Continuosly search for separators between the two iterators, setting i at the same time.
	while ((i = search(i, end, sep.begin(), sep.end())) != end)
	{
		//Make sure the separator is neither at the beginning nor the end
		if (i != begin && (i + sep.size()) != end)
		{
			//Iterate backwards from the separator to get the protocol name
			iter url_start = i;
			while (url_start != begin && isalpha(url_start[-1]))
			{
				url_start--;
			}

			//Make sure we found a protocol name AND there is a valid character after the separator
			if (url_start != i && !not_url_char(i[sep.size()]))
			{
				//Return the pointer to the start of our URL
				return url_start;
			}
		}

		//Jump past this separator and keep searching
		i += sep.size();
	}

	//Simply return the end iterator if we found no valid URL
	return end;
}

//Find any non-URL characters between the two iterators, return that location
string::const_iterator url_end(string::const_iterator begin, string::const_iterator end)
{
	return find_if(begin, end, not_url_char);
}

vector<string> find_urls(const string& s)
{
	vector<string> ret;
	iter begin = s.begin();
	iter end = s.end();

	while (begin != end)
	{
		//Find the beginning of a URL between the two iterators
		begin = url_beg(begin, end);

		//url_beg returns the last element if nothing was found
		if (begin != end)
		{
			//Get the rest of the URL
			iter after = url_end(begin, end);

			//Create a string from the URL indices we found
			ret.push_back(string(begin, after));

			//Advance the start iterator to after the URL we found
			begin = after;
		}
	}

	return ret;
}
