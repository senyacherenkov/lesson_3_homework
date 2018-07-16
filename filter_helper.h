#include <iostream>
#include <vector>
#include <string>

namespace filtering {

    using addressList = std::vector<std::vector<std::string>>;

    void lexicographRevSort(addressList& input);
    std::string showAndGetIp(const std::vector<std::string> & input);
    void showList(const addressList& input);
    std::vector<std::string> filter(const addressList& input, const char* byte1, const char* byte2 = nullptr);
    std::vector<std::string> filter_any(const addressList& input, const char* byte1);
}
