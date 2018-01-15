#ifndef STRING_LIST_H
#define STRING_LIST_H

#include <string>

#include "Str_Node.h"
#include "Iterator.h"
#include "ReverseIterator.h"

/*
	Exercise 10-4
	Write a class that implements a list that only holds strings
	- STL List is implements using a doubly linked list
*/
class String_List 
{
public:
	String_List() : head_(0), tail_(0), size_(0) {}
	~String_List();

	void push_back(const std::string& s);
	void push_front(const std::string& s);
	void pop_back();
	void pop_front();
	void print();

	bool empty() { return size_ == 0; }
	size_t size() { return size_; }
	std::string& front() { return head_->data; }
	std::string& back() { return tail_->data; }
	Iterator begin() { return Iterator(head_); }
	Iterator end() { return Iterator(0); }
	ReverseIterator rbegin() { return ReverseIterator(tail_); }
	ReverseIterator rend() { return ReverseIterator(0); }

private:
	//Store size to make a faster size() function
	size_t size_;
	//Keep references to first and last elements in the list
	Str_Node* head_;
	Str_Node* tail_;

	void insert_internal(const std::string& s, Str_Node* pos);
	void remove_internal(Str_Node* pos);
};

#endif // !STRING_LIST_H
