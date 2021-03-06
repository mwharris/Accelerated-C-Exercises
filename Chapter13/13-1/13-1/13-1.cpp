#include "stdafx.h"
#include <iostream>

#include "Grad.h"
#include "Core.h"

using std::cout;
using std::endl;

/*
Output of the program should be:
1.
	Core::Core()
2.
	Core::Core()
	Grad::Grad()
3.
	Core::Core()
	Grad::Grad()
4.
	Core::Core(istream& in)
5.
	Core::Core()
	Grad::Grad(istream& in)
6.
	Core::Core()
	Grad::Grad(istream& in)
5.
	Core::Core(istream& in)
	Grad::Grad(istream& in)
6.
	Core::Core(istream& in)
	Grad::Grad(istream& in)
*/
void test_13_1()
{
	std::cout << "1." << std::endl;
	Core* c = new Core();

	std::cout << "2." << std::endl;
	Grad* g = new Grad();

	std::cout << "3." << std::endl;
	Core* cg = new Grad();

	std::cout << "4." << std::endl;
	Core* c2 = new Core(std::cin);

	std::cout << "5." << std::endl;
	Grad* g2 = new Grad(std::cin);

	std::cout << "6." << std::endl;
	Core* cg2 = new Grad(std::cin);

	std::cout << "7." << std::endl;
	Grad* g3 = new Grad(std::cin, 1.0);

	std::cout << "8." << std::endl;
	Core* cg3 = new Grad(std::cin, 2.0);
}

/*
Output for this test should be:
1. 
	Core::Core()
	Core::Core()
	Grad::Grad()
2.
	Core::Core()
	Core::Core()
	Grad::Grad()
3.
	Core::get_final_grade()
	Core::get_name()
4.
	Grad::get_final_grade()
	Core::get_final_grade()
	Core::get_name()
5.
	Core::get_final_grade()
	Core::get_name()
6.
	Core::get_name()
	Grad::get_final_grade()
	Core::get_final_grade()
*/
void test_13_2()
{
	cout << endl << "1." << endl;
	Core* p1 = new Core;
	Core* p2 = new Grad;

	cout << endl << "2." << endl;
	Core s1;
	Grad s2;

	cout << endl << "3." << endl;
	p1->get_final_grade();
	p1->get_name();

	cout << endl << "4." << endl;
	p2->get_final_grade();
	p2->get_name();

	cout << endl << "5." << endl;
	s1.get_final_grade();
	s1.get_name();

	cout << endl << "6." << endl;
	s2.get_name();
	s2.get_final_grade();
}

int main()
{
	//test_13_1();
	test_13_2();
    return 0;
}

