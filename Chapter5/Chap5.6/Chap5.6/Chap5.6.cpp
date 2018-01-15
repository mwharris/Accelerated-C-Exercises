#include "stdafx.h"
#include <cctype>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::max;

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

//Determine the longest string in vector
str_sz width(const vector<string> v)
{
	str_sz maxLength = 0;
	for (vector<string>::const_iterator iter = v.begin(); iter < v.end(); iter++)
	{
		maxLength = max(maxLength, iter->size());
	}
	return maxLength;
}

//Frame a given vector in a border
vector<string> frame(const vector<string>& words)
{
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
		ret.push_back(front + (*iter) + string(maxLen - iter->size(), ' ') + back);
	}

	//Create the bottom border
	ret.push_back(topBottom);

	return ret;
}

//Concatenate two vectors "vertically"
vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
	vector<string> ret = top;
	ret.insert(ret.end(), bottom.begin(), bottom.end());
	return ret;
}

//Concatenate two vectors "horizontally"
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

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
		framedWords = frame(words);
		print_vector("Framed: ", framedWords);

		//Now vertically concatenate the two and print
		vcatFrame = vcat(words, framedWords);
		print_vector("Vertical Concatenation: ", vcatFrame);

		//Lastly, horizontally concatenate the two and print
		hcatFrame = hcat(words, framedWords);
		print_vector("Horizontal Concatenation: ", hcatFrame);
	}

    return 0;
}

