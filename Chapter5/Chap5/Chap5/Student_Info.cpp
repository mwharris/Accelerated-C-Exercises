#include "stdafx.h"
#include <stdexcept>

#include "Student_Info.h"
#include "Grade.h"

using std::cin;
using std::cout;
using std::vector;
using std::istream;
using std::domain_error;
using std::list;

//Custom comparator for Student Info objects
bool compare(const Student_Info& a, const Student_Info& b)
{
	return a.name < b.name;
}

//Read a list of homework grades into a student's homework vector
istream& read_hw(istream& in, vector<double>& hw)
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
istream& read(istream& in, Student_Info& s)
{
	//Read the first name, midterm, and final grades
	cout << "Please enter name, midterm, and final grades or end-of-file: ";
	cin >> s.name >> s.midterm >> s.final;

	//Read in all homework grades
	read_hw(in, s.homework);
	
	//Calculate the student's final grade if we didn't hit end-of-file
	if (in) 
	{
		//Exception is thrown if no HW was entered
		try {
			s.finalGrade = grade(s.midterm, s.final, s.homework);
		}
		catch (domain_error e) {
			s.final = -1;
			return in;
		}
	}
	
	//Return the input stream to preserve the state
	return in;
}

//Remove failing grade students from the vector and return them
vector<Student_Info> extract_failures(vector<Student_Info>& students)
{
	vector<Student_Info> fails;

	//Loop through all students
	vector<Student_Info>::iterator iter = students.begin();
	while(iter != students.end())
	{
		//When we find one with a failing grade
		if (fgrade(*iter))
		{
			//Add to the fails vector
			fails.push_back(*iter);
			//And remove from the students vector
			iter = students.erase(iter);
		}
		//Only advance i when we reach a record we don't remove
		else
		{
			iter++;
		}
	}
	return fails;
}
