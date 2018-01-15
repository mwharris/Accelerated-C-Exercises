#include "stdafx.h"
#include <algorithm>

#include "ExtractDidnt.h"

using std::stable_partition;

//Look for a 0 in the student's HW grades.  If none are found, they did all HW.
bool did_all_hw(const Student_Info& s)
{
	return (find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
}

Student_Group extract_didnt(Student_Group& students)
{
	Student_Group didnts;

	//Partition passing and failing grades in the student group, returning the location of the partition
	Student_Group::iterator iter = stable_partition(students.begin(), students.end(), did_all_hw);
	//Create a new Student_Group in the range of the fails
	didnts = Student_Group(iter, students.end());
	//Erase all elements in the failing range
	students.erase(iter, students.end());

	return didnts;
}