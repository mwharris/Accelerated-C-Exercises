#ifndef GRADE_H
#define GRADE_H

#include <vector>
#include <list>
#include "Student_Info.h"

const double midtermPerc = 0.2;
const double finalPerc = 0.4;
const double homeworkPerc = 0.4;

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_Info& s);
double fgrade(const Student_Info& s);
double pgrade(const Student_Info& s);
double average_hw(const std::vector<double>& grades);

#endif // !GRADE_H