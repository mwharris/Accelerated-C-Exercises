#include "stdafx.h"
#include <iostream>
#include <string>

#include "Student_Group.h"
#include "Analysis.h"
#include "ExtractDidnt.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	Student_Group did, didnt, fail_did, fail_didnt;

	//Read in all student information
	Student_Info record;
	while (read(cin, record))
	{
		did.push_back(record);
	}

	//Extract students from the list/vector that didn't do all the hw
	didnt = extract_didnt(did);

	//Check if either of the list/vectors are empty
	if (did.empty())
	{
		cout << "No student did all of the homework!" << endl;
	}
	if (didnt.empty())
	{
		cout << "All students did their homework!" << endl;
	}

	//Extract all failures from both arrays
	fail_did = extract_fails_v2(did);
	fail_didnt = extract_fails_v2(didnt);

	//Execute and print the results of our analysis
	cout << string(30, '*') << endl;
	cout << "ANALYSIS" << endl;
	cout << string(30, '*') << endl;
	write_analysis(cout, "median", grade_aux, did, didnt);
	write_analysis(cout, "average", average_hw_grade, did, didnt);
	write_analysis(cout, "optimistic", optimistic_median, did, didnt);
	cout << string(30, '*') << endl;

    return 0;
}

