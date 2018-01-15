#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

#include "Student_Info.h"

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

//Separate a list of students by grade and set in map
void separate_by_grade(const vector<Student_Info>& students, map<char, int>& students_by_range)
{
	//Initialize grade ranges A - F
	students_by_range['A'] = 0;
	students_by_range['B'] = 0;
	students_by_range['C'] = 0;
	students_by_range['D'] = 0;
	students_by_range['F'] = 0;
	//Loop through students and add them to the above ranges
	for (vector<Student_Info>::const_iterator it = students.begin(); it != students.end(); it++)
	{
		++students_by_range[it->letter_grade];
	}
}

int main()
{
	vector<Student_Info> students;
	string::size_type maxLengthName = 0;

	//Read in all student information
	Student_Info record;
	while (read(cin, record))
	{
		students.push_back(record);
		//Also find the longest student name
		maxLengthName = max(maxLengthName, record.name.size());
	}

	//Sort the array of students alphabetically
	sort(students.begin(), students.end(), compare);

	//Calculate the final grade and print
	cout << string(20, '-') << endl;
	cout << "ALL STUDENTS GRADES" << endl;
	cout << string(20, '-') << endl;
	for (vec_sz i = 0; i < students.size(); i++)
	{
		//Display the player's name with appropriate padding
		string::size_type padding = (maxLengthName - students[i].name.size()) + minPadding;
		cout << students[i].name << string(padding, ' ');

		//Display the student's final grade if it was calculated
		if (students[i].final != -1)
		{
			streamsize prec = cout.precision();
			cout << setprecision(3) << students[i].final << setprecision(prec);
		}
		//Display an error message if we didn't calculate the grade properly
		else
		{
			cout << "Student has done no homework!";
		}

		//Line break for the next student
		cout << endl;
	}

	//Separate students into grade ranges
	map<char, int> students_by_range;
	separate_by_grade(students, students_by_range);

	//Next, print all students separated by grade ranges A-F
	cout << string(20, '-') << endl;
	cout << "STUDENTS BY GRADE RANGE" << endl;
	cout << string(20, '-') << endl;
	for (map<char, int>::const_iterator it = students_by_range.begin(); it != students_by_range.end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}

    return 0;
}