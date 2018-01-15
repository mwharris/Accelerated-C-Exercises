#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

//Read in several words to process for upper/lower case
void read_words(vector<string>& words)
{
	cout << "Please write words to process: " << endl;

	string s;
	while (cin >> s)
	{
		words.push_back(s);
	}
}

//Check if a word contains any uppercase letters
bool check_contains_uppercase(string word)
{
	if (word.size() > 0)
	{
		char c;
		for (string::const_iterator it = word.begin(); it < word.end(); it++)
		{
			if (isupper(*it))
			{
				return true;
			}
		}
	}
	return false;
}

//Seperate uppercase and lowercase words
void separate_cases(vector<string>& words, vector<string>& uppercase, vector<string>& lowercase)
{
	for (vector<string>::const_iterator it = words.begin(); it < words.end(); it++)
	{
		if (check_contains_uppercase(*it))
		{
			uppercase.push_back(*it);
		}
		else 
		{
			lowercase.push_back(*it);
		}
	}
}

void print_vec(vector<string>& v)
{
	for (vector<string>::const_iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << endl;
	}
}

int main()
{
	vector<string> words;
	vector<string> uppercase;
	vector<string> lowercase;
    
	read_words(words);

	separate_cases(words, uppercase, lowercase);

	cout << string(30, '-') << endl;
	cout << "UPPERCASE WORDS: " << endl; 
	cout << string(30, '-') << endl;

	print_vec(uppercase);

	cout << string(30, '-') << endl;
	cout << "LOWERCASE WORDS: " << endl;
	cout << string(30, '-') << endl;

	print_vec(lowercase);

	return 0;
}

