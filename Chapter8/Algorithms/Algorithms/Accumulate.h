#ifndef ACCUMULATE_H
#define ACCUMULATE_H

#include <ostream>

template <class I, class T>
T accumulate(I begin, I end, T val)
{
	while (begin != end)
	{
		val += *begin;
		begin++;
	}
	return val;
}

void test_accumulate(std::ostream& out);

#endif // !ACCUMULATE_H
