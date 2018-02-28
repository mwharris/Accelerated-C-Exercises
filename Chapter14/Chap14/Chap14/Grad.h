#ifndef GRAD_H
#define GRAD_H

#include "Core.h"

class Grad : public Core
{
public:
	//Constructors
	Grad();
	Grad(std::istream&);

	//Member functions
	std::istream& read(std::istream&);
	double get_final_grade() const;
	std::string get_letter_grade() const;
	
	bool valid() const { 
		return !homework.empty() && thesis > 0; 
	}

protected:
	virtual Grad* clone() const { return new Grad(*this); }

private:
	double thesis;

};

#endif // !GRAD_H
