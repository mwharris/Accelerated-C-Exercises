#ifndef STR_H
#define STR_H

#include <iterator>
#include "Vec.h"

class Str {
	//Input operator overload
	friend std::istream& operator>> (std::istream& is, Str& str);

public:
	typedef Vec<char>::size_type size_type;

	//Default empty constructor
	Str() {}
	
	//Initialize a string of n occurrences of c 
	Str(size_type n, char c) : data(n, c) {}

	//Initialize a string given an array of char
	Str(const char* c) {
		std::copy(c, c + std::strlen(c), std::back_inserter(data));
	}
	
	//Initialize a string with the values given between two iterators
	template <class In>
	Str(In begin, In end) {
		data = Vec<char>(begin, end);
	}

	//Index operator overloads
	char& operator[] (size_type n) { return data[n]; }
	const char& operator[] (size_type n) const { return data[n]; }

	//Concatenate operator overload
	Str& operator+= (const Str& s)
	{
		//Simply copy the data from the input Str to this Str
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

	//Utility functions
	//Note: this should be const so const Str's can call this fine
	size_type size() const { return data.size(); }

private:
	Vec<char> data;

};

//Input operator overload
std::istream& operator>> (std::istream& is, Str& str) {
	//Clear the Str's data
	str.data.clear();
	//Skip over any whitespace in the istream
	char c;
	while (is.get(c) && isspace(c)) {}
	//If there are characters left to read
	if (is) {
		//Keep reading characters until we reach a space OR end-of-file
		do str.data.push_back(c);
		while (is.get(c) && !isspace(c));
		//If we ended because we hit a space
		if (is) {
			//Undo the get() on the space
			is.unget();
		}
	}
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

#endif // !STR_H
