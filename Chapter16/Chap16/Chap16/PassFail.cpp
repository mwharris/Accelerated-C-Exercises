#include "stdafx.h"
#include <iostream>

#include "PassFail.h"
#include "Grade.h"

PassFail::PassFail() {}

PassFail::PassFail(std::istream& in)
{
	read(in);
}

std::istream& PassFail::read(std::istream& in)
{
	//Read in the basic information (name, midterm, final)
	read_common(in);
	//Finally read in all homework grades
	read_hw(in, homework);
	//Check if we did homework or not
	if (homework.size() > 0) 
	{
		didHw = true;
	}
	return in;
}

//Grade the student, don't count homework if none was done
double PassFail::get_final_grade() const
{
	if (didHw)
	{
		return grade(midterm, final, homework);
	}
	else 
	{
		return grade(midterm, final);
	}
}

Str PassFail::get_letter_grade() const
{
	if (get_final_grade() >= 60)
	{
		return "P";
	}
	else
	{
		return "F";
	}
}