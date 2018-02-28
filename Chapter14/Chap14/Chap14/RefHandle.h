#ifndef REF_HANDLE_H
#define REF_HANDLE_H

template <class T>
class RefHandle
{
public:
	RefHandle() : p(0), refptr(new std::size_t(1)) {}
	RefHandle(T* t) : p(t), refptr(new std::size_t(1)) {}

	//Copy Constructor
	RefHandle(const RefHandle& rh) : p(rh.p), refptr(rh.refptr)
	{
		//Increment the shared reference count
		*refptr++;
	}

	//Destructor: simply delete members
	~RefHandle() 
	{
		//If we are the last handle pointing to this data
		if (*refptr == 1)
		{
			//Delete the data
			delete p;
			delete refptr;
		}
		//If there are other pointers pointing to the data
		else
		{
			//Simply decrement the ref count
			*refptr--;
		}
	}
	
	//Assignment Operator
	RefHandle& operator= (const RefHandle& rhs)
	{
		//Protect against self-assignment
		if (&rhs != this)
		{
			//If LHS ref count is 1, Delete the object and ref counter
			if (*refptr == 1)
			{
				delete p;
				delete refptr;
			}
			//If LHS > 1, then decrement the ref counter
			else
			{
				*refptr--;
			}
			//Increment the vlaue of RHS ref count
			*rhs.refptr++;
			//Copy RHS values to LHS
			p = rhs.p;
			refptr = rhs.refptr;
		}
		return *this;
	}

	//Operator Overloads
	T* operator->() const 
	{
		if (p) { return p; }
		else { throw runtime_error("Unbound RefHandle!"); }
	}
	T& operator*() const  
	{
		if (p) { return *p; }
		else { throw runtime_error("Unbound RefHandle!"); }
	}

	//Conversion Operator Overloads
	operator bool() const { return p; }

private:
	T* p;
	//Why is this a pointer?...
	std::size_t* refptr;
};

#endif // !REF_HANDLE_H
