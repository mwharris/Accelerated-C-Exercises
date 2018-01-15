#include "stdafx.h"
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <iterator>

using std::vector;
using std::vector;
using std::domain_error;
using std::sort;
using std::distance;

//Calculate the median of a vector of hw grades
double median(vector<double> hw)
{
	//Make sure homework grades were entered
	vector<double>::size_type size = hw.size();
	if (size == 0)
	{
		return 0;
	}

	double median; 
	
	//Sort the vector
	sort(hw.begin(), hw.end());

	//Determine the median
	vector<double>::size_type mid = size / 2;
	median = size % 2 == 0 ? ((hw[mid - 1] + hw[mid]) / 2) : hw[mid];
	
	return median;
}