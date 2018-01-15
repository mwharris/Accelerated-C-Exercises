#include "stdafx.h"
#include <algorithm>
#include <iterator>

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

double gen_analysis(const Student_Group& students, double aux(const Student_Info& s))
{
	vector<double> grades;

	//Run the grade function of every student and insert into a new vector
	transform(students.begin(), students.end(), back_inserter(grades), aux);

	//Find the median of all student grades
	return median(grades);

}

//Grade all students using the original median-based HW grading, and find the median of all grades
double median_analysis(const Student_Group& students)
{
	vector<double> grades;

	//Run the grade function of every student and insert into a new vector
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

	//Find the median of all student grades
	return median(grades);
}

//Grade all students using an average-based HW grading, then find the median of all grades
double average_analysis(const Student_Group& students)
{
	vector<double> grades;

	//Run the average function on evert student and insert into a new vector
	transform(students.begin(), students.end(), back_inserter(grades), average_hw_grade);

	//Find the median of all the average grades
	return median(grades);
}

//Grade all students using an optimistic median based HW grading, then find the median of all grades
double optimistic_median_analysis(const Student_Group& students)
{
	vector<double> grades;

	//Run the optimistic median function on every student and insert into a new vector
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);

	//Find the median of all the optimistic median based grades
	return median(grades);
}

//Generic function to write the results of an analysis to the console
void write_analysis(ostream& out, const string& name, double analysis(const Student_Group& students, double aux(const Student_Info& students)),
	const Student_Group& did, const Student_Group& didnt, double aux(const Student_Info& students))
{
	//Call the analysis that we were passed on both student groups
	double did_result = gen_analysis(did, aux);
	double didnt_result = gen_analysis(didnt, aux);
	//Print the results
	cout << name << " (did): " << did_result << ", " << name << " (didnt): " << didnt_result << endl;
}