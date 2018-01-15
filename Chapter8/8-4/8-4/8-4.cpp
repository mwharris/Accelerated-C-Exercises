#include "stdafx.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

template <class T>
void swap(T& first, T& second)
{
	T temp;
	temp = second;
	second = first;
	first = temp;
}

template <class Bi>
void my_reverse(Bi begin, Bi end)
{
	while (begin != end)
	{
		end--;
		if (begin != end)
		{
			swap(*begin++, *end);
		}
	}
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);

	//Print the vector before the reverse
	cout << "Before: ";
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		if (it == v.begin())
		{
			cout << *it;
		}
		else
		{
			cout << ", " << *it;
		}
	}
	cout << endl;

	//Perform the reverse
	my_reverse(v.begin(), v.end());

	//Print the vector before the reverse
	cout << "After: ";
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		if (it == v.begin())
		{
			cout << *it;
		}
		else
		{
			cout << ", " << *it;
		}
	}
	cout << endl;

    return 0;
}

