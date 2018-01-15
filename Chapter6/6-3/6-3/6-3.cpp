#include "stdafx.h"
#include <vector>
#include <algorithm>

using std::vector;
using std::copy;
using std::back_inserter;

int main()
{
	vector<int> u(10, 100);
	vector<int> v;
	copy(u.begin(), u.end(), back_inserter(v));
    return 0;
}

