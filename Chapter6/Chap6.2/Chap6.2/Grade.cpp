#include "stdafx.h"
#include <stdexcept>
#include <numeric>
#include <algorithm>

#include "Grade.h"
#include "Median.h"
#include "Student_Group.h"

using std::vector;
using std::domain_error;
using std::accumulate;
using std::remove_copy;

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

//Determine if a student's grade is passing or not
double pgrade(const Student_Info& s)
{
	return !fgrade(s);
}

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
		return grade(s.midterm, s.final, average_hw(s.homework));
	}
	catch (domain_error e) {
		return grade(s.midterm, s.final, 0);
	}
}

//Average a list of grades
double average_hw(const vector<double>& grades)
{
	return accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
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
