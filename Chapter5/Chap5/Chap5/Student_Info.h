#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <string>
#include <vector>
#include <iostream>
#include <list>

struct Student_Info {
	std::string name;
	double midterm;
	double final;
	double finalGrade;
	std::vector<double> homework;
};

bool compare(const Student_Info& a, const Student_Info& b);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);
std::istream& read(std::istream& in, Student_Info& s);
std::vector<Student_Info> extract_failures(std::vector<Student_Info>& students);

#endif // !STUDENT_INFO_H