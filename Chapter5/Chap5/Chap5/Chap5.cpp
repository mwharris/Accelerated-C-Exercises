#include "stdafx.h"
#include <string>
#include <vector>
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

typedef vector<double>::size_type vec_sz;

const string::size_type minPadding = 5;

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

	//Separate any failing grade students into another vector
	vector<Student_Info> fails = extract_failures(students);

	//Sort the array of students alphabetically
	sort(students.begin(), students.end(), compare);

	//Calculate the final grade and print
	cout << string(20, '-') << endl;
	for (vector<Student_Info>::const_iterator iter = students.begin(); iter != students.end(); iter++)
	{
		//Display the player's name with appropriate padding
		string::size_type padding = (maxLengthName - iter->name.size()) + minPadding;
		cout << iter->name << string(padding, ' ');

		//Display the student's final grade if it was calculated
		if (iter->final != -1)
		{
			streamsize prec = cout.precision();
			cout << setprecision(3) << iter->final << setprecision(prec);
		}
		//Display an error message if we didn't calculate the grade properly
		else
		{
			cout << "Student has done no homework!";
		}

		//Line break for the next student
		cout << endl;
	}

	return 0;
}