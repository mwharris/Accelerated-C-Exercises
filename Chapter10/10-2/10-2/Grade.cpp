#include "stdafx.h"
#include <vector>
#include <stdexcept>
#include "Grade.h"
#include "Median.h"

using std::vector;
using std::domain_error;

//Calculate the final grade given all grades and percentages
double grade(double midterm, double final, double homework)
{
	return (midterm * midtermPerc) + (final * finalPerc) + (homework * homeworkPerc);
}

//Calculate the median of the hw vector, then the final grade
double grade(double midterm, double final, const vector<double>& hw)
{
	//Test median function using a vector
	double med = median<double>(hw.begin(), hw.end());
	//"Instantiate" an array and test with that as well
	const double* b = &hw[0];
	const double* e = &hw[hw.size() - 1];
	e++;
	double med_2 = median<double>(b, e);
	//Calculate the grade using the median found
	return grade(midterm, final, med_2);
}

/*
//Break a student object up into important information and pass along
double grade(const Student_Info& s)
{
	return grade(s.midterm, s.final, s.homework);
}
*/