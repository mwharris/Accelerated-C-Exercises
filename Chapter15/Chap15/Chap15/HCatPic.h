#ifndef HCAT_PIC_H
#define HCAT_PIC_H

#include "PicBase.h"
#include "Ptr.h"

class HCatPic : public PicBase
{
	friend Picture hcat(const Picture& left, const Picture& right);

	//Pointers to our left and right pictures
	Ptr<PicBase> left;
	Ptr<PicBase> right;

	//Constructor
	HCatPic(const Ptr<PicBase>& l, const Ptr<PicBase>& r) : left(l), right(r) {}

	//Virtual function implementations
	wd_sz width() const { return left->width() + right->width(); }
	ht_sz height() const { return std::max(left->height(), right->height()); }
	void reframe(char, char, char);
	void displayRow(std::ostream& os, ht_sz row, bool pad) const;
};

//Simply call reframe in our left and right pics
void HCatPic::reframe(char cn, char ci, char w)
{
	left->reframe(cn, ci, w);
	right->reframe(cn, ci, w);
}

//Display a given row of text stored in the vector of strings
void HCatPic::displayRow(std::ostream& os, ht_sz row, bool doPad) const
{
	PicBase::ht_sz difference;
	Ptr<PicBase> smaller;
	Ptr<PicBase> larger;
	//If the left picture is greater than the right picture
	if (left->height() > right->height()) {
		//Calculate the difference between heights
		difference = left->height() - right->height();
		PicBase::ht_sz padding = difference / 2;
		//Display the current row of the left picture
		left->displayRow(os, row, doPad || row < right->height());
		//Display padding row for right picture on the first or last couple rows
		if (row < padding || row > right->height() + padding) {
			pad(os, 0, right->width());
		}
		//Display the normal row if not
		else {
			right->displayRow(os, row - padding, doPad);
		}
	}
	else {
		//Calculate the difference between heights
		difference = right->height() - left->height();
		PicBase::ht_sz padding = difference / 2;
		//Display padding row for right picture on the first or last couple rows
		if (row < padding || row > left->height() + padding - 1) {
			pad(os, 0, left->width());
		}
		//Display the normal row if not
		else {
			left->displayRow(os, row - padding, doPad || row < right->height());
		}
		//Display the current row of the left picture
		right->displayRow(os, row, doPad);
	}
}

#endif // !HCAT_PIC_H