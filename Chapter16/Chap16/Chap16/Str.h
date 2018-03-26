#ifndef STR_H
#define STR_H

#include "Ptr.h"

class Str {
	//Input operator overload
	friend std::istream& operator>> (std::istream& is, Str& str);

public:
	typedef Vec<char>::size_type size_type;

	//Default empty constructor
	Str() : data(new Vec<char>) 
	{
		data->push_back('\0');
	}
	
	//Constructor: Initialize a string of n occurrences of c 
	Str(size_type n, char c) : data(new Vec<char>(n, c)) 
	{
		data->push_back('\0');
	}

	//Constructor: Initialize a string given an array of char
	Str(const char* c) : data(new Vec<char>) {
		std::copy(c, c + std::strlen(c), std::back_inserter(*data));
		data->push_back('\0');
	}
	
	//Constructor: Initialize a string with the values given between two iterators
	template <class In>
	Str(In begin, In end) : data(new Vec<char>) {
		std::copy(begin, end, std::back_inserter(*data));
		data->push_back('\0');
	}

	//Index operator overloads
	char& operator[] (size_type n) { 
		//Make unique since this function is not const and the value can be updated
		data.make_unique();
		return (*data)[n]; 
	}
	const char& operator[] (size_type n) const { return (*data)[n]; }

	//Concatenate operator overload
	Str& operator+= (const Str& s)
	{
		//Make sure we are a unique instance
		data.make_unique();
		//Remove the null-terminator
		data->erase(data->end() - 1);
		//Simply copy the data from the input Str to this Str
		std::copy(s.data->begin(), s.data->end(), std::back_inserter(*data));
		return *this;
	}

	//Utility functions
	//Note: this should be const so const Str's can call this fine
	size_type size() const { 
		if (data->size() == 0 || data->size() == 1) 
		{
			return 0;
		}
		else 
		{
			return data->size() - 1;
		}
	}
	
	void clear() {
		//Make sure we are a unique instance
		data.make_unique();
		//Then clear the Vec<char>
		data->clear(); 
	};

private:
	Ptr<Vec<char>> data;

};

std::istream& operator>> (std::istream& is, Str& str);
std::ostream& operator<< (std::ostream& os, const Str& s);
bool operator< (const Str& lhs, const Str& rhs);
Str operator+ (const Str& left, const Str& right);
std::istream& getline(std::istream& os, Str& s);
std::istream& read_until(std::istream& is, Str& s, char stopChar);

#endif // !STR_H
