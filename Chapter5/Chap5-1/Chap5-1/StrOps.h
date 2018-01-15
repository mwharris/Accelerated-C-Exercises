#ifndef STR_OPS_H
#define STR_OPS_H

#include <string>
#include <vector>

std::string to_lower_case(std::string s);
std::vector<std::string> split(const std::string& s);
std::string vec_to_str(const std::vector<std::string>& v);
std::vector<std::string> hcat(const std::vector<std::string>& left, const std::vector<std::string>& right);
std::vector<std::string> frame(const std::vector<std::string>& words, bool alignLeft);

#endif // !STR_OPS_H
