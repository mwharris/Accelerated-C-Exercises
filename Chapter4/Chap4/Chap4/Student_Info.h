#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <string>
#include <vector>
#include <iostream>

struct Student_Info {
	std::string name;
	double final;
	char letter_grade;
};

bool compare(const Student_Info& a, const Student_Info& b);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);
std::istream& read(std::istream& in, Student_Info& s);
char get_letter_grade(double grade);

#endif // !STUDENT_INFO_H