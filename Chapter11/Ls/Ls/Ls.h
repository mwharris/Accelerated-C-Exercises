#ifndef LS_H
#define LS_H

#include <memory>
#include <algorithm>

using std::uninitialized_fill;
using std::uninitialized_copy;
using std::max;

template <class T>
class Ls
{
public:
	/*
		Constructors
	*/
	Ls()
	{
		create();
	}

	Ls(size_t n, const T& val)
	{
		create(n, val);
	}

	Ls(T* start, T* end)
	{
		create(start, end);
	}

	//Copy Constructor
	Ls(const Ls& l)
	{
		create(l.begin(), l.end());
	}

	/*
		Destructor
	*/
	~Ls()
	{
		uncreate();
	}

	/*
		Operator Overloads
	*/
	//Assignment Operator
	Ls& operator=(const Ls& rhs)
	{
		//Prevent self-assignment
		if (&rhs != this)
		{
			//Destroy the lhs
			this->uncreate();
			//Create a new chunk of memory using rhs
			create(rhs.begin(), rhs.end());
		}
		return *this;
	}

	const T& operator[] (size_t i) const
	{
		return data[i];
	}

	T& operator[] (size_t i)
	{
		return data[i];
	}

	/*
		Member Functions
	*/
	void push_back(const T& val)
	{
		//If we are at max capacity, double the memory size
		if (avail == limit)
		{
			grow();
		}
		//Construct a new object in available memory
		append(val);
	}

	/*
		Utility Functions
	*/
	T* erase(T* position)
	{
		//If we are NOT deleting the last element
		if (position != avail - 1)
		{
			//Move all elements back one space
			T* temp = position + 1;
			T* prev = position;
			while (temp != avail)
			{
				*prev++ = *temp++;
			}
			//Delete the final element which is now a dupe
			alloc.destroy(prev);
		}
		//If we are deleting the last element
		else
		{
			alloc.destroy(position);
		}
		//Decrement the avail pointer
		avail--;
		return position;
	}


	T* erase(T* start, T* end)
	{
		//Cap our deletion at the end of the list
		if (end > avail)
		{
			end = avail;
		}
		//Loop through the list and delete everything in range
		T* it = start;
		while (it != end)
		{
			alloc.destroy(it++);
		}
		//Move objects back
		if (end != avail)
		{
			T* front = start;
			T* back = end;
			while (back != avail)
			{
				*front++ = *back;
				alloc.destroy(back++);
			}
			avail = front;
		}
		else
		{
			avail = start;
		}
		return start;
	}

	T* begin()			    { return data;  }
	const T* begin() const  { return data;  }

	T* end()			    { return avail; }
	const T* end() const    { return avail; }
	
	size_t size() const	    { return avail - data; }
	size_t max_size() const { return limit - data; }
	bool empty()		    { return data == avail; }

private:
	//Pointers to our memory ranges
	T* data;
	T* avail;
	T* limit;

	//Memory allocator
	std::allocator<T> alloc;

	//Helper functions
	void create();
	void create(size_t n, const T& data);
	void create(const T* start, const T* end);
	void uncreate();
	void grow();
	void append(const T& val);
};

//Create an empty list with no memory
template <class T>
void Ls<T>::create()
{
	//Simply default all pointers to 0
	data = avail = limit = 0;
}

//Create a list of n items which are copies of val
template <class T>
void Ls<T>::create(size_t n, const T& val)
{
	//Allocate enough space to hold n items
	data = alloc.allocate(n);
	//Setup our data pointers
	limit = avail = data + n;
	//Construct objects of val to fill the range data - limit
	uninitialized_fill(data, limit, val);
}

//Create a list given the range of another list
template <class T>
void Ls<T>::create(const T* start, const T* end)
{
	//Allocate space equal to the passed-in range
	data = alloc.allocate(end - start);
	//Copy elements from range to our newly allocated space
	limit = avail = uninitialized_copy(start, end, data);
}

//Destroy all elements stored and free memory
template <class T>
void Ls<T>::uncreate()
{
	//If data was allocated
	if (data)
	{
		T* it = data;
		//Destroy every element constructed
		while (it != avail)
		{
			alloc.destroy(it++);
		}
		//Free the allocated memory
		alloc.deallocate(data, limit - data);
	}
	//Reset poitners back to 0
	data = avail = limit = 0;
}

template <class T>
void Ls<T>::grow()
{
	//Create a new chunk of memory double the size of the old memory
	size_t newSize = max(2 * (limit - data), ptrdiff_t(1));
	T* newData = alloc.allocate(newSize);
	//Copy the elements over to the new chunk
	T* newAvail = uninitialized_copy(data, avail, newData);
	//Destroy the old space
	uncreate();
	//Reinitialize the pointers with the new memory
	data = newData;
	avail = newAvail;
	limit = newData + newSize;
}

template <class T>
void Ls<T>::append(const T& val)
{
	alloc.construct(avail++, val);
}

#endif // !LS_H
