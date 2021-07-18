#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE test_ip

#include "../PrintIP.h"
#include <boost/test/unit_test.hpp>

#include <list>

using ip = std::vector<std::string>;

void checkCollections(const ip& lhs, const ip& rhs)
{
    BOOST_CHECK_EQUAL(lhs.size(), rhs.size());
    for (auto i = 0; i < lhs.size(); i++)
    {
        BOOST_CHECK_EQUAL(lhs[i], rhs[i]);
    }
}

BOOST_AUTO_TEST_SUITE(ConvertToBytes)

BOOST_AUTO_TEST_CASE(basicConvert)
{
    {
        std::cout << "Checking char -1 to 255" << std::endl;
        const ip gold = {"255"};

        const auto& res = printIP(char{-1});
        checkCollections(res, gold);
    }
    {
        std::cout << "Checking short 0 to 0.0" << std::endl;
        ip gold = {"0", "0"};

        const auto& res = printIP(short{0});
        checkCollections(res, gold);
    }
    {
        std::cout << "Checking int 2130706433 to 127.0.0.1" << std::endl;
        const ip gold = {"127", "0", "0", "1"};

        const auto& res = printIP(int{2130706433});
        checkCollections(res, gold);
    }
    {
        std::cout << "Checking long 8875824491850138409 to 123.45.67.89.101.112.131.41" << std::endl;
        const ip gold = {"123", "45", "67", "89", "101", "112", "131", "41"};

        const auto& res = printIP(long{8875824491850138409});
        checkCollections(res, gold);
    }
    {
        std::cout << "Checking string Hello, World!" << std::endl;
        const ip gold = {"Hello, World!"};

        const auto& res = printIP( std::string{"Hello, World!"});
        checkCollections(res, gold);
    }
    {
        std::cout << "Checking vector {100, 200, 300, 400}" << std::endl;
        const ip gold = {"100", "200", "300", "400"};

        const auto& res = printIP(std::vector<int>{100, 200, 300, 400});
        checkCollections(res, gold);
    }
    {
        std::cout << "Checking ist {400, 300, 200, 100}" << std::endl;
        const ip gold = {"400", "300", "200", "100"};

        const auto& res = printIP(std::list<short>{400, 300, 200, 100});
        checkCollections(res, gold);
    }
}

BOOST_AUTO_TEST_SUITE_END() // ConvertToBytes