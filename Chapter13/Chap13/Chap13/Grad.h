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

private:
	double thesis;

};

#endif // !GRAD_H
