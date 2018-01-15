#include "stdafx.h"
#include <vector>
#include <stdexcept>
#include "Grade.h"

using std::vector;
using std::domain_error;

//Calculate the median of the hw vector, then the final grade
double grade(double midterm, double final)
{
	return (midterm + final) / 2;
}