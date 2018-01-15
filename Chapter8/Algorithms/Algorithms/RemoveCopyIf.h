#ifndef REMOVE_COPY_IF_H
#define REMOVE_COPY_IF_H

#include <ostream>

template <class I, class O, class T>
O my_remove_copy_if(I begin, I end, O dest, bool predicate(const T& t))
{
	while (begin != end)
	{
		if (!predicate(*begin))
		{
			*dest++ = *begin;
		}
		begin++;
	}
	return dest;
}

void test_remove_copy_if(std::ostream& out);

#endif // !REMOVE_COPY_IF_H
