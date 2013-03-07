/*
 * Adopted from http://www.alittlemadness.com/2009/03/31/c-unit-testing-with-boosttest/
 */
#include <string>
#include <iostream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/unit_test.hpp>


int add(int i, int j) {
	return i + j;
}

BOOST_AUTO_TEST_CASE(universeInOrder) {
	BOOST_CHECK(add(2, 2) == 5);
	BOOST_REQUIRE(add(2, 2) == 4);
}


