#ifndef FIND_H
#define FIND_H

#include <ostream>

template <class I, class T>
I my_find(I begin, I end, const T& t)
{
	while (begin != end)
	{
		if (*begin == t) 
		{
			return begin;
		}
		begin++;
	}
	return end;
}

void test_find(std::ostream& out);

#endif // !FIND_H