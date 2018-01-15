#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::streamsize;
using std::setprecision;

typedef vector<double>::size_type vec_sz;

int main()
{
	//Get the users's name
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	//Get the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	//Prompt the user for homeworks grades
	cout << "Enter all homework grades, followed by end-of-file: ";
	//Read the list until we hit an end-of-file
	vector<double> homework;
	double x;
	while (cin >> x)
	{
		homework.push_back(x);
	}

	//Make sure grades were actually entered
	vec_sz size = homework.size();
	if (size == 0)
	{
		cout << "You must enter your grades. Please try again.";
		return 1;
	}

	//Sort the grades
	sort(homework.begin(), homework.end());

	//Compute the median
	vec_sz mid = size / 2;
	double median;
	if (mid % 2 == 0)
	{
		median = ((homework[mid - 1] + homework[mid + 1]) / 2);
	}
	else
	{
		median = homework[mid];
	}

	//Compute the final grade and print
	streamsize prec = cout.precision();
	double finalGrade = (0.2 * midterm) + (0.4 * final) + (0.4 * median);
	cout << "Your final grade is: " << setprecision(3) << finalGrade << setprecision(prec) << std::endl;

    return 0;
}

