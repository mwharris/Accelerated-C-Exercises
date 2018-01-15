#include "stdafx.h"
#include <algorithm>
#include <iterator>
#include <stdexcept>

#include "Analysis.h"
#include "Grade.h"
#include "Median.h"

using std::vector;
using std::transform;
using std::back_inserter;
using std::ostream;
using std::string;
using std::cout;
using std::endl;
using std::domain_error;

//Auxilary function for passing to algorithms
double grade_aux(const Student_Info& s)
{
	try {
		return grade(s);
	}
	catch (domain_error e) {
		return grade(s.midterm, s.final, 0);
	}
}

//Calculate the average of the hw vector, then the final grade
double average_hw_grade(const Student_Info& s)
{
	try {
		double grd = grade(s.midterm, s.final, average_hw(s.homework));
		return grd;
	}
	catch (domain_error e) {
		return grade(s.midterm, s.final, 0);
	}
}

//Calculate a student's final grade, using "optimistic" median for calculating HW.
//"optimistic" median removes all 0 grades and calculates median with the results.
double optimistic_median(const Student_Info& s)
{
	vector<double> nonzeroes;

	//Remove all 0's, copy non-zeroes to the nonzero vector
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzeroes), 0);

	//Calculate the grade. Use 0 for non homework
	if (nonzeroes.empty())
	{
		return grade(s.midterm, s.final, 0);
	}
	else
	{
		return grade(s.midterm, s.final, median(nonzeroes));
	}
}