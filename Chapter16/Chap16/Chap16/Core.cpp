#include "stdafx.h"
#include <stdexcept>
#include <string>

#include "Core.h"
#include "Grade.h"

using std::cin;
using std::cout;
using std::istream;
using std::domain_error;
using std::string;

//Default constructor
Core::Core() : midterm(0), final(0) {}

//Initalizer constructor
Core::Core(istream& in)
{
	read(in);
}

//Destructor
Core::~Core() {}

//Read a list of homework grades into a student's homework vector
istream& Core::read_hw(istream& in, Vec<double>& hw)
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
istream& Core::read_common(istream& in)
{
	//Read the first name, midterm, and final grades
	cout << "Please enter name, midterm, and final grades or end-of-file: ";
	in >> name >> midterm >> final;
	//Return the input stream to preserve the state
	return in;
}

//Top read function to handle reading in all information 
//by calling helper functions defined above.
istream& Core::read(istream& in)
{
	//First read common student information (name, midterm, final)
	read_common(in);
	//Read in all homework grades
	read_hw(in, homework);
	//Return the input stream to preserve the state
	return in;
}

//Calculate the grade for this player using the values we've read
double Core::get_final_grade() const
{
	return grade(midterm, final, homework);
}

//Getters for private and protected members
Str Core::get_name() const
{
	return name;
}

Str Core::get_letter_grade_helper(double grade) const
{
	if (grade >= 97)
	{
		return "A+";
	}
	else if (grade >= 94)
	{
		return "A";
	}
	else if (grade >= 90)
	{
		return "A-";
	}
	else if (grade >= 87)
	{
		return "B+";
	}
	else if (grade >= 84)
	{
		return "B";
	}
	else if (grade >= 80)
	{
		return "B-";
	}
	else if (grade >= 77)
	{
		return "C+";
	}
	else if (grade >= 74)
	{
		return "C";
	}
	else if (grade >= 70)
	{
		return "C-";
	}
	else if (grade >= 60)
	{
		return "D";
	}
	else
	{
		return "F";
	}
}

Str Core::get_letter_grade() const
{
	return get_letter_grade_helper(get_final_grade());
}