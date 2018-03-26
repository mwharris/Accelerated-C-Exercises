#include "stdafx.h"
#include <stdexcept>

#include "Grade.h"
#include "Median.h"

using std::domain_error;

//Calculate the final grade given all grades and percentages
double grade(double midterm, double final, double homework)
{
	return (midterm * midtermPerc) + (final * finalPerc) + (homework * homeworkPerc);
}

//Calculate the median of the hw vector, then the final grade
double grade(double midterm, double final, const Vec<double>& hw)
{
	return grade(midterm, final, median(hw));
}

//Calculate the average between midterm and final grades
double grade(double midterm, double final)
{
	return (midterm + final) / 2;
}