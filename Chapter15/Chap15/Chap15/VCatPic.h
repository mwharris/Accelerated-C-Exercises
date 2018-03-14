#ifndef VCAT_PIC_H
#define VCAT_PIC_H

#include "PicBase.h"
#include "Ptr.h"

class VCatPic : public PicBase
{
	friend Picture vcat(const Picture& top, const Picture& bottom);

	//Pointers to our top and bottom pictures
	Ptr<PicBase> top;
	Ptr<PicBase> bottom;

	//Constructor
	VCatPic(const Ptr<PicBase>& t, const Ptr<PicBase>& b) : top(t), bottom(b) {}

	//Virtual function implementations
	wd_sz width() const { return std::max(top->width(), bottom->width()); }
	ht_sz height() const { return top->height() + bottom->height(); }
	void reframe(char, char, char);
	void displayRow(std::ostream& os, ht_sz row, bool pad) const;
};

//Simply call reframe in our left and right pics
void VCatPic::reframe(char cn, char ci, char w)
{
	top->reframe(cn, ci, w);
	bottom->reframe(cn, ci, w);
}

//Display a given row of text stored in the vector of strings
void VCatPic::displayRow(std::ostream& os, ht_sz row, bool doPad) const
{
	//Keep track of the width of whatever row we display
	PicBase::wd_sz w = 0;
	//If we are requesting a row within the top section
	if (row < top->height())
	{
		//Delegate work further down the inheritance tree.
		//This should eventually hit a StringPic.
		top->displayRow(os, row, doPad);
		w = top->width();
	}
	//If we are requesting a row within the bottom section
	else if (row < height())
	{
		//Delegate work further down the inheritance tree.
		//This should eventually hit a StringPic.
		bottom->displayRow(os, row - top->height(), doPad);
		w = bottom->width();
	}
	//Fill in padding between our displayed row and maximum width
	if (doPad)
	{
		pad(os, w, width());
	}
}

#endif // !VCAT_PIC_H