#include "stdafx.h"
#include <stdexcept>

#include "Student_Info.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::domain_error;

//Default constructor
Student_Info::Student_Info() : cp(0) {}

//Initialize constructor
Student_Info::Student_Info(istream& is) : cp(0) 
{
	read(is);
}

//Function to read in either a Core or Grad from input stream
istream& Student_Info::read(istream& is)
{
	//Prompt the user for either a U or G representing the type of object they are creating
	char ch;
	cout << "Enter 'U' for Undergrad, 'G' for Graduate, 'P' for Pass/Fail, or 'A' fo Audit.  Enter Ctrl+Z to exit:" << endl;
	is >> ch;
	//Create the object based on user input, calling the correct constructor
	if (ch == 'G')
	{
		//RHS allocates a new Core object and returns a Core* using the Core constructor.
		//Since we are assigning, the Ptr<T> assignment operator is called.
		//However the assignment operator takes a Handle not a Core* so a conversion is needed. (the Handle<T>(T*) constructor is called).
		//The Handle<T>(T*) constructor takes the Core* and returns a Handle<Core> which then goes to the assignment operator.
		//Then the assignment operator is called and takes the appropriate actions.
		cp = new Grad(is);
	}
	else if (ch == 'P')
	{
		cp = new PassFail(is);
	}
	else if (ch == 'A')
	{
		cp = new Audit(is);
	}
	else
	{
		cp = new Core(is);
	}
	return is;
}

Str Student_Info::get_name() const
{
	//Forward work to underlying object if one exists
	if (cp) { return cp->get_name(); }
	//Otherwise throw a runtime error
	else { throw std::runtime_error("Uninitialized Student_Info!"); }
}

double Student_Info::get_final_grade() const
{
	//Forward work to underlying object if one exists
	if (cp) { return cp->get_final_grade(); }
	//Otherwise throw a runtime error
	else { throw std::runtime_error("Uninitialized Student_Info!"); }
}

Str Student_Info::get_letter_grade() const
{
	//Forward work to either Grad or Core function
	if (cp) { return cp->get_letter_grade(); }
	//Otherwise throw an error
	else { throw std::runtime_error("Uninitialized Student_Info!"); }
}

bool Student_Info::valid() const
{
	//Forward work to either Grad or Core function
	if (cp) { return cp->valid(); }
	//Otherwise throw an error
	else { throw std::runtime_error("Uninitialized Student_Info!"); }
}