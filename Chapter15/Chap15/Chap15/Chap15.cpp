#include "stdafx.h"

#include <iostream>
#include "Picture.h"

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

void readLines(istream& in, ostream& out, Vec<Str>& vec)
{
	Str s;
	out << "Enter lines for the picture: " << endl;
	while (getline(in, s)) {
		vec.push_back(s);
	}
	in.clear();
}

int main()
{
	//Fill our Vec with user input
	Vec<Str> vec;
	readLines(cin, cout, vec);

	//Simple display of the data line-by-line
	Picture p = vec;
	cout << p << endl;

	//Display the data in padded frame
	Picture f = frame(cin, p);
	cout << f << endl;
	
	//Horizontal concatenation of the data + framed data
	Picture h = hcat(p, f);
	cout << h << endl;

	//Vertical concatenation of the framed data + (data + framed data)
	Picture v = vcat(f, h);
	cout << v << endl;

	//Test our reframe function
	v.reframe(cin);

	//Will produce the output show below where TEST is the Vec text
	Picture big = frame(cin, hcat(v, vcat(h, f)));
	cout << big << endl;
	/*
	  ****************************
	  * ********	    ******** *
	  * *	   *		*	   * *
	  * * TEST *	TEST* TEST * *
	  * *      *		*      * *
	  * ********		******** *
	  *     ****************     *
	  * 	*	   **	   *	 *
	  * TEST* TEST ** TEST *	 *
	  * 	*      **      *	 *
	  * 	****************	 *
	  ****************************
	*/

	//Will produce the above with all *'s replaces with user input
	big.reframe(cin);
	cout << big << endl;

	return 0;
}