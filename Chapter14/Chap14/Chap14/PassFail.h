#ifndef PASS_FAIL_H
#define PASS_FAIL_H

#include "Core.h"

class PassFail : public Core
{
public:
	//Constructors
	PassFail();
	PassFail(std::istream& in);

	//Member functions
	std::istream& read(std::istream&);
	double get_final_grade() const;
	std::string get_letter_grade() const;

	bool valid() const { 
		return true; 
	}

protected:
	virtual PassFail* clone() const { return new PassFail(*this); }

private:
	bool didHw = false;

};

#endif // !PASS_FAIL_H