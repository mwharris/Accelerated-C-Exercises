#ifndef REMOVE_H
#define REMOVE_H

#include <ostream>

template<class I, class T>
I my_remove(I begin, I end, const T& t)
{
	//Create temp iterators
	I right = end;
	right--;

	//Loop until the two iterators meet
	while (begin < right)
	{
		//If we found an element that needs to be shifted
		if (*begin == t)
		{
			//Iterate backwards using the right iterator until we find a replacement
			while (right > begin && *right == t)
			{
				right--;
			}
			//Shift right with left
			T temp = *begin;
			*begin = *right;
			*right = temp;
		}
		begin++;
	}
	return begin;
}

void test_remove(std::ostream& out);

#endif // !REMOVE_H
