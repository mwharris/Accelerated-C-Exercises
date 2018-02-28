#ifndef STR_2_H
#define STR_2_H

#include <cstring>
#include <iterator>

#include "Ptr.h"

class Str2
{
	/*
		Friend Functions
	*/
	friend std::istream& operator>> (std::istream& is, Str2& s);
	
public:
	typedef std::size_t size_type;
	typedef char* iterator;
	typedef const char* const_iterator;

	/*
		Constructors
	*/
	//Default
	Str2() : data(new Vec<char>) { data->push_back('\0'); }
	
	//Create n instances of c
	Str2(size_type n, char c) : data(new Vec<char>(n, c)) { data->push_back('\0'); }

	//Constructor: Initialize a string given an array of char
	Str2(const char* c) : data(new Vec<char>) {
		std::copy(c, c + std::strlen(c), std::back_inserter(*data));
		data->push_back('\0');
	}

	//Constructor: Initialize a string with the values given between two iterators
	template <class In>
	Str2(In begin, In end) : data(new Vec<char>) {
		std::copy(begin, end, std::back_inserter(*data));
		data->push_back('\0');
	}

	/*
		Operators
	*/
	//Index operator
	char& operator[] (size_type i) { return (*data)[i]; }
	const char& operator[] (size_type i) const { return (*data)[i]; }

	//Concatenate operator overload
	Str2& operator+= (const Str2& s)
	{
		//Make sure we are a unique instance
		data.make_unique();
		//Remove the trailing \0
		data->erase(data->end() - 1);
		//Simply copy the data from the input Str to this Str
		std::copy(s.data->begin(), s.data->end() - 1, std::back_inserter(*data));
		data->push_back('\0');
		return *this;
	}

	//Conversion to bool
	operator bool() const { 
		return !this->empty(); 
	}

	/*
		Utility Functions (defined in .cpp)
	*/
	void clear() { data->clear(); }
	void copy(char* dest, size_type amount, size_type pos = 0);
	const_iterator c_str() const { return data->begin(); }
	size_type size() { return data->size() - 1; }
	size_type size() const { return data->size() - 1; }
	iterator begin() { return data->begin(); }
	const_iterator begin() const { return data->begin(); }
	iterator end() { return data->end() - 1; }
	const_iterator end() const { return data->end() - 1; }
	bool empty() { return data->size() - 1 == 0; }
	bool empty() const { return data->size() - 1 == 0; }
	Str2 substr(size_type start, size_type length) const;

private:
	Ptr<Vec<char>> data;

};

/*
	Non-member Functions
*/
std::ostream& operator<< (std::ostream& os, const Str2& s);
std::ostream_iterator<char>& operator<< (std::ostream_iterator<char>& os, const Str2& s);
Str2 operator+ (const Str2& lhs, const Str2& rhs);
Str2 operator+ (const Str2& lhs, const char* rhs);
Str2 operator+ (const char* lhs, const Str2& rhs);
std::istream& getline(std::istream& os, Str2& s);
std::istream& read_until(std::istream& is, Str2& s, char stopChar);

/*
	Private Functions
*/
inline bool operator== (const Str2& lhs, const Str2& rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) == 0);
}

inline bool operator!= (const Str2& lhs, const Str2& rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) != 0);
}

inline bool operator< (const Str2& lhs, const Str2& rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) < 0);
}

inline bool operator<= (const Str2& lhs, const Str2& rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) <= 0);
}

inline bool operator> (const Str2& lhs, const Str2& rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) > 0);
}

inline bool operator>= (const Str2& lhs, const Str2& rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) >= 0);
}

#endif // !STR_2_H
