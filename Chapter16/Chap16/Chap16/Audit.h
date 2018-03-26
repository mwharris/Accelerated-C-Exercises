#ifndef AUDIT_H
#define AUDIT_H

#include "Core.h"

class Audit : public Core
{
public:
	Audit();
	Audit(std::istream& in);

	std::istream& read(std::istream& in);
	double get_final_grade() const;
	Str get_letter_grade() const;

	bool valid() const {
		return true;
	}

protected:
	virtual Audit* clone() const { return new Audit(*this); }

};

#endif // !AUDIT_H
