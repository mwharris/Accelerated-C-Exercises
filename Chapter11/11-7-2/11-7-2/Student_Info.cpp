#include "stdafx.h"
#include <stdexcept>

#include "Student_Info.h"
#include "Grade.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream;
using std::domain_error;

//Custom comparator for Student Info objects
bool compare(const Student_Info& a, const Student_Info& b)
{
	return a.get_name() < b.get_name();
}

//Default constructor
Student_Info::Student_Info() : midterm(0), final(0), name("")
{

}

//Initalizer constructor
Student_Info::Student_Info(istream& in)
{
	read(in);
}

//Default Destructor
Student_Info::~Student_Info()
{
	midterm = final = final_grade = 0;
	name = "";
}

//Copy Constructor
Student_Info::Student_Info(const Student_Info& s)
{
	clone(s);
}

//Read all of a student's information from the input stream
istream& Student_Info::read(istream& in)
{
	//Read the first name, midterm, and final grades
	cout << "Please enter name, midterm, and final grades or end-of-file: ";
	cin >> name >> midterm >> final;
	//Grade the student's performance
	final_grade = ::grade(midterm, final);
	//Return the input stream to preserve the state
	return in;
}