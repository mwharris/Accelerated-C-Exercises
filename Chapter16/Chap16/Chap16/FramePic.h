#ifndef FRAME_PIC_H
#define FRAME_PIC_H

#include <iostream>

#include "PicBase.h"
#include "Ptr.h"

class FramePic : public PicBase
{
	friend Picture frame(std::istream& in, const Picture& pic);

	//A pointer to our framed data
	Ptr<PicBase> p;

	//Variables for building our border
	char corner, ceiling, wall;

	//Constructor
	FramePic(const Ptr<PicBase>& pic, char c, char ceil, char w) : p(pic), corner(c), ceiling(ceil), wall(w) {}

	//Virtual function implementations.  4 is the frame padding
	wd_sz width() const { return p->width() + 4; }
	ht_sz height() const { return p->height() + 4; }
	void reframe(char cn, char ci, char w);
	void displayRow(std::ostream& os, ht_sz row, bool pad) const;

};

//Simply update the border characters of the FramePic
void FramePic::reframe(char cn, char ci, char w)
{
	corner = cn;
	ceiling = ci;
	wall = w;
	p->reframe(cn, ci, w);
}

//Display a given row of text stored in the vector of strings
void FramePic::displayRow(std::ostream& os, ht_sz row, bool doPad) const
{
	//Calculate and store height and width
	PicBase::ht_sz h = height();
	PicBase::wd_sz w = width();
	//Check if we are within range of our picture data
	if (row < h)
	{
		//Top or Bottom border: fill with *'s
		if (row == 0)
		{
			os << corner;
			os << Str(w - 2, ceiling);
			os << corner;
		}
		else if (row == h - 1)
		{
			os << corner;
			os << Str(w - 2, ceiling);
			os << corner;
		}
		//Insert spaces between the picture and top or bottom border
		else if (row == 1 || row == h - 2)
		{
			os << wall << " ";
			pad(os, 2, w - 2);
			os << " " << wall;
		}
		//Not inside any border; print the row and padding
		else
		{
			os << wall << " ";
			p->displayRow(os, row - 2, true);
			os << " " << wall;
		}
	}
	//Not within range: simply print spaces
	else if (doPad)
	{
		pad(os, 0, w);
	}
}

#endif // !FRAME_PIC_H