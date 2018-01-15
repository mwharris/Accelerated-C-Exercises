#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <vector>
#include <string>
#include <iostream>

#include "Student_Group.h"
#include "Student_Info.h"

double gen_analysis(const Student_Group& students, double aux(const Student_Info& s));
double median_analysis(const Student_Group& students);
void write_analysis(std::ostream& out, const std::string& name, double analysis(const Student_Group& students, double aux(const Student_Info& students)),
	const Student_Group& did, const Student_Group& didnt, double aux(const Student_Info& students));
double average_analysis(const Student_Group& students);
double optimistic_median_analysis(const Student_Group& students);

#endif // !ANALYSIS_H