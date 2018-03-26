#ifndef PTR_H
#define PTR_H

#include "Vec.h"
#include "RefCount.h"

template <class T>
class Ptr
{
public:
	Ptr() : p(0) {}
	Ptr(T* t) : p(t) {}

	//Destructor
	~Ptr()
	{
		//Decrement ref count, if we hit 0 then delete our object
		--refCount;
		if (!refCount)
		{
			delete p;
		}
	}

	//Copy Constructor
	Ptr(const Ptr& p2) : p(p2.p), refCount(p2.refCount) 
	{ 
		++refCount; 
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
		if (refCount != 1)
		{
			//Decrement the ref count
			--refCount;
			//Create a new ref count for our unique object
			refCount = RefCount(1);
			//Clone the data
			p = p ? clone(p) : 0;
		}
	}

private:
	T* p;
	RefCount refCount;

};

template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
	//Increment the counter of RHS since we will be adding another ref
	++rhs.refCount;
	//Free the LHS if necessary
	--refCount;
	if (!refCount)
	{
		delete p;
	}
	//Copy values from RHS to LHS
	refCount = rhs.refCount;
	p = rhs.p;
	return *this;
}

#endif // !PTR_H
