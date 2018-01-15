#ifndef COPY_H
#define COPY_H

#include <ostream>

template <class I, class O>
O my_copy(I begin, I end, O dest)
{
	while (begin != end)
	{
		*dest++ = *begin++;
	}
	return dest;
}

void test_copy(std::ostream& out);

#endif // !COPY_H
