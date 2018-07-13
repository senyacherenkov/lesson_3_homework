#include "filter_helper.h"
#include <cstring>
#include <algorithm>
#include <tuple>

std::string showIp(std::vector<std::string> & input)
{
    std::string rIpStr;
    bool isNotFirstPart = false;
    for (auto & ip_part: input)
    {
        if (isNotFirstPart)
        {
            rIpStr.push_back('.');
            std::cout << ".";
        }

        isNotFirstPart = true;
        rIpStr.append(ip_part);
        std::cout << ip_part;
    }
    std::cout << std::endl;
    return rIpStr;
}

void showList(std::vector<std::vector<std::string> > &input)
{
    for (auto & ip: input)
    {
        showIp(ip);
    }
}

std::vector<std::string> filter(std::vector<std::vector<std::string> >& input, const char *byte1, const char *byte2)
{
    std::vector<std::string> rVecStr;
    for (auto & ip: input)
    {
        if(byte2)
        {
            if ((strcmp(ip.at(0).c_str(), byte1) != 0) || (strcmp(ip.at(1).c_str(), byte2) != 0))
                continue;
        }
        else
        {
            if(strcmp(ip.at(0).c_str(), byte1) != 0)
                continue;
        }

        rVecStr.push_back(showIp(ip));
    }
    return rVecStr;
}

std::vector<std::string> filter_any(std::vector<std::vector<std::string> > &input, const char *byte1)
{
    std::vector<std::string> rVecStr;
    for (auto & ip: input)
    {
        bool isByteFounded = false;
        for (auto& ip_part: ip)
        {
            if (strcmp(ip_part.c_str(), byte1) == 0)
                isByteFounded = true;
        }

        if (isByteFounded)
            rVecStr.push_back(showIp(ip));
    }
    return rVecStr;
}

void lexicographRevSort(std::vector<std::vector<std::string> > &input)
{
    std::sort(input.rbegin(), input.rend(),[](const std::vector<std::string> & lhs,
                                               const std::vector<std::string>& rhs)
                                               {
                                                    return std::make_tuple(std::stoi(lhs.at(0)), std::stoi(lhs.at(1)), std::stoi(lhs.at(2)), std::stoi(lhs.at(3))) <
                                                        std::make_tuple(std::stoi(rhs.at(0)), std::stoi(rhs.at(1)), std::stoi(rhs.at(2)), std::stoi(rhs.at(3)));
                                               });
}
