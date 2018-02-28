#include "stdafx.h"
#include <iostream>
#include <vector>

#include "Str2.h"

using std::vector;
using std::ostream;
using std::istream;
using std::ostream_iterator;

//Concatenate two Str2's and return a new one representing the result
Str2 operator+ (const Str2& lhs, const Str2& rhs)
{
	//Create a new Str2 to hold the concat result
	Str2 ret = lhs;
	//Call the += operator to combine the two
	ret += rhs;
	//Return the new string
	return ret;
}
Str2 operator+ (const Str2& lhs, const char* rhs)
{
	Str2 ret = lhs;
	ret += Str2(rhs, rhs + strlen(rhs));
	return ret;
}
Str2 operator+ (const char* lhs, const Str2& rhs)
{
	Str2 ret = Str2(lhs, lhs + strlen(lhs));
	ret += rhs;
	return ret;
}

//Input operator, read istream into Str2 object
istream& operator>> (istream& is, Str2& s)
{
	//Skip over leading whitespace
	char c;
	while (is.get(c) && isspace(c))	{}
	//Make sure we don't consume non-spaces
	is.unget();
	//Read all chars into s until we hit a space
	return read_until(is, s, ' ');
}

//Output operator, read Str2 object into ostream
ostream& operator<< (ostream& os, const Str2& s)
{
	//Print every char that isn't a null-terminator
	const char* curr = s.c_str();
	while (*curr != '\0')
	{
		os << *curr++;
	}
	return os;
}

//Output operator using ostream_iterator
ostream_iterator<char>& operator<< (ostream_iterator<char>& os, const Str2& s)
{
	copy(s.begin(), s.end(), os);
	return os;
}

//Copies the amount of items from data into dest
void Str2::copy(char* dest, size_type amount, size_type pos)
{
	std::copy(data->begin() + pos, data->begin() + pos + amount, dest);
}

//Read a line from the ostream into the Str2
istream& getline(istream& is, Str2& s)
{
	//First remove all data from the Str2
	s.clear();
	//Next read characters from
	return read_until(is, s, '\n');
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

//Helper function to read an ostream until a char is found
istream& read_until(istream& is, Str2& s, char stopChar)
{
	vector<char> vchars;
	char c;
	//Read all chars into a vector
	while (is.get(c) && !char_match(c, stopChar))
	{
		vchars.push_back(c);
	}
	//Update the Str2 with the chars from the vector
	s = Str2(vchars.begin(), vchars.end());
	//If we didn't reach end-of-file
	if (is)
	{
		is.unget();
	}
	return is;
}

//Return a substring of the Str2 based on the indexes [start, end)
Str2 Str2::substr(size_type start, size_type length) const
{
	iterator begin = this->data->begin() + start;
	iterator end = this->data->begin() + start + length;
	return Str2(begin, end);
}