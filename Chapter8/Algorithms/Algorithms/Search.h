#ifndef SEARCH_H
#define SEARCH_H

#include <ostream>

template <class I>
I my_search(I begin1, I end1, I begin2, I end2)
{
	while (begin1 != end1)
	{
		I it1 = begin1;
		I it2 = begin2;
		while (it2 != end2 && *it1 == *it2)
		{
			if (it1 == end1)
			{
				return end1;
			}
			it1++;
			it2++;
		}
		if (it2 == end2)
		{
			return begin1;
		}
		begin1++;
	}
	return end1;
}

void test_search(std::ostream& out);

#endif // !SEARCH_H
