#include "stdafx.h"
#include <string>
#include <iostream>

#include "Vec.h"

int main()
{
	Vec<std::string> v;
	v.push_back("Zero");
	v.push_back("One");
	v.push_back("Two");
	v.push_back("Three");
	v.push_back("Four");

	std::string* ptr = &v[2];
	ptr = v.erase(ptr);

	v.clear();
	v.push_back("Fuck");
	v.push_back("You");

	for (std::size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}

    return 0;
}