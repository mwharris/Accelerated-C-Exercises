#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

#include "Core.h"
#include "Grad.h"
#include "PassFail.h"
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

typedef vector<Student_Info>::size_type vec_sz;

const string::size_type minPadding = 5;

int main()
{
	vector<Student_Info> students;
	string::size_type maxLengthName = 0;

	//Read in all student information
	Student_Info record;
	while (record.read(cin))
	{
		//Add this record to our list of records
		students.push_back(record);
		//Also find the longest student name
		maxLengthName = max(maxLengthName, record.get_name().size());
	}

	//Sort the array of students alphabetically
	sort(students.begin(), students.end(), Student_Info::compare);

	//Calculate the final grade and print
	cout << string(20, '-') << endl;
	cout << "ALL STUDENT'S GRADES" << endl;
	cout << string(20, '-') << endl;
	for (vec_sz i = 0; i < students.size(); i++)
	{
		//Display the player's name with appropriate padding
		string::size_type padding = (maxLengthName - students[i].get_name().size()) + minPadding;
		cout << students[i].get_name() << string(padding, ' ');

		//Display the student's final grade if homework is valid
		if (students[i].valid())
		{
			streamsize prec = cout.precision();
			cout << setprecision(3) << students[i].get_letter_grade();
			cout << " (" << students[i].get_final_grade() << ")" << setprecision(prec);
		}
		//Display an error message if we didn't calculate the grade properly
		else
		{
			cout << "Student has done no homework or failed thesis!";
		}
		//Line break for the next student
		cout << endl;
	}

	return 0;
}