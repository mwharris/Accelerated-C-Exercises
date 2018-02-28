#ifndef PTR_H
#define PTR_H

#include "Vec.h"

template <class T>
class Ptr
{
public:
	Ptr() : p(0), refptr(new std::size_t(1)) {}
	Ptr(T* t) : p(t), refptr(new std::size_t(1)) {}

	//Destructor
	~Ptr()
	{
		//Decrement out ref count, if we hit 0 then delete
		if (--*refptr == 0) 
		{
			delete refptr;
			delete p;
		}
	}

	//Copy Constructor
	Ptr(const Ptr& p2) : p(p2.p), refptr(p2.refptr)
	{
		++*refptr;
	}

	//Assignment Operator
	Ptr& operator=(const Ptr& rhs);

	//Conversion Operator Overload
	operator bool() const { return p; }

	//Other Operator Overloads
	T& operator*() const  { return *p;  }
	T* operator->() const { return p; }

	//Global clone function that will help make_unique() clone T objects
	template <class T>
	T* clone(const T* tp)
	{
		return tp->clone();
	}
	//Template specialization for the above clone() function
	template<>
	Vec<char>* clone(const Vec<char>* vp)
	{
		return new Vec<char>(*vp);
	}

	//Helper function to make a copy whenever the user chooses
	void make_unique()
	{
		//If we aren't the last pointer
		if (*refptr != 1)
		{
			//Decrement the ref count
			--*refptr;
			//Create a new ref count for our unique object
			refptr = new std::size_t(1);
			//Clone the data
			p = p ? clone(p) : 0;
		}
	}

private:
	T* p;
	std::size_t* refptr;

};

template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
	//Increment the counter of RHS since we will be adding another ref
	++*rhs.refptr;
	//Free the LHS if necessary
	if (--*refptr == 0)
	{
		delete refptr;
		delete p;
	}
	//Copy values from RHS to LHS
	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

#endif // !PTR_H
