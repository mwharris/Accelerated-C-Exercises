#ifndef CORE_H
#define CORE_H

#include <string>
#include <vector>
#include <iostream>

class Core {

	friend class Student_Info;

public:
	//Constructors and Destructors
	Core();
	Core(std::istream&);
	virtual ~Core();

	//Member functions
	virtual std::istream& read(std::istream& in);
	virtual double get_final_grade() const;
	virtual std::string get_letter_grade() const;
	
	virtual bool valid() const { 
		return !homework.empty(); 
	}

	//Getters and Setters
	std::string get_name() const;

	virtual Core* clone() const { return new Core(*this); }

protected:
	//Member functions
	std::istream& read_common(std::istream& in);
	std::istream& read_hw(std::istream& in, std::vector<double>& hw);
	double midterm, final;
	std::vector<double> homework;
	std::string get_letter_grade_helper(double grade) const;

private:
	//Data members
	std::string name;

};

char get_letter_grade(double grade);

#endif // !CORE_H