#ifndef PIC_BASE_H
#define PIC_BASE_H

//Forward class declaration needed because PicBase and Picture refer to each other.
//PicBase refers to Picture in that Picture class is a friend as well as the operator<< overload in Picture.
//Picture refers to PicBase in that it has a Ptr<PicBase> member.
class Picture;

class PicBase
{
	friend class Picture;
	friend class VCatPic;
	friend class HCatPic;
	friend class FramePic;
	friend std::ostream& operator<<(std::ostream&, const Picture&);

public:
	//Typedefs that will be inherited by derived classes
	typedef Vec<Str>::size_type ht_sz;
	typedef Str::size_type wd_sz;

	//Virtual destructor so derived classes can implement their own
	virtual ~PicBase() {}

private:
	//Interface functions that will be implemented in derived classes
	virtual ht_sz height() const = 0;
	virtual wd_sz width() const = 0;
	virtual void reframe(char, char, char) = 0;
	virtual void displayRow(std::ostream& os, ht_sz row, bool pad) const = 0;

protected:
	//Helper function to apply a padding after a string is written to output stream.
	//This function is static in order to only associate it with this base class.
	//This is to allow for the possibility that derived classes might want their own pad function.
	//Making this static allows those classes to define their own pad function in the scope of only that class.
	static void pad(std::ostream& os, wd_sz start, wd_sz end)
	{
		while (start != end)
		{
			os << " ";
			start++;
		}
	}

};

#endif // !PIC_BASE_H