#ifndef GRAD_H
#define GRAD_H

#include "Core.h"

class Grad : public Core
{
public:
	//Constructors
	Grad();
	Grad(std::istream&);
	Grad(std::istream&, double blah);

	//Member functions
	std::istream& read(std::istream&);
	double get_final_grade() const;

protected:
	virtual Grad* clone() const { return new Grad(*this); }

private:
	double thesis;

};

#endif // !GRAD_H
