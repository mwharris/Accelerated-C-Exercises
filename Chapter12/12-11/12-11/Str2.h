#ifndef STR_2_H
#define STR_2_H

#include <memory>
#include <cstring>
#include <iterator>

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
	Str2() 
	{ 
		create(0, '\0');
	}
	//Create n instances of c
	Str2(size_type n, const char c)
	{
		create(n, c);
	}
	//Create a Str2 using the elements between two iterators
	template <class In>
	Str2(In start, In end)
	{
		create(start, end);
	}
	//Destructor
	~Str2()
	{
		uncreate();
	}

	//Conversion: create a Str2 using an array of char
	Str2(const char* c)
	{
		create(c, c + strlen(c));
	}

	//Copy Constructor: create a new Str2 with passed-in Str2 values
	Str2(const Str2& s)
	{
		create(s.begin(), s.end());
	}

	/*
		Operators
	*/
	//Assignment
	Str2& operator= (const Str2& rhs)
	{
		if (&rhs != this)
		{
			//First destroy the current values
			uncreate();
			//Then re-create using rhs values
			create(rhs.begin(), rhs.end());
		}
		return *this;
	}

	//Index operator
	char& operator[] (size_type i) { return chars[i]; }
	const char& operator[] (size_type i) const { return chars[i]; }

	//Concatenation + assignment
	Str2& operator+= (const char* c) 
	{
		return concat(strlen(c), c, c + strlen(c));
	}
	Str2& operator+= (const Str2& rhs)
	{
		return concat(rhs.size(), rhs.c_str(), rhs.c_str() + rhs.size());
	}

	//Conversion to bool
	operator bool() const { 
		return !this->empty(); 
	}

	/*
		Utility Functions (defined in .cpp)
	*/
	void clear();
	void push_back(const char c);
	void copy(char* dest, size_type amount, size_type pos = 0);
	const_iterator c_str() const { return chars; }
	const_iterator data() const { return chars; }
	size_type size() { return length; }
	size_type size() const { return length; }
	iterator begin() { return chars; }
	const_iterator begin() const { return chars; }
	iterator end() { return chars + length; }
	const_iterator end() const { return chars + length; }
	bool empty() { return length == 0; }
	bool empty() const { return length == 0; }
	Str2 substr(size_type start, size_type length) const;

private:
	//Pointer to the front of our char array
	iterator chars;
	//The total amount of chars in the array
	size_type length;
	//Allocator for our char array
	std::allocator<char> alloc;

	//Helper functions for managing memory
	void create(size_type n, const char c);
	template <class In> void create(In start, In end);
	void uncreate();
	void grow(size_type amount);
	Str2& concat(size_type size, const char* begin, const char* end);

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
//Create a string using two iterators pointing to chars
template <class In>
void Str2::create(In start, In end)
{
	//Determine the length using pointer difference
	length = end - start;
	//Allocation memory for the full length
	chars = alloc.allocate(length + 1);
	//Copy values between the pointers to our newly allocated data
	std::uninitialized_copy(start, end, chars);
	//Add our null-terminator
	alloc.construct(chars + length, '\0');
}

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
