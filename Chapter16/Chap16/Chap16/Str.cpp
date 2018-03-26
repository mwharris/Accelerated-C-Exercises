#include "stdafx.h"
#include <iostream>

#include "Str.h"

//Input operator overload
std::istream& operator>> (std::istream& is, Str& str) {
	//Clear the Str's data
	str.data->clear();
	//Skip over any whitespace in the istream
	char c;
	while (is.get(c) && isspace(c)) {}
	//If there are characters left to read
	if (is) {
		//Keep reading characters until we reach a space OR end-of-file
		do str.data->push_back(c);
		while (is.get(c) && !isspace(c));
		//If we ended because we hit a space
		if (is) {
			//Undo the get() on the space
			is.unget();
		}
	}
	//Don't forget to add the null-terminator
	str.data->push_back('\0');
	return is;
}

//Output operator overload
std::ostream& operator<< (std::ostream& os, const Str& s) {
	//Read every character of the Str into the output stream
	for (Str::size_type i = 0; i != s.size(); i++) {
		os << s[i];
	}
	return os;
}

//Concatenation overload
Str operator+ (const Str& left, const Str& right)
{
	//Create a new Str
	Str ret = left;
	//Use the += copy operator to concatenate the two
	ret += right;
	return ret;
}

//Helper function to check if two chars are equal
bool char_match(char a, char b)
{
	if (a == b)
	{
		return true;
	}
	return false;
}

//Read from an input stream into a given Str until a stop character is reached
std::istream& read_until(std::istream& is, Str& s, char stopChar)
{
	Vec<char> vchars;
	char c;
	//Read all chars into a vector
	while (is.get(c) && !char_match(c, stopChar))
	{
		vchars.push_back(c);
	}
	//Update the Str2 with the chars from the vector
	s = Str(vchars.begin(), vchars.end());
	return is;
}

//Read a line from the input stream into a given Str
std::istream& getline(std::istream& is, Str& s)
{
	//Clear the existing data
	s.clear();
	//Then read in new data
	return read_until(is, s, '\n');
}

//Operator overload for comparing two Strs
bool operator< (const Str& lhs, const Str& rhs)
{
	for (size_t i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] != rhs[i])
		{
			return lhs[i] < rhs[i];
		}
	}
	return false;
}