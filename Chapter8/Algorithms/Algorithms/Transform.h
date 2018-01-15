#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <ostream>

template <class I, class O, class T>
void my_transform(I begin, I end, O dest, T fn(T& val))
{
	while (begin != end)
	{
		*dest++ = fn(*begin);
		begin++;
	}
}

void test_transform(std::ostream& out);

#endif // !TRANSFORM_H
