#include "stdafx.h"
#include <stdexcept>

#include "Grade.h"
#include "Median.h"

using std::vector;
using std::domain_error;
using std::vector;

const double failThreshold = 60;

//Calculate the final grade given all grades and percentages
double grade(double midterm, double final, double homework)
{
	double mid = midterm * midtermPerc;
	double fin = final * finalPerc;
	double hom = homework * homeworkPerc;
	double finalGrade = mid + fin + hom;
	return finalGrade;
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

//Break a student object up into important information and pass along
double grade(const Student_Info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

//Determine if a student's grade is failing or not
double fgrade(const Student_Info& s)
{
	return s.finalGrade < failThreshold;
}