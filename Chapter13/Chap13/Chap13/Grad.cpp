#include "stdafx.h"
#include <iostream>
#include <algorithm>

#include "Grad.h"

using std::istream;
using std::min;

//Default Constructor
Grad::Grad() : thesis(0) {}

//Constructor given an input stream
Grad::Grad(istream& in)
{
	//Read values from input stream to initialize members
	read(in);
}

istream& Grad::read(istream& in)
{
	//First read common student information (name, midterm grade, final grade)
	read_common(in);
	//Then read thesis grade (only available to Grad students)
	in >> thesis;
	//Finally read in all homework grades
	read_hw(in, homework);
	//Return the istream to preserve state
	return in;
}

//Calculate the grade for this Grad student
double Grad::get_final_grade() const
{
	//Find the minimum between the core grades and the thesis grade.
	//Core scope is required in order to not re-call Grad's get_final_grade() function.
	return min(Core::get_final_grade(), thesis);
}