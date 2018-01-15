#include "stdafx.h"
#include <stdexcept>
#include <algorithm>
#include <vector>

#include "ExtractFailures.h"
#include "Grade.h"

using std::list;
using std::domain_error;
using std::sort;
using std::stable_partition;
using std::vector;

void swap_students(vector<Student_Info>& students, vector<Student_Info>::size_type pass_index, vector<Student_Info>::size_type fail_index)
{
	if (fail_index < pass_index)
	{
		//Swap the passer and the failer
		Student_Info passer = students[pass_index];
		students[pass_index] = students[fail_index];
		students[fail_index] = passer;
	}
	else
	{
		throw domain_error("Y'all fucked up now");
	}
}

bool is_passing(const Student_Info& s)
{
	return s.get_final_grade() > 60;
}

//Extract student failures using algorithms instead of looping
vector<Student_Info> extract_fails(vector<Student_Info>& students)
{
	vector<Student_Info> fails;

	//Partition passing and failing grades in the student group, returning the location of the partition
	vector<Student_Info>::iterator iter = stable_partition(students.begin(), students.end(), is_passing);
	//Create a new Student_Group in the range of the fails
	fails = vector<Student_Info>(iter, students.end());
	//Erase all elements in the failing range
	students.erase(iter, students.end());

	return fails;
}