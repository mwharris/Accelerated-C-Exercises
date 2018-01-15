#ifndef REMOVE_COPY_H
#define REMOVE_COPY_H

#include <ostream>

template <class I, class O, class T>
O my_remove_copy(I begin, I end, O dest, const T& val)
{
	while (begin != end)
	{
		if (*begin != val)
		{
			*dest++ = *begin;
		}
		begin++;
	}
	return dest;
}

void test_remove_copy(std::ostream& out);

#endif // !REMOVE_COPY_H
