#include "stdafx.h"
#include <stdexcept>

#include "Student_Info.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream;
using std::domain_error;

//Default constructor
Student_Info::Student_Info() : cp(0) {}

//Initialize constructor
Student_Info::Student_Info(istream& is) : cp(0) 
{
	read(is);
}

//Default Destructor
Student_Info::~Student_Info()
{
	delete cp;
}

//Copy Constructor
Student_Info::Student_Info(const Student_Info& s) : cp(0)
{
	//Simply clone the passed-in class if it has data
	if (s.cp) 
	{
		//Clone() is virtual and will call either Grad::clone or Core::clone
		cp = s.cp->clone();
	}
}

//Assignment Operator
Student_Info& Student_Info::operator= (const Student_Info& s)
{
	//Check that we aren't assigning ourself to ourself
	if (&s != this) 
	{
		//Destroy the values that are currently here
		delete cp;
		//Clone the assignor if data exists
		if (s.cp) 
		{
			//Call either Grad::clone or Core::clone
			cp = s.cp->clone();
		}
		//Otherwise just assign to 0
		else 
		{
			cp = 0;
		}
	}
	return *this;
}

//Function to read in either a Core or Grad from input stream
istream& Student_Info::read(istream& is)
{
	//Ensure we are reading into an empty object
	delete cp;
	//Prompt the user for either a U or G representing the type of object they are creating
	char ch;
	cout << "Enter 'U' or 'G' depending on student type.  Enter Ctrl+Z to exit:" << endl;
	is >> ch;
	//Create the object based on user input, calling the correct constructor
	if (ch == 'U') 
	{
		cp = new Core(is);
	}
	else if (ch == 'G')
	{
		cp = new Grad(is);
	}
	else
	{
		cp = 0;
	}
	return is;
}

std::string Student_Info::get_name() const
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

bool Student_Info::valid() const
{
	if (cp)
	{
		return cp->valid();
	}
	return false;
}