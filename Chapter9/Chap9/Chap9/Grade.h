#ifndef GRADE_H
#define GRADE_H

#include <vector>
#include "Student_Info.h"

const double midtermPerc = 0.2;
const double finalPerc = 0.4;
const double homeworkPerc = 0.4;

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
//double grade(const Student_Info& s);

#endif // !GRADE_H