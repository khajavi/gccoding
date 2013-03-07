#include <string>
#include <iostream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "MyTest"
#include <boost/test/unit_test.hpp>

using namespace std;

template<char* S>
void Test()
{
    BOOST_REQUIRE("Boom!" != string(S));
}

char bang[] = "Bang!";

BOOST_AUTO_TEST_CASE(Boom)
{
    char boom[] = "Boom!";
    Test<bang>();
}


