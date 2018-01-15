#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Index.h"
#include "StrOps.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::getline;
using std::sort;

typedef string::size_type str_sz;

//Read in all line articles
vector<string> read_lines()
{
	vector<string> ret;

	cout << "Please enter the articles followed by end-of-file: ";

	string line;
	while (getline(cin, line))
	{
		ret.push_back(line);
	}
	cin.clear();

	return ret;
}

void print_permute_index(const vector<Index>& indices, const vector<string>& lines)
{
	//Create left and right blocks for printing
	vector<string> left_block, right_block;
	create_blocks(indices, lines, left_block, right_block);

	//Frame both vectors
	left_block = frame(left_block, false);
	right_block = frame(right_block, true);

	//Horizontally concatenate the two vectors
	vector<string> print = hcat(left_block, right_block);

	//Print the concatenated blocks
	for (vector<string>::const_iterator it = print.begin(); it < print.end(); it++)
	{
		cout << *it << endl;
	}
}

int main()
{
	//Read in all our line articles
	vector<string> lines = read_lines();

	//Create the rotations
	vector<Index> indices;
	create_permuted_index(lines, indices);

	//Sort the rotations
	sort(indices.begin(), indices.end(), compare_indices);

	//Display our results
	print_permute_index(indices, lines);

    return 0;
}

