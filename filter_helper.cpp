#include "filter_helper.h"
#include <cstring>
#include <algorithm>
#include <tuple>

namespace filtering {

std::string showAndGetIp(const std::vector<std::string> & input)
{
    std::string rIpStr;

    rIpStr.append(input.at(0));
    std::cout << rIpStr;

    for(std::vector<std::string>::const_iterator ip_part = input.cbegin() + 1; ip_part != input.cend(); ++ip_part)
    {
        rIpStr.push_back('.');
        std::cout << ".";

        rIpStr.append(*ip_part);
        std::cout << *ip_part;
    }
    std::cout << std::endl;
    return rIpStr;
}

void showList(const addressList& input)
{
    for (auto & ip: input)
    {
        showAndGetIp(ip);
    }
}

std::vector<std::string> filter(const addressList& input, const char *byte1, const char *byte2)
{
    std::vector<std::string> rVecStr;
    for (auto & ip: input)
    {
        if(byte2)
        {
            if ((std::strcmp(ip.at(0).c_str(), byte1) != 0) || (std::strcmp(ip.at(1).c_str(), byte2) != 0))
                continue;
        }
        else
        {
            if(std::strcmp(ip.at(0).c_str(), byte1) != 0)
                continue;
        }

        rVecStr.push_back(showAndGetIp(ip));
    }
    return rVecStr;
}

std::vector<std::string> filter_any(const addressList& input, const char *byte1)
{
    std::vector<std::string> rVecStr;
    for (auto & ip: input)
    {
        bool isByteFounded = false;
        for (auto& ip_part: ip)
        {
            if (std::strcmp(ip_part.c_str(), byte1) == 0)
                isByteFounded = true;
        }

        if (isByteFounded)
        {
            std::string foundedStr = showAndGetIp(ip);
            rVecStr.push_back(foundedStr);
        }
    }
    return rVecStr;
}

bool ip_compare(const std::string& lhs, const std::string& rhs)
{
    if(lhs.size() == rhs.size())
    {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    else
    {
        return lhs.size() < rhs.size();
    }
}

void lexicographRevSort(addressList& input)
{
    std::sort(input.rbegin(), input.rend(),[](const std::vector<std::string> & lhs,
              const std::vector<std::string>& rhs)
    {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), ip_compare);
    });
}



}


