#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;
using std::getline;

void read_words(vector<string>& words)
{
	cout << "Please enter words to process for palindromes: " << endl;

	string s;
	while (getline(cin, s))
	{
		words.push_back(s);
	}
}

//Check if a string is a palindrome
bool is_palindrome(string s)
{
	if (s.size() > 0)
	{
		string::size_type front = 0;
		string::size_type back = s.size() - 1;

		//Remove spaces

		//Loop through all characters
		while (front < back)
		{
			//Jump over any spaces
			if (isspace(s[front]))
			{
				front++;
			}
			if (isspace(s[back]))
			{
				back--;
			}
			//Make sure the opposite characters are the same
			if (s[front] != s[back])
			{
				return false;
			}
			//Move the indexes closer together
			front++;
			back--;
		}
		return true;
	}
	return false;
}

string::size_type find_palindromes(vector<string>& words, vector<string>& pals)
{
	string::size_type max_length = 0;
	for (vector<string>::const_iterator it = words.begin(); it < words.end(); it++)
	{
		if (is_palindrome(*it))
		{
			pals.push_back(*it);
			max_length = max(max_length, it->size());
		}
	}
	return max_length;
}

int main()
{
	vector<string> words;
	vector<string> palindromes;

	read_words(words);

	string::size_type max_size = find_palindromes(words, palindromes);

	cout << "PALINDROMES: " << endl;
	for (vector<string>::const_iterator it = palindromes.begin(); it < palindromes.end(); it++)
	{
		cout << *it << endl;
	}

    return 0;
}