#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H

#include <string>
#include "Str_Node.h"

class ReverseIterator 
{
public:
	ReverseIterator(Str_Node* p = 0) : pos(p) {}

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
	bool operator != (const ReverseIterator& it)
	{
		return this->pos != it.pos;
	}
	//Move to the next node - prefix
	ReverseIterator operator ++ ()
	{
		pos = pos->prev;
		return *this;
	}
	//Move to the previous node - prefix
	ReverseIterator operator -- ()
	{
		pos = pos->next;
		return *this;
	}
	//Move to the next node - postfix
	ReverseIterator operator ++ (int)
	{
		pos = pos->prev;
		return *this;
	}
	//Move to the previous node - postfix
	ReverseIterator operator -- (int)
	{
		pos = pos->next;
		return *this;
	}

private:
	Str_Node* pos;

};

#endif // !REVERSE_ITERATOR_H
