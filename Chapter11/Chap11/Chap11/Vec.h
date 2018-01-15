#ifndef VEC_H
#define VEC_H

#include <memory>
#include <algorithm>

using std::uninitialized_fill;
using std::uninitialized_copy;
using std::max;

template <class T> 
class Vec
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef std::size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;

	/*
	 *	Constructors
	 */
	Vec() 
	{ 
		create(); 
	}

	explicit Vec(std::size_t n, const T& val = T()) 
	{ 
		create(n, val); 
	}

	//Copy constructor
	Vec(const Vec& v)
	{
		create(v.begin(), v.end());
	}

	~Vec() 
	{
		uncreate();
	}

	/*
	 *	Operator Overloads
	 */
	//Assignment Operator
	Vec& operator=(const Vec& rhs)
	{
		//Make sure the argument is not ourselves
		if (&rhs != this)
		{
			//Free the array on lhs (uncreate())
			this->uncreate();
			//Create a new Vec using the RHS Vec
			create(rhs.begin(), rhs.end());
		}
		return *this;
	}

	const T& operator[] (size_type index) const { 
		return data[index]; 
	}
	
	T& operator[] (size_type index) { 
		return data[index]; 
	}

	/*
	 *	Utility Functions
	 */
	void push_back(const T& val)
	{
		//If we've reached the end of our memory
		if (avail == limit)
		{
			//Double the amount of available memory
			grow();
		}
		//Append the new element
		unchecked_append(val);
	}

	//Remove a single element from the vector
	iterator erase(iterator position)
	{
		//If we didn't remove the last element in the vector
		if (position != (avail - 1))
		{
			//Loop through the rest of the vector and move each element back one spot
			iterator prev = position;
			iterator temp = position + 1;
			while (temp != avail)
			{
				*prev++ = *temp++;
			}
			//Delete the now duplicated element at the end
			alloc.destroy(prev);
		}
		else
		{
			//Delete the element at the end
			alloc.destroy(position);
		}
		//Move the back pointer back one element
		avail--;
		//Return the new element that now occupies the given position's space
		return position;
	}

	//Destroy all elements in the vector
	void clear()
	{
		avail--;
		while (avail != data)
		{
			alloc.destroy(avail--);
		}
		alloc.destroy(avail);
	}

	size_type size() const
	{
		return avail - data;
	}

	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return avail; }
	const_iterator end() const { return avail; }

private:
	//Will always point to the first element in the array
	iterator data;
	//Will point to the 1 + last element in the array
	iterator limit;
	//Will always point to the last spot of memory available
	iterator avail;

	//Used for memory allocation
	std::allocator<T> alloc;

	//Allocate and initialize the underlying array
	void create(); 
	void create(std::size_t n, const T& val);
	void create(const_iterator beg, const_iterator end);

	//Destroy the elements in the array
	void uncreate();

	//Support functions for push_back
	void grow();
	void unchecked_append(const T& val);
};

template <class T>
void Vec<T>::create()
{
	//Simply initialize our pointers to 0
	data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(std::size_t n, const T& val)
{
	//Allocate enough space to hold n items
	data = alloc.allocate(n);
	//Setup our pointers
	limit = avail = data + n;
	//Construct objects to fill the allocated space
	uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator begin, const_iterator end)
{
	//Allocate equal space to the range passed in
	data = alloc.allocate(end - begin);
	//Copy the elements in the range begin - end, and update our pointers to the end location
	limit = avail = std::uninitialized_copy(begin, end, data);
}

//Destroy all elements and deallocate all memory
template <class T>
void Vec<T>::uncreate()
{
	//If we allocated data
	if (data)
	{
		//Destroy each element in reverse order
		iterator it = avail;
		while (it != data)
		{
			alloc.destroy(--it);
		}
		//Free the amount of memory allocated
		alloc.deallocate(data, limit - data);
	}
	//Reset pointers to indicate an empty vector
	data = limit = avail = 0;
}

//Double the size of available memory and update pointers
template <class T>
void Vec<T>::grow()
{
	//Determine the new size of memory, the max() is in case the memory is currently 0
	size_t new_size = max(2 * (limit - data), ptrdiff_t(1));
	//Allocate this amount of space
	iterator new_data = alloc.allocate(new_size);
	//Copy the old elements into the new space
	iterator new_avail = uninitialized_copy(data, avail, new_data);
	//Destroy the old space
	uncreate();
	//Reset pointers to point to the new space
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

//Construct a new element to the available memory
template <class T>
void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
}

#endif // !VEC_H
