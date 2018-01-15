#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

#include "Student_Info.h"
#include "ExtractFailures.h"

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
using std::map;

typedef vector<double>::size_type vec_sz;

const string::size_type minPadding = 5;

int main()
{
	vector<Student_Info> students;
	string::size_type maxLengthName = 0;

	//Read in all student information
	Student_Info record;
	while (record.read(cin))
	{
		students.push_back(record);
		//Also find the longest student name
		maxLengthName = max(maxLengthName, record.get_name().size());
	}

	//Sort the array of students alphabetically
	sort(students.begin(), students.end(), compare);

	//Extract the failing records
	cout << string(20, '-') << endl;
	vector<Student_Info> failures = extract_fails(students);

	//Print all passing student grades
	cout << string(20, '-') << endl;
	cout << "PASSING STUDENT GRADES" << endl;
	cout << string(20, '-') << endl;
	for (vec_sz i = 0; i < students.size(); i++)
	{
		//Display the player's name with appropriate padding
		string::size_type padding = (maxLengthName - students[i].get_name().size()) + minPadding;
		cout << students[i].get_name() << string(padding, ' ');
		//Display the student's final grade if homework is valid
		cout << "P" << endl;
	}

	//Print all failing student grades
	cout << string(20, '-') << endl;
	cout << "FAILING STUDENT GRADES" << endl;
	cout << string(20, '-') << endl;
	for (vec_sz i = 0; i < students.size(); i++)
	{
		//Display the player's name with appropriate padding
		string::size_type padding = (maxLengthName - students[i].get_name().size()) + minPadding;
		cout << students[i].get_name() << string(padding, ' ');
		//Display the student's final grade if homework is valid
		cout << "F" << endl;
	}

	return 0;
}