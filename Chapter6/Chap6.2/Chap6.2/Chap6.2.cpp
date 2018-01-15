#include "stdafx.h"

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <list>

#include "Student_Info.h"
#include "ExtractFailures.h"
#include "ExtractDidnt.h"
#include "Student_Group.h"
#include "Analysis.h"
#include "Grade.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::domain_error;
using std::sort;
using std::max;
using std::streamsize;
using std::setprecision;
using std::list;

const string::size_type minPadding = 5;

//Helper function to print a student group's grades to the screen
void print_student_group(const Student_Group& s)
{
	for (Student_Group::const_iterator it = s.begin(); it < s.end(); it++)
	{
		cout << it->name << ", Grade: " << it->finalGrade << endl;
	}
}

int main()
{
	Student_Group did, didnt, fail_did, fail_didnt;

	//Read in all student information
	Student_Info record;
	while (read(cin, record))
	{
		did.push_back(record);
	}

	//Extract students from the list/vector that didn't do all the hw
	didnt = extract_didnt(did);

	//Check if either of the list/vectors are empty
	if (did.empty())
	{
		cout << "No student did all of the homework!" << endl;
	}
	if (didnt.empty())
	{
		cout << "All students did their homework!" << endl;
	}

	//Extract all failures from both arrays
	fail_did = extract_fails_v2(did);
	fail_didnt = extract_fails_v2(didnt);

	//Execute and print the results of our analysis
	cout << string(30, '*') << endl; 
	cout << "ANALYSIS" << endl;
	cout << string(30, '*') << endl;
	write_analysis(cout, "median", gen_analysis, did, didnt, grade_aux);
	write_analysis(cout, "average", gen_analysis, did, didnt, average_hw_grade);
	write_analysis(cout, "optimistic", gen_analysis, did, didnt, optimistic_median);
	cout << string(30, '*') << endl;

	//Print all passing grades
	cout << string(30, '*') << endl;
	cout << "FINAL GRADES - PASSING" << endl;
	cout << string(30, '*') << endl;
	print_student_group(did);
	print_student_group(didnt);

	cout << string(30, '*') << endl;
	cout << "FINAL GRADES - FAILING" << endl;
	cout << string(30, '*') << endl;
	print_student_group(fail_did);
	print_student_group(fail_didnt);

	return 0;
}
