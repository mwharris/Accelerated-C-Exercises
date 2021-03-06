#include "stdafx.h"

#include <map>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

#include "Vec.h"
#include "Str.h"
#include "Student_Info.h"
#include "Picture.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::domain_error;
using std::sort;
using std::max;
using std::streamsize;
using std::setprecision;
using std::map;

typedef Vec<Student_Info>::size_type vec_sz;

const size_t minPadding = 5;

int main()
{
	Vec<Student_Info> students;
	size_t maxLengthName = 0;

	//Read in all student information
	Student_Info record;
	while (record.read(cin))
	{
		//Add this record to our list of records
		students.push_back(record);
		//Also find the longest student name
		maxLengthName = max(maxLengthName, record.get_name().size());
	}
	cin.clear();

	//Sort the array of students alphabetically
	sort(students.begin(), students.end(), Student_Info::compare);

	//Create a histogram using the student data
	Picture hist = histogram(students);
	cout << frame(cin, hist) << endl;

	return 0;
}