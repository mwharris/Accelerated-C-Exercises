#ifndef CORE_H
#define CORE_H

#include <string>
#include <vector>
#include <iostream>

class Core {
public:
	//Constructors
	Core();
	Core(std::istream&);

	//Member functions
	virtual std::istream& read(std::istream& in);
	virtual double get_final_grade() const;
	bool valid() const { return !homework.empty(); }

	//Getters and Setters
	std::string get_name() const;

protected:
	//Member functions
	std::istream& read_common(std::istream& in);
	std::istream& read_hw(std::istream& in, std::vector<double>& hw);
	double midterm, final;
	std::vector<double> homework;

private:
	//Data members
	std::string name;

};

bool compare(const Core& a, const Core& b);
bool compare_core_ptrs(const Core* a, const Core* b);
char get_letter_grade(double grade);

#endif // !CORE_H