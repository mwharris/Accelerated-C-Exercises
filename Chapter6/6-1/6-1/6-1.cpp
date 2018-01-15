#include "stdafx.h"
#include <iostream>

#include "NewFunctions.h"
#include "OldFunctions.h"

using std::vector;
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;

typedef string::size_type str_sz;

//Split a string sentence into it's individual words
vector<string> split(const string& s)
{
	vector<string> ret;

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

//Simply print out a vector to the screen along with a string title
void print_vector(string title, const vector<string>& v)
{
	cout << title << endl;
	for (vector<string>::const_iterator iter = v.begin(); iter < v.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << endl;
}

int main()
{
	string s;
	cout << "Please enter a sentence or end-of-file: ";
	while (getline(cin, s))
	{
		vector<string> words;
		vector<string> framedWords;
		vector<string> vcatFrame;
		vector<string> hcatFrame;

		//Read and split our sentence up into individual words and print
		words = split(s);
		cout << endl;
		print_vector("Split sentence: ", words);

		//Now frame these words and print
		framedWords = frame_new(words);
		print_vector("Framed: ", framedWords);

		//Lastly, horizontally concatenate the two and print
		hcatFrame = hcat_new(words, framedWords);
		print_vector("Horizontal Concatenation: ", hcatFrame);
	}

	return 0;
}

