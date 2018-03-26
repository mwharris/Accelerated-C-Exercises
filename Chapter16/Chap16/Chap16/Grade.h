#ifndef GRADE_H
#define GRADE_H

#include "Core.h"
#include "Vec.h"

const double midtermPerc = 0.2;
const double finalPerc = 0.4;
const double homeworkPerc = 0.4;

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const Vec<double>& hw);
double grade(double midterm, double final);

#endif // !GRADE_H