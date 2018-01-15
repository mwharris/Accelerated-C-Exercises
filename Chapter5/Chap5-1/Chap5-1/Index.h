#ifndef INDEX_H
#define INDEX_H

#include <string>
#include <vector>

struct Index {
	std::string original_line;
	std::string rotated_line;
	std::vector<std::string>::size_type line_number;
	std::string::size_type line_index;
	std::vector<std::string> line_elements;
};

void create_permuted_index(const std::vector<std::string>& lines, std::vector<Index>& indices);
bool compare_indices(const Index& a, const Index& b);
void create_blocks(const std::vector<Index>& indices, const std::vector<std::string>& lines,
			std::vector<std::string>& left_block, std::vector<std::string>& right_block);

#endif