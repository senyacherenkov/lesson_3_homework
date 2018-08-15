#include "filter_helper.h"

#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>

using namespace filtering;
BOOST_AUTO_TEST_SUITE(test_suite_main)
static std::vector<std::vector<std::string> > ip_pool    { { "1", "10", "2", "1" },
                                                           { "1", "2", "3", "4" },
                                                           { "1", "2", "6", "1" },
                                                           { "70", "2", "6", "1" },
                                                           { "46", "70", "6", "1" },
                                                           { "46", "128", "6", "1" },
                                                           { "168", "56", "46", "1" }};
BOOST_AUTO_TEST_CASE(check_proper_sorting)
{
    lexicographRevSort(ip_pool);

    BOOST_CHECK_MESSAGE( getIp(ip_pool.at(0)) == "168.56.46.1", "actual value: " << getIp(ip_pool.at(0)) );
    BOOST_CHECK_MESSAGE( getIp(ip_pool.at(1)) == "70.2.6.1", "actual value: " << getIp(ip_pool.at(1)) );
    BOOST_CHECK_MESSAGE( getIp(ip_pool.at(2)) == "46.128.6.1", "actual value: " << getIp(ip_pool.at(2)) );
    BOOST_CHECK_MESSAGE( getIp(ip_pool.at(3)) == "46.70.6.1", "actual value: " << getIp(ip_pool.at(3)) );
    BOOST_CHECK_MESSAGE( getIp(ip_pool.at(4)) == "1.10.2.1", "actual value: " << getIp(ip_pool.at(4)) );
    BOOST_CHECK_MESSAGE( getIp(ip_pool.at(5)) == "1.2.6.1", "actual value: " << getIp(ip_pool.at(5)) );
    BOOST_CHECK_MESSAGE( getIp(ip_pool.at(6)) == "1.2.3.4", "actual value: " << getIp(ip_pool.at(6)) );
}

BOOST_AUTO_TEST_CASE(check_filter_valid)
{
    std::vector<std::string> result = filter(ip_pool, "1");

    BOOST_CHECK_MESSAGE( result.size() == 3, "result.size(): " << result.size());
    BOOST_CHECK_MESSAGE( result.at(0) == "1.10.2.1", "result.at(0):" << result.at(0));
    BOOST_CHECK_MESSAGE( result.at(1) == "1.2.6.1", "result.at(1):" << result.at(1));
    BOOST_CHECK_MESSAGE( result.at(2) == "1.2.3.4", "result.at(2):" << result.at(2));

    result.clear();
    result = filter(ip_pool, "46", "70");

    BOOST_CHECK_MESSAGE( result.size() == 1, "result.size(): " << result.size());
    BOOST_CHECK_MESSAGE( result.at(0) == "46.70.6.1", "result.at(0):" << result.at(0));
}

BOOST_AUTO_TEST_CASE(check_filter_any_valid)
{
    std::vector<std::string> result = filter_any(ip_pool, "46");

    BOOST_CHECK_MESSAGE( result.size() == 3, "result.size(): " << result.size());
    BOOST_CHECK_MESSAGE( result.at(0) == "168.56.46.1", "result.at(0):" << result.at(0));
    BOOST_CHECK_MESSAGE( result.at(1) == "46.128.6.1", "result.at(1):" << result.at(1));
    BOOST_CHECK_MESSAGE( result.at(2) == "46.70.6.1", "result.at(2):" << result.at(2));
}

BOOST_AUTO_TEST_SUITE_END()
