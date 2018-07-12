// lesson_3.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <stdexcept>
// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
	std::vector<std::string> r;

	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);
	while (stop != std::string::npos)
	{
		r.push_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}

	r.push_back(str.substr(start));

	return r;
}

int main(int argc, char const *argv[])
{
	try
	{
		std::vector<std::vector<std::string> > ip_pool{ { "1", "10", "2", "1" },
														{ "1", "2", "3", "4" },
														{ "1", "2", "6", "1" }, 
														{ "70", "2", "6", "1" },
														{ "46", "70", "6", "1" },
														{ "46", "128", "6", "1" },
														{ "168", "56", "46", "1" }, };
		/*std::vector<std::tuple<std::string, std::string, std::string, std::string> > ip_pool2;
		ip_pool2.push_back(std::make_tuple("1", "10", "2", "1"));
		ip_pool2.push_back(std::make_tuple("1", "2", "3", "4"));
		ip_pool2.push_back(std::make_tuple("1", "2", "6", "1"));*/

		/*{ { "1", "10", "2", "1" },
		{ "1", "2", "3", "4" },
		{ "1", "2", "6", "1" }, };*/

		//for (std::string line; std::getline(std::cin, line);)
		//{
		//	std::vector<std::string> v = split(line, '\t');
		//	ip_pool.push_back(split(v.at(0), '.'));
		//}9-

		//// TODO reverse lexicographically sort

		

		std::sort(ip_pool.rbegin(), ip_pool.rend(),[](const std::vector<std::string> & lhs,
														const std::vector<std::string>& rhs)
													{
															return std::make_tuple(std::stoi(lhs.at(0)), std::stoi(lhs.at(1)), std::stoi(lhs.at(2)), std::stoi(lhs.at(3))) <
																std::make_tuple(std::stoi(rhs.at(0)), std::stoi(rhs.at(1)), std::stoi(rhs.at(2)), std::stoi(rhs.at(3)));
													});

		for (std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
		{
			for (std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
			{
				if (ip_part != ip->cbegin())
				{
					std::cout << ".";

				}
				std::cout << *ip_part;
			}
			std::cout << std::endl;
		}

		// TODO filter by first byte and output
		for (std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
		{
			std::string strPart(*ip->cbegin());
			if(strcmp(strPart.c_str(), "1") != 0)
				continue;

			for (std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
			{
				if (ip_part != ip->cbegin())
				{
					std::cout << ".";
				}
				std::cout << *ip_part;
			}
			std::cout << std::endl;
		}

		// TODO filter by first and second bytes and output
		for (std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
		{
			std::string strPart1(*ip->cbegin());
			std::string strPart2(*(ip->cbegin() + 1));
			if ((strcmp(strPart1.c_str(), "46") != 0) || (strcmp(strPart2.c_str(), "70") != 0))
				continue;

			for (std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
			{
				if (ip_part != ip->cbegin())
				{
					std::cout << ".";
				}
				std::cout << *ip_part;
			}
			std::cout << std::endl;
		}

		// TODO filter by any byte and output
		for (std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
		{
			bool isFortySix = false;
			for (std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
			{
				std::string strPart1(*ip_part);
				if (strcmp(strPart1.c_str(), "46") == 0)
					isFortySix = true;
			}

			if (isFortySix)
			{
				for (std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
				{
					if (ip_part != ip->cbegin())
					{
						std::cout << ".";
					}
					std::cout << *ip_part;
				}
				std::cout << std::endl;
			}
		}
		// 222.173.235.246
		// 222.130.177.64
		// 222.82.198.61
		// ...
		// 1.70.44.170
		// 1.29.168.152
		// 1.1.234.8

		
		// ip = filter(1)

		// 1.231.69.33
		// 1.87.203.225
		// 1.70.44.170
		// 1.29.168.152
		// 1.1.234.8

		// TODO filter by first and second bytes and output
		// ip = filter(46, 70)

		// 46.70.225.39
		// 46.70.147.26
		// 46.70.113.73
		// 46.70.29.76

		// TODO filter by any byte and output
		// ip = filter_any(46)

		// 186.204.34.46
		// 186.46.222.194
		// 185.46.87.231
		// 185.46.86.132
		// 185.46.86.131
		// 185.46.86.131
		// 185.46.86.22
		// 185.46.85.204
		// 185.46.85.78
		// 68.46.218.208
		// 46.251.197.23
		// 46.223.254.56
		// 46.223.254.56
		// 46.182.19.219
		// 46.161.63.66
		// 46.161.61.51
		// 46.161.60.92
		// 46.161.60.35
		// 46.161.58.202
		// 46.161.56.241
		// 46.161.56.203
		// 46.161.56.174
		// 46.161.56.106
		// 46.161.56.106
		// 46.101.163.119
		// 46.101.127.145
		// 46.70.225.39
		// 46.70.147.26
		// 46.70.113.73
		// 46.70.29.76
		// 46.55.46.98
		// 46.49.43.85
		// 39.46.86.85
		// 5.189.203.46
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
