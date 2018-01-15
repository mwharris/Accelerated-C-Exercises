#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <vector>
#include <string>
#include <iostream>

#include "Student_Group.h"
#include "Student_Info.h"
#include "Median.h"

double grade_aux(const Student_Info& s);
double average_hw_grade(const Student_Info& s);
double optimistic_median(const Student_Info& s);

template <class Function>
double analysis(const Student_Group& students, Function grading_func)
{
	std::vector<double> grades;

	//Run the grade function of every student and insert into a new vector
	transform(students.begin(), students.end(), back_inserter(grades), grading_func);

	//Find the median of all student grades
	return median(grades);
}

template <class Function>
void write_analysis(std::ostream& out, const std::string& name, Function grading_func, const Student_Group& did, const Student_Group& didnt)
{
	//Call the analysis that we were passed on both student groups
	double did_result = analysis(did, grading_func);
	double didnt_result = analysis(didnt, grading_func);
	//Print the results
	out << name << " (did): " << did_result << ", " << name << " (didnt): " << didnt_result << std::endl;
}

#endif // !ANALYSIS_H