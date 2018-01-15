#include "stdafx.h"
#include <iostream>
#include <vector>

#include "Str2.h"

using std::vector;
using std::ostream;
using std::istream;
using std::ostream_iterator;

//Create n amount of c chars in our array
void Str2::create(size_type n, const char c)
{
	//Allocation memory for n chars
	chars = alloc.allocate(n+1);
	//We have our length now too
	length = n;
	//Fill our newly allocated memory with copies of passed-in char
	std::uninitialized_fill(chars, chars + length, c);
	//Add a null-terminator to the end of the char
	alloc.construct(chars + length, '\0');
}

//Destroy all constructed objects and allocated memory
void Str2::uncreate()
{
	//Only destroy if we allocated data
	if (chars) 
	{
		//Loop backwards and destroy each constructed object
		iterator temp = chars + length;
		while (temp != chars)
		{
			alloc.destroy(--temp);
		}
		//Deallocate the memory
		alloc.deallocate(chars, length + 1);
	}
	//Reset our pointer and length
	chars = 0;
	length = 0;
}

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

//Clear the char array of values
void Str2::clear()
{
	//Destroy all values and memory
	uncreate();
	//Create a new, blank set of data
	create(0, '\0');
}

//Push a new char onto the end of the string
void Str2::push_back(const char c)
{
	//Grow the allocated memory by 1
	grow(1);
	//Add the new char
	alloc.construct(chars + length, c);
	length++;
	//Add the null-terminator
	alloc.construct(chars + length, '\0');
}

//Copies the amount of items from data into dest
void Str2::copy(char* dest, size_type amount, size_type pos)
{
	std::copy(chars + pos, chars + pos + amount, dest);
}

void Str2::grow(size_type amount)
{
	//Allocate memory to fit the new length
	size_type oldLength = length;
	size_type newLength = length + amount;
	char* temp = alloc.allocate(newLength + 1);
	//Copy values from the current memory to the new memory
	std::uninitialized_copy(chars, chars + length, temp);
	//Destroy the old memory
	uncreate();
	//Update pointers
	chars = temp;
	length = oldLength;
}

Str2& Str2::concat(size_type size, const char* begin, const char* end)
{
	//Grow the memory to fit the new size
	grow(size);
	//Move values from this AND rhs to the new block of memory
	std::uninitialized_copy(begin, end, chars + length);
	//Add a null-terminator
	alloc.construct(chars + length + size, '\0');
	//Update pointers and length
	length += size;
	return *this;
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
Str2 Str2::substr(size_type index, size_type length) const
{
	iterator begin = this->chars + index;
	iterator end = this->chars + index + length;
	return Str2(begin, end);
}