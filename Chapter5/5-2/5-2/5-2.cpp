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
#include "Student_Group.h"

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

int main()
{
	Student_Group students;
	string::size_type maxLengthName = 0;

	//Read in all student information
	Student_Info record;
	while (read(cin, record))
	{
		students.push_back(record);
		//Also find the longest student name
		maxLengthName = max(maxLengthName, record.name.size());
	}

	//Separate any failing grade students into another vector
	//Student_Group fails = extract_failures(students);
	extract_failures(students);

	//Sort the array of students alphabetically
	//TODO: THIS NEEDS TO CHANGE WHEN LIST/VECTOR CHANGES
	//students.sort(compare);
	//sort(students.begin(), students.end(), compare);

	//Print the list of passing students
	cout << string(20, '-') << endl << "Passing Students" << endl << string(20, '-') << endl;
	for (Student_Group::const_iterator iter = students.begin(); iter != students.end(); iter++)
	{
		//Display the player's name with appropriate padding
		string::size_type padding = (maxLengthName - iter->name.size()) + minPadding;
		cout << iter->name << string(padding, ' ');

		//Display the student's final grade if it was calculated
		if (iter->finalGrade != -1)
		{
			streamsize prec = cout.precision();
			cout << setprecision(3) << iter->finalGrade << setprecision(prec);
		}
		//Display an error message if we didn't calculate the grade properly
		else
		{
			cout << "Student has done no homework!";
		}

		//Line break for the next student
		cout << endl;
	}

	/*
	//Print the list of failing students
	cout << string(20, '-') << endl << "Failing Students" << endl << string(20, '-') << endl;
	for (Student_Group::const_iterator iter = fails.begin(); iter != fails.end(); iter++)
	{
		//Display the player's name with appropriate padding
		string::size_type padding = (maxLengthName - iter->name.size()) + minPadding;
		cout << iter->name << string(padding, ' ');

		//Display the student's final grade if it was calculated
		if (iter->finalGrade != -1)
		{
			streamsize prec = cout.precision();
			cout << setprecision(3) << iter->finalGrade << setprecision(prec);
		}
		//Display an error message if we didn't calculate the grade properly
		else
		{
			cout << "Student has done no homework!";
		}

		//Line break for the next student
		cout << endl;
	}
	*/

	return 0;
}