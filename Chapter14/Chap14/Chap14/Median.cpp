#include "stdafx.h"
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::domain_error;
using std::sort;

typedef vector<double>::size_type vec_sz;

//Calculate the median of a vector of hw grades
double median(vector<double> hw)
{
	//Make sure homework grades were entered
	vec_sz size = hw.size();
	if (size == 0)
	{
		return 0;
	}
	else if (size == 1)
	{
		return hw[0];
	}
	//Sort the vector
	sort(hw.begin(), hw.end());
	//Calculate the median of the homework grades
	vec_sz mid = size / 2;
	double median = mid % 2 == 0 ? ((hw[mid - 1] + hw[mid]) / 2) : hw[mid];
	return median;
}