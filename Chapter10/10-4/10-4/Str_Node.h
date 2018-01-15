#ifndef STR_NODE_H
#define STR_NODE_H

#include <string>

//Nodes for our list will hold strings and point to previous and next
struct Str_Node
{
	//Constructor which takes string data, defaults next and prev
	Str_Node(std::string d) : data(d), next(0), prev(0) {}

	std::string data;
	Str_Node* next;
	Str_Node* prev;
};

#endif // !STR_NODE_H