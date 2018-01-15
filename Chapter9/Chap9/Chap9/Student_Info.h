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

	//Member functions
	bool valid() const { return !homework.empty(); }
	std::istream& read(std::istream& in);

	//Getters and Setters
	std::string get_name() const { return name; }
	double get_final_grade() const { return final_grade; }

private:
	//Data members
	std::string name;
	double midterm, final, final_grade;
	std::vector<double> homework;

	//Member functions
	std::istream& read_hw(std::istream& in, std::vector<double>& hw);
};

bool compare(const Student_Info& a, const Student_Info& b);
char get_letter_grade(double grade);

#endif // !STUDENT_INFO_H