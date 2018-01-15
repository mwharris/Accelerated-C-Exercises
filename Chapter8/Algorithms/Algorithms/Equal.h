#ifndef EQUAL_H
#define EQUAL_H

#include <iostream>
#include <vector>

template <class I>
bool my_equal(I begin, I end, I check)
{
	while (begin != end)
	{
		if (*begin != *check)
		{
			return false;
		}
		begin++;
		check++;
	}
	return true;
}

void test_equal(std::ostream& out);

#endif // !EQUAL_H
