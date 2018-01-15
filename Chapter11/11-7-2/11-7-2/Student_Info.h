#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <string>
#include <vector>
#include <iostream>

class Student_Info {
public:
	//Constructors
	Student_Info();
	Student_Info(std::istream&);
	~Student_Info();

	//Copy Constructor
	Student_Info(const Student_Info& s);

	//Assignment Operator
	Student_Info& operator=(const Student_Info& rhs)
	{
		//Make sure we aren't assigning a variable to itself
		if (this != &rhs)
		{
			clone(rhs);
		}
		return *this;
	}

	//Member functions
	std::istream& read(std::istream& in);

	//Getters and Setters
	std::string get_name() const { return name; }
	double get_final_grade() const { return final_grade; }

private:
	std::string name;
	double midterm, final, final_grade;

	void clone(const Student_Info& s)
	{
		final = s.final;
		final_grade = s.final_grade;
		midterm = s.midterm;
		name = s.name;
	}
};

bool compare(const Student_Info& a, const Student_Info& b);

#endif // !STUDENT_INFO_H