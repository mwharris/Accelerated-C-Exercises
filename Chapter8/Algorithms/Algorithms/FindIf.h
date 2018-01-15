#ifndef FIND_IF_H
#define FIND_IF_H

#include <ostream>

template <class I, class T>
bool my_find_if(I begin, I end, bool predicate(T element))
{
	while (begin != end)
	{
		if (predicate(*begin))
		{
			return true;
		}
		begin++;
	}
	return false;
}

void test_find_if(std::ostream& out);

#endif // !FIND_IF_H
