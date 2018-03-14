#ifndef PICTURE_H
#define PICTURE_H

#include "Str.h"
#include "PicBase.h"

class Picture
{
	friend Picture frame(std::istream& in, const Picture& pic);
	friend Picture hcat(const Picture& left, const Picture& right);
	friend Picture vcat(const Picture& top, const Picture& bottom);
	friend std::ostream& operator<<(std::ostream&, const Picture&);

public:
	//Conversion Constructor: converts a Vec of Str representing a picture to a Picture using StringPic
	Picture(const Vec<Str>& = Vec<Str>());
	Picture reframe(std::istream& in);

private:
	//Conversion Constructor that builds a Picture around a PicBase*
	Picture::Picture(PicBase* ptr) : pb(ptr) {}

	Ptr<PicBase> pb;
};

//Non-member functions for manipulating picture data
Picture frame(std::istream& in, const Picture& pic);
Picture hcat(const Picture& left, const Picture& right);
Picture vcat(const Picture& top, const Picture& bottom);
std::ostream& operator<<(std::ostream&, const Picture&);

#endif // !PICTURE_H
