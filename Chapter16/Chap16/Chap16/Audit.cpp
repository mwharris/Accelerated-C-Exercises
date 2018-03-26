#include "stdafx.h"

#include "Core.h"
#include "Audit.h"

Audit::Audit() {}

Audit::Audit(std::istream& in)
{
	read(in);
}

std::istream& Audit::read(std::istream& in)
{
	//Read the basic information for a student
	read_common(in);
	//Next read if the student did the HW
	return read_hw(in, homework);
}

//Return an invalid number since Audits don't get a grade
double Audit::get_final_grade() const
{
	return 0;
}

//Audit students don't receive a grade
Str Audit::get_letter_grade() const
{
	return "Audit";
}