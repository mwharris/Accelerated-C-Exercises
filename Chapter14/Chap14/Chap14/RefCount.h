#ifndef REF_COUNT_H
#define REF_COUNT_H

class RefCount
{
public:
	//Default constructor
	RefCount() : refptr(new std::size_t(1)) {}
	//Constructor: default to a certain count
	RefCount(std::size_t count) : refptr(new std::size_t(count)) {}

	//Destructor
	~RefCount()
	{
		//Only destroy this if it's the last one pointing to the count
		if (*refptr == 0)
		{
			delete refptr;
		}
	}

	//Copy Constructor
	RefCount(const RefCount& rhs) : refptr(rhs.refptr) {}

	//Assignment Operator
	RefCount& operator= (const RefCount& rhs)
	{
		//Self-assignment check
		if (&rhs != this)
		{
			//Delete our refptr if one exists and now points to 0
			if (refptr && *refptr == 0) 
			{ 
				delete refptr; 
			}
			//Create a new refptr with the same values as RHS
			refptr = rhs.refptr;
		}
		return *this;
	}

	//Utility functions
	RefCount& increment()		
	{ 
		++*refptr; 
		return *this; 
	}
	const RefCount& increment() const { 
		++*refptr; 
		return *this;
	}
	RefCount& decrement()		
	{ 
		--*refptr; 
		return *this;
	}
	const RefCount& decrement() const 
	{ 
		--*refptr; 
		return *this;
	}
	bool isZero()		{ return *refptr == 0; }
	bool isZero() const { return *refptr == 0; }

	//Operator Overloads
	RefCount& operator++()		 { return increment(); }
	const RefCount& operator++() const { return increment(); }
	RefCount& operator--()		 { return decrement(); }
	const RefCount& operator--() const { return decrement(); }

	bool operator==(const RefCount& rhs) const { return *refptr == *rhs.refptr; }
	bool operator!=(const RefCount& rhs) const { return *refptr != *rhs.refptr; }

	//Conversion Operator Overload
	operator bool() const { return !isZero(); }

private:
	std::size_t* refptr;

};

#endif // !REF_COUNT_H
