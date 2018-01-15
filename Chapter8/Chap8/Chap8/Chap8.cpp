#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::find;
using std::domain_error;
using std::distance;

template <class I, class T>
T median_one(I begin, I end, T type)
{
	//Build a vector based on the range
	vector<T> v(begin, end);
	//Check the size of the vector we created
	typedef typename vector<T>::size_type vec_sz;
	vec_sz size = v.size();
	if (v.size() == 0)
	{
		throw domain_error("Attempted to find median of empty range!");
	}
	//Sort the vector
	sort(v.begin(), v.end());
	//Determine the median
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

template <class I, class T>
T median_two(I begin, I end, T type)
{
	typedef typename vector<T>::size_type vec_sz;
	//Determine the distance between the two iterators
	vec_sz size = distance(begin, end);
	if (size == 0)
	{
		throw domain_error("Attempted to find median of empty range!");
	}
	//Sort the sequence
	sort(begin, end);
	//Determine the median
	vec_sz mid = size / 2;
	if (size % 2 == 0)
	{
		return (*(begin + mid) + *(begin + mid - 1)) / 2;
	}
	else
	{
		return *(begin + mid);
	}
}

int main()
{
	vector<int> ints;
	ints.push_back(2);
	ints.push_back(100);
	ints.push_back(1);
	ints.push_back(40);
	ints.push_back(20);
	ints.push_back(80);
	int iResultOne = median_one(ints.begin(), ints.end(), 1);
	int iResultTwo = median_two(ints.begin(), ints.end(), 1);

	vector<double> doubles;
	doubles.push_back(100.0);
	doubles.push_back(1.0);
	doubles.push_back(99.0);
	doubles.push_back(50.0);
	doubles.push_back(20.0);
	doubles.push_back(40.0);
	double dResultOne = median_one(doubles.begin(), doubles.end(), 1.0);
	double dResultTwo = median_two(doubles.begin(), doubles.end(), 1.0);

	cout << "Int median one:    " << iResultOne << endl;
	cout << "Int median two:    " << iResultTwo << endl;
	cout << "Double median one: " << dResultOne << endl;
	cout << "Double median two: " << dResultTwo << endl;

    return 0;
}