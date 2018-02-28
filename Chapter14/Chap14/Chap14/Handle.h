#ifndef HANDLE_H
#define HANDLE_H

#include "Core.h"

template <class T>
class Handle
{
public:
	//Constructors and Destructor
	Handle() : p(0) {}
	Handle(T* t) : p(t) {}
	~Handle() { delete p; }

	//Copy Constructor
	Handle(const Handle& h) : p(0) { 
		if (h.p) 
		{ 
			p = h.p->clone(); 
		} 
	}
	
	//Assignment Operator
	Handle& operator= (const Handle& h);

	//Conversion Operator Overloads
	operator bool() const { return p; }
	T& operator*() const;
	T* operator->() const;

private:
	T* p;
};

bool compare_core_handles(const Handle<Core>& a, const Handle<Core>& b);

template <class T>
Handle<T>& Handle<T>::operator= (const Handle& rhs)
{
	//Check for self-assignment
	if (&rhs != this)
	{
		//Destroy data in this object
		delete p;
		//Copy the rhs and point us to that copy 
		p = rhs.p ? rhs.p->clone() : 0;
	}
	return *this;
}

//Dereference operator overload
template <class T>
T& Handle<T>::operator*() const
{
	//Return the address of the object we are pointing to
	if (p) { return *p; }
	//If we're unbound then throw an error
	else { throw std::runtime_error("Unbound Handle!"); }
}

//Pointer operator overload
template <class T>
T* Handle<T>::operator->() const
{
	//Return the pointer to the object to which we are bound
	if (p) { return p; }
	//If we're unbound then throw an error
	else { throw std::runtime_error("Unbound Handle!"); }
}

#endif // !HANDLE_H
