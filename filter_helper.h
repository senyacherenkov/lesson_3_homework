#include <iostream>
#include <vector>
#include <string>

void lexicographRevSort(std::vector<std::vector<std::string> >& input);
void showList(std::vector<std::vector<std::string> >& input);
std::string showIp(std::vector<std::string> & input);
std::vector<std::string> filter(std::vector<std::vector<std::string> >& input, const char* byte1, const char* byte2 = nullptr);
std::vector<std::string> filter_any(std::vector<std::vector<std::string> >& input, const char* byte1);
