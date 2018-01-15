#ifndef MEDIAN_H
#define MEDIAN_H

#include <vector>
#include <algorithm>

//double median(std::vector<double> hw);

using std::sort;

template<typename T, class Iterator>
T median(Iterator begin, Iterator end)
{
	//Make sure homework grades are entered
	if (begin == end)
	{
		return 0;
	}
	//Create a temp vector we can sort
	vector<T> temp;
	while (begin != end)
	{
		temp.push_back(*begin);
		begin++;
	}
	//Sort the temp vector
	sort(temp.begin(), temp.end());
	//Calculate the median
	size_t mid = temp.size() / 2;
	T median = mid % 2 == 0 ? ((temp[mid - 1] + temp[mid]) / 2) : temp[mid];
	return median;
}

#endif // !MEDIAN_H