#include "stdafx.h"

#include "Rotate.h"

using std::string;
using std::vector;

vector<string> rotate_line(const vector<string>& line)
{
	typedef vector<string>::size_type vec_sz;
	vector<string> ret;
	
	vec_sz size = line.size();
	for (vec_sz i = 0; i < size; i++)
	{
		if (i + 1 < size)
		{
			ret.push_back(line[i + 1]);
		}
		else
		{
			ret.push_back(line[0]);
		}
	}

	return ret;
}