#include "stdafx.h"

#include <iostream>
#include "Picture.h"
#include "FramePic.h"
#include "HCatPic.h"
#include "VCatPic.h"
#include "StringPic.h"

using std::istream;
using std::ostream;
using std::endl;

//Conversion Constructor that builds a Ptr<PicBase> around a StringPic Vec then builds a Picture around that
Picture::Picture(const Vec<Str>& v) : pb(new StringPic(v)) { }

//Frame a given picture
Picture frame(istream& in, const Picture& pic)
{
	//Read in special characters for the frame's ceiling, corners, and walls
	char corner, ceiling, wall;
	std::cout << "Please enter 4 variables for the borders (Corners, Ceilings, Walls): ";
	in >> corner >> ceiling >> wall;
	in.clear();
	//Create a new FramePic by passing the passed-in Picture's Ptr<PicBase>.
	//The new operator will yield a PicBase* since FramePic implements PicBase.
	//The PicBase* will be converted into a Picture using the conversion constructor.
	return new FramePic(pic.pb, corner, ceiling, wall);
}

//Horizontal concatenate two pictures
Picture hcat(const Picture& left, const Picture& right)
{
	return new HCatPic(left.pb, right.pb);
}

//Vertical concatenate two pictures
Picture vcat(const Picture& top, const Picture& bottom)
{
	return new VCatPic(top.pb, bottom.pb);
}

//Reframe a picture by swapping all frame characters with new ones
Picture Picture::reframe(std::istream& in)
{
	//Read in special characters for the frame's ceiling, corners, and walls
	char corner, ceiling, wall;
	std::cout << "Please enter 4 variables for the borders (Corners, Ceilings, Walls): ";
	in >> corner >> ceiling >> wall;
	in.clear();
	//Update all frames within this picture to use these new values
	pb->reframe(corner, ceiling, wall);
	return *this;
}

//Output operator overload to read a picture to the screen
ostream& operator<<(ostream& os, const Picture& pic) {
	for (PicBase::ht_sz i = 0; i != pic.pb->height(); ++i) {
		pic.pb->displayRow(os, i, false);
		os << endl;
	}
	return os;
}

//Create a histogram given a list of student info
Picture histogram(const Vec<Student_Info>& students)
{
	Picture names;
	Picture grades;
	for (Vec<Student_Info>::const_iterator it = students.begin(); it != students.end(); ++it)
	{
		names = vcat(names, Vec<Str>(1, it->get_name()));
		int numSymbols = it->get_final_grade() / 5;
		Str s = " " + Str(numSymbols, '=');
		grades = vcat(grades, Vec<Str>(1, s));
	}
	return hcat(names, grades);
}