#ifndef NEW_FUNCTIONS_H
#define NEW_FUNCTIONS_H

#include <vector>
#include <string>

std::string::size_type width_new(const std::vector<std::string> v);
std::vector<std::string> frame_new(const std::vector<std::string>& words);
std::vector<std::string> hcat_new(const std::vector<std::string>& left, const std::vector<std::string>& right);

#endif // !NEW_FUNCTIONS_H
