#include "stdafx.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "URL.h"

using std::map;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::getline;

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
			//Add this word to our return vector if it doesn't already exist
			string sub = s.substr(i, j - i);
			if (find(ret.begin(), ret.end(), sub) == ret.end())
			{
				ret.push_back(s.substr(i, j - i));
			}
			//Advance i to start at this index next iteration
			i = j;
		}
	}

	return ret;
}

//Read input lines, split into words, and keep track of all lines those words appear
map<string, vector<int>> xref(istream& in, vector<string> find_words(const string&) = split)
{
	map<string, vector<int> > ret;
	int line_number = 0;
	string line;

	cout << "Enter lines of words followed by Enter: " << endl;

	//Read a line
	while (getline(in, line))
	{
		line_number++;

		//Check the line for URLs
		vector<string> urls = find_urls(line);

		//Process all words
		for (vector<string>::const_iterator it = urls.begin(); it < urls.end(); it++)
		{
			//Add the current line number to this word's vector
			ret[*it].push_back(line_number);
		}
	}

	//Clear the input buffer of errors
	in.clear();

	return ret;
}

int main()
{
	//Read line input and create cross-reference table of words
	map<string, vector<int>> cross_ref = xref(cin);

	//Print the results
	for (map<string, vector<int>>::const_iterator it = cross_ref.begin(); it != cross_ref.end(); it++)
	{
		cout << it->first << " occurs on line";
		if (it->second.size() > 1)
		{
			cout << "s: ";
		}
		else
		{
			cout << ": ";
		}

		//Print the first word immediately and line number iterator
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it;
		line_it++;

		//Print the rest of the words comma separated
		while (line_it != it->second.end())
		{
			cout << ", " << *line_it;
			line_it++;
		}
		cout << endl;
	}

    return 0;
}