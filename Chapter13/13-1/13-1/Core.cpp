#include "stdafx.h"
#include <stdexcept>
#include <string>

#include "Core.h"
#include "Grade.h"

using std::cin;
using std::cout;
using std::vector;
using std::istream;
using std::domain_error;
using std::string;

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
bool compare(const Core& a, const Core& b)
{
	return a.get_final_grade() < b.get_final_grade();
}
//Pointer version of custom comparator
bool compare_core_ptrs(const Core* a, const Core* b)
{
	return compare(*a, *b);
}

//Default constructor
Core::Core() : midterm(0), final(0) 
{
	std::cout << "Core::Core()" << std::endl;
}

//Initalizer constructor
Core::Core(istream& in)
{
	std::cout << "Core::Core(istream& in)" << std::endl;
	//read(in);
}

//Destructor
Core::~Core() {}

//Read a list of homework grades into a student's homework vector
istream& Core::read_hw(istream& in, vector<double>& hw)
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
	std::cout << "Core::get_final_grade()" << std::endl;
	return grade(midterm, final, homework);
}

//Getters for private and protected members
string Core::get_name() const
{
	std::cout << "Core::get_name()" << std::endl;
	return name;
}