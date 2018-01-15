#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "Read.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::sort;

//Counts the number of occurences of a word starting at the index.
//Expected that the words array is sorted alphabetically
int count_occurences(string word, vector<string>::size_type startIndex, const vector<string>& words)
{
	//Make sure our inputs are valid
	if (words.size() == 0 || startIndex >= words.size())
	{
		return 0;
	}

	//Count occurences of a word starting with the specified index
	int count = 0;
	for (vector<string>::size_type i = startIndex; i < words.size(); i++)
	{
		if (words[i] == word)
		{
			count++;
		}
		else
		{
			break;
		}
	}

	return count;
}

int main()
{
	vector<string> words;

	//Read the user's words into the vector
	cout << "Please enter words followed by end-of-file: " << endl;
	string::size_type maxLength = read_words(cin, words);

	//Sort the vector alphabetically
	sort(words.begin(), words.end());

	//Display the count
	cout << string(30,  '-') << endl << "You entered " << words.size() << " words: " << endl;

	vector<string>::size_type i = 0;
	while(i < words.size())
	{
		int count = count_occurences(words[i], i, words);
		string::size_type padding = maxLength + 1 - words[i].size();
		cout << words[i] << string(padding, ' ') << count << endl;
		i += count;
	}

    return 0;
}

