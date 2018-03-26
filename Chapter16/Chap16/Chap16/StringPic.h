#ifndef STRING_PIC_H
#define STRING_PIC_H

#include <algorithm>
#include "PicBase.h"

class StringPic : public PicBase
{
	friend class Picture;

	//The actual string data used in a picture
	Vec<Str> data;

	//Constructor
	StringPic(const Vec<Str>& v) : data(v) {}

	//Virtual function implementations
	ht_sz height() const { return data.size(); }
	wd_sz width() const;
	void reframe(char, char, char) {}
	void displayRow(std::ostream& os, ht_sz row, bool pad) const;

};

//Find the maximum length string inside our vector of strings
PicBase::wd_sz StringPic::width() const
{
	PicBase::wd_sz ret = 0;
	for (PicBase::ht_sz i = 0 ; i < height(); ++i)
	{
		ret = std::max(ret, data[i].size());
	}
	return ret;
}

//Display a given row of text stored in the vector of strings
void StringPic::displayRow(std::ostream& os, ht_sz row, bool doPad) const
{
	wd_sz start = 0;
	//Make sure we're not trying to print out of range
	if (row < height())
	{
		os << data[row];
		start = data[row].size();
	}
	//Apply a padding if needed
	if (doPad)
	{
		pad(os, start, width());
	}
}

#endif // !STRING_PIC_H