#include "stdafx.h"
#include <string>
#include <iostream>

#include "String_List.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

//Destructor
String_List::~String_List()
{
	//Simply delete all elements in the list
	Str_Node* curr = head_;
	while (curr)
	{
		Str_Node* next = curr->next;
		delete curr;
		curr = next;
	}
}

//Insert a new node before the given position.
//Position is expected to be NULL if inserting at tail.
void String_List::insert_internal(const std::string& s, Str_Node* pos)
{
	//Create a new node to store in the list
	Str_Node* n = new Str_Node(s);

	//Increment the size of the list
	size_++;

	//Default n's next to the passed-in position
	n->next = pos;

	//If we received a valid position
	if (pos)
	{
		//Update n, pos, and pos->prev pointers
		n->prev = pos->prev;
		pos->prev = n;
	}
	//If we didn't, insert at tail
	else
	{
		n->prev = tail_;
		tail_ = n;
	}

	//If list was not empty, update previous element
	if (n->prev)
	{
		n->prev->next = n;
	}
	//If list was empty, point head to new element
	else
	{
		head_ = n;
	}
}

//Remove the node at the given position
void String_List::remove_internal(Str_Node* pos)
{
	if (size_ > 0)
	{
		//Temp pointer to keep reference to element to delete
		Str_Node* del = pos;
		//Update pointers accordingly
		if (pos->prev)
		{
			pos->prev->next = pos->next;
		}
		if (pos->next)
		{
			pos->next->prev = pos->prev;
		}
		if (pos == head_)
		{
			head_ = pos->next;
		}
		if (pos == tail_)
		{
			tail_ = pos->prev;
		}
		//Delete the element
		delete del;
		//Decrement the size
		size_--;
	}
}

//Push a new element to the front of the list
void String_List::push_front(const string& s)
{
	insert_internal(s, head_);
}

//Push a new element to the back of the list
void String_List::push_back(const string& s)
{
	insert_internal(s, 0);
}

//Remove an element from the front of the list
void String_List::pop_front()
{
	remove_internal(head_);
}

//Remove an element from the back of the list
void String_List::pop_back()
{
	remove_internal(tail_);
}

void String_List::print()
{
	cout << "----------------------------------------------" << endl;

	//Print the head
	cout << "head" << endl;
	cout << "  points to: " << head_->data << endl;
	if (head_->next) 
	{
		cout << "  next is:   " << head_->next->data << endl;
	}
	cout << endl;
	
	//Print the stuff in between
	if (head_->next) 
	{
		int i = 1;
		Str_Node* curr = head_->next;
		while (curr != tail_)
		{
			cout << "Element " << i << endl;
			cout << "  points to: " << curr->data << endl;
			cout << "  next is:   " << curr->next->data << endl;
			cout << "  prev is:   " << curr->prev->data << endl;
			cout << endl;
			curr = curr->next;
			i++;
		}
	}

	//Print the tail
	cout << "tail" << endl;
	cout << "  points to: " << tail_->data << endl;
	if (tail_->prev)
	{
		cout << "  prev is:   " << tail_->prev->data << endl;
	}
}