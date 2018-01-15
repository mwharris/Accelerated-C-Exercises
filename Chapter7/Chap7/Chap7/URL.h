#ifndef URL_H
#define URL_H

#include <string>
#include <vector>

bool not_url_char(char c);
std::string::const_iterator url_beg(std::string::const_iterator begin, std::string::const_iterator end);
std::string::const_iterator url_end(std::string::const_iterator begin, std::string::const_iterator end);
std::vector<std::string> find_urls(const std::string& s);

#endif // !URL_H
