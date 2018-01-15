#include "stdafx.h"
#include <stdexcept>

#include "Student_Info.h"
#include "Grade.h"

using std::cin;
using std::cout;
using std::vector;
using std::istream;
using std::domain_error;

//Return the letter grade a student deserves based on number grade
char get_letter_grade(double grade)
{
	if (grade >= 90)
	{
		return 'A';
	}
	else if (grade >= 80 && grade < 90)
	{
		return 'B';
	}
	else if (grade >= 70 && grade < 80)
	{
		return 'C';
	}
	else if (grade >= 60 && grade < 70)
	{
		return 'D';
	}
	else
	{
		return 'F';
	}
}

//Custom comparator for Student Info objects
bool compare(const Student_Info& a, const Student_Info& b)
{
	return a.get_name() < b.get_name();
}

//Default constructor
Student_Info::Student_Info() : midterm(0), final(0) {}

//Initalizer constructor
Student_Info::Student_Info(istream& in)
{
	read(in);
}

//Read a list of homework grades into a student's homework vector
istream& Student_Info::read_hw(istream& in, vector<double>& hw)
{
	//Make sure our input stream is not in a failure state
	if (in)
	{
		//Clear the previous hw content
		hw.clear();
		//Read the input stream grades
		cout << "Please enter homework grades followed by end-of-file: ";
		double currGrade;
		while (in >> currGrade)
		{
			hw.push_back(currGrade);
		}
		//Clear the input stream failure state
		in.clear();
	}
	//Return our input stream
	return in;
}

//Read all of a student's information from the input stream
istream& Student_Info::read(istream& in)
{
	//Read the first name, midterm, and final grades
	cout << "Please enter name, midterm, and final grades or end-of-file: ";
	cin >> name >> midterm >> final;
	//Read in all homework grades
	read_hw(in, homework);
	//Grade the student's performance
	final_grade = ::grade(midterm, final, homework);
	//Return the input stream to preserve the state
	return in;
}