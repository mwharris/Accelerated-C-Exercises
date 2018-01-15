#include "stdafx.h"
#include <stdexcept>
#include <algorithm>

#include "ExtractFailures.h"
#include "Grade.h"

using std::list;
using std::domain_error;
using std::sort;

//Remove failing grade students from the list and return them
/*Student_Group extract_failures(Student_Group& students)
{
	Student_Group fails;

	//Loop through all students
	Student_Group::iterator iter = students.begin();
	while (iter != students.end())
	{
		//When we find one with a failing grade
		if (fgrade(*iter))
		{
			//Add to the fails list
			fails.push_back(*iter);
			//And remove from the students list
			iter = students.erase(iter);
		}
		//Only advance i when we reach a record we don't remove
		else
		{
			iter++;
		}
	}
	return fails;
}*/

void swap_students(Student_Group& students, Student_Group::size_type pass_index, Student_Group::size_type fail_index)
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

//Remove failing grade students from the list and return them
void extract_failures(Student_Group& students)
{
	//Sort the students by grade descending
	sort(students.begin(), students.end(), grade_compare);

	//Loop through all students
	Student_Group::size_type size = students.size() - 1;
	Student_Group::size_type first_fail_index = 0;
	for(Student_Group::size_type i = size; i > 0; i--)
	{
		//Find the first passing grade
		if (!fgrade(students[i]))
		{
			first_fail_index = i + 1;
			break;
		}
	}

	//Resize the vector by the different between the size and the fail index
	students.resize((size - first_fail_index) + 1);
	first_fail_index = 0;
}