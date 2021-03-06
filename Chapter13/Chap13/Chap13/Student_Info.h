#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <string>
#include <vector>
#include <iostream>

#include "Core.h"
#include "Grad.h"
#include "PassFail.h"
#include "Audit.h"

class Student_Info {
public:
	Student_Info();
	Student_Info(std::istream&);
	Student_Info(const Student_Info& s);
	~Student_Info();
	Student_Info& operator= (const Student_Info& s);

	std::istream& read(std::istream&);

	std::string get_name() const;
	double get_final_grade() const;
	bool valid() const;
	std::string get_letter_grade() const;

	//Static member function to compare two Student_Info object by name
	static bool compare(const Student_Info& a, const Student_Info& b)
	{
		return a.get_name() < b.get_name();
	}

private:
	Core* cp;

};


#endif // !STUDENT_INFO_H