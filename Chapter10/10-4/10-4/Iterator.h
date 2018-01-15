#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>
#include "Str_Node.h"

class Iterator 
{
public:
	Iterator(Str_Node* p = 0) : pos(p) {}

	//Dereference the iterator and return the data value
	std::string operator * ()
	{
		return pos->data;
	}
	//Dereference the iterator and return a pointer to the data
	std::string* operator -> ()
	{
		return &(pos->data);
	}
	//Compare the data in this and the passed-in iterator
	bool operator != (const Iterator& it)
	{
		return this->pos != it.pos;
	}
	//Move to the next node
	Iterator operator ++ ()
	{
		pos = pos->next;
		return *this;
	}
	//Move to the previous node
	Iterator operator -- ()
	{
		pos = pos->prev;
		return *this;
	}
	//Move to the next node
	Iterator operator ++ (int)
	{
		pos = pos->next;
		return *this;
	}
	//Move to the previous node
	Iterator operator -- (int)
	{
		pos = pos->prev;
		return *this;
	}

private:
	Str_Node* pos;

};

#endif // !ITERATOR_H
