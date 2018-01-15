#include "stdafx.h"
#include <algorithm>

#include "Index.h"
#include "Rotate.h"
#include "StrOps.h"

using std::vector;
using std::string;

//Create Index objects for each permuted index
void create_permuted_index(const vector<string>& lines, vector<Index>& indices)
{
	typedef vector<string>::size_type vec_sz;

	//Iterate through all lines that were entered
	vec_sz lineSize = lines.size();
	for (vec_sz i = 0; i < lineSize; i++)
	{
		//Split this line up into words
		vector<string> words = split(lines[i]);

		//Create a copy vector to rotate, leaving the original unaffected
		vector<string> rot_words = words;

		//Iterate through each word
		vec_sz wordSize = words.size();
		for (vec_sz j = 0; j < wordSize; j++)
		{
			//Create an Index for each word in the line
			Index id;
			id.line_number = i;
			id.line_index = j;
			id.original_line = lines[i];
			id.rotated_line = vec_to_str(rot_words);
			id.line_elements = words;
			indices.push_back(id);

			//Rotate the words
			rot_words = rotate_line(rot_words);
		}
	}
}

//Custom comparator for our Index objects
bool compare_indices(const Index& a, const Index& b)
{
	return to_lower_case(a.rotated_line) < to_lower_case(b.rotated_line);
}

//Create a vector of strings either left of the index or right of the index
void create_blocks(const vector<Index>& indices, const vector<string>& lines, 
								vector<string>& left_block, vector<string>& right_block)
{
	//Loop through all indices
	for (vector<Index>::const_iterator it = indices.begin(); it < indices.end(); it++)
	{
		//Get the split words for this index's line
		vector<string> words = it->line_elements;
		
		//Loop through each word
		string left, right;
		vector<string>::size_type size = words.size();
		for (vector<string>::size_type i = 0; i < size; i++)
		{
			//Create string to the left of the index 
			if (i < it->line_index)
			{
				if (i + 1 < it->line_index)
				{
					left += words[i] + " ";
				}
				else 
				{
					left += words[i];
				}
			}
			//Create string to the right of the index including the index itself
			else if (i >= it->line_index)
			{
				if (i + 1 < size)
				{
					right += words[i] + " ";
				}
				else
				{
					right += words[i];
				}
			}
		}

		//Add left and right strings to corresponding vector
		left_block.push_back(left);
		right_block.push_back(right);
	}
}
