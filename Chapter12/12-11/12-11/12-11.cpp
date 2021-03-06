#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Str2.h"
#include "Vec.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::max;

//Simply print out a vector to the screen along with a string title
void print_vector(string title, const Vec<Str2>& v)
{
	cout << title << endl;
	for (Vec<Str2>::const_iterator iter = v.begin(); iter < v.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << endl;
}

//Split a string sentence into it's individual words
Vec<Str2> split(const Str2& s)
{
	Vec<Str2> ret;

	size_t i = 0;
	while (i < s.size())
	{
		//Move i until we hit the start of a word
		while (i < s.size() && isspace(s[i]))
		{
			i++;
		}
		//Create a second index to find the next whitespace
		size_t j = i;
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
Str2::size_type width(const Vec<Str2> v)
{
	Vec<Str2>::size_type maxLength = 0;
	for (Vec<Str2>::const_iterator iter = v.begin(); iter < v.end(); iter++)
	{
		maxLength = max(maxLength, iter->size());
	}
	return maxLength;
}

//Frame a given vector in a border
Vec<Str2> frame(const Vec<Str2>& words)
{
	Vec<Str2> ret;

	//Find the max length string
	Vec<Str2>::size_type maxLen = width(words);
	Str2 topBottom = Str2(maxLen + 4, '*');

	//Create the top border
	ret.push_back(topBottom);

	//Create the in-between rows
	for (Vec<Str2>::const_iterator iter = words.begin(); iter < words.end(); iter++)
	{
		Str2 front = "* ";
		Str2 back = " *";
		ret.push_back(front + (*iter) + Str2(maxLen - iter->size(), ' ') + back);
	}

	//Create the bottom border
	ret.push_back(topBottom);

	return ret;
}

//Concatenate two vectors "vertically"
Vec<Str2> vcat(const Vec<Str2>& top, const Vec<Str2>& bottom)
{
	Vec<Str2> ret = top;
	ret.insert(ret.end(), bottom.begin(), bottom.end());
	return ret;
}

//Concatenate two vectors "horizontally"
Vec<Str2> hcat(const Vec<Str2>& left, const Vec<Str2>& right)
{
	Vec<Str2> ret;

	//Get the longest word length in left
	Str2::size_type maxLen = width(left) + 1;

	Vec<Str2>::size_type i = 0;
	Vec<Str2>::size_type j = 0;
	while (i < left.size() || j < right.size())
	{
		Str2 s;

		//Start off with the left-side if there exists one
		if (i < left.size())
		{
			s = left[i++];
		}

		//Add padding
		s += Str2(maxLen - s.size(), ' ');

		//Now add the right side
		if (j < right.size())
		{
			s += right[j++];
		}

		ret.push_back(s);
	}

	return ret;
}

int main()
{
	Str2 s;
	cout << "Enter a sentence: ";
	
	if (getline(cin, s))
	{
		Vec<Str2> words;
		Vec<Str2> framedWords;
		Vec<Str2> vcatFrame;
		Vec<Str2> hcatFrame;

		//Read in and split a sentence into individual words and print
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

