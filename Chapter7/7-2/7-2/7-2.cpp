#include "stdafx.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>

using std::map;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::getline;

//Translate our map of (string, counter) -> (counter, strings)
void create_occurrence_map(const map<string, int>& counters, map<int, vector<string>>& occurrence_map)
{
	for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); it++)
	{
		occurrence_map[it->second].push_back(it->first);
	}
}

int main()
{
	string s;
	map<string, int> counters;
	map<int, vector<string>> occurrence_map;

	//Read in words one at a time, add to our map, and increment the int counter at that key
	while (cin >> s)
	{
		++counters[s];
	}

	//Translate our map into another grouped by occurrence counters
	create_occurrence_map(counters, occurrence_map);

	//Print all words grouped by occurrence rate
	cout << string(20, '*') << endl;
	for (map<int, vector<string>>::const_iterator it = occurrence_map.begin(); it != occurrence_map.end(); it++)
	{
		vector<string> curr = it->second;
		
		//If this vector has strings to display
		if (curr.size() > 0)
		{
			//Print the first string out
			cout << it->first << ": " << curr[0];
			//If there are anymore, print with leading comma
			vector<string>::const_iterator iter = curr.begin() + 1;
			while(iter != curr.end())
			{
				cout << ", " << *iter;
				iter++;
			}
			cout << endl;
		}
	}

    return 0;
}