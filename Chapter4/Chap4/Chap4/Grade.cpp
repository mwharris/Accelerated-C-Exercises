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
	if (hw.size() == 0)
	{
		domain_error("Student has done no homework!");
	}
	return grade(midterm, final, median(hw));
}

/*
//Break a student object up into important information and pass along
double grade(const Student_Info& s)
{
	return grade(s.midterm, s.final, s.homework);
}
*/