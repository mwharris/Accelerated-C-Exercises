#ifndef PARTITION_H
#define PARTITION_H

#include <ostream>

template <class I, class T>
I my_partition(I begin, I end, bool fn(const T& elem))
{
	//Create temp iterators
	I right = end;
	right--;

	//Loop until the two iterators meet
	while (begin < right)
	{
		//If we found an element that needs to be shifted to the back
		if (!fn(*begin))
		{
			//Iterate backwards until we find a replacement
			while (right > begin && !fn(*right))
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

void test_partition(std::ostream& out);

#endif // !PARTITION_H
