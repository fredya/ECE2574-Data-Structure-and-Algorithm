////////////////////////////////////////////////////////
// ECE 2574, Homework 1, starter code
//
#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE	// this line avoids problems due to color-coding the output
#include "catch.hpp"

#include "ArrayBag.h" 

// The following tests need to be expanded, as described in the specification
TEST_CASE("Test the 'replace' method", "[ArrayBag]") {
	
	ArrayBag<double> b;
	REQUIRE(b.isEmpty());	
	b.add(1);
	b.add(1);
	b.add(3);
	b.add(16);
	b.add(3);
	b.add(8);
	std::cout << "add(1,1,3,16,3,8)" << std::endl;
	std::vector<double> bv = b.toVector();	// test use
	std::cout << "Vector" << bv[0] << bv[1] << bv[2] << bv[3] << bv[4] << bv[5] << std::endl;	// test use
	std::cout << "Test replace(3, 17)" << std::endl;
	b.replace(3, 17);
	bv = b.toVector();	// test use
	std::cout << "Vector" << bv[0] << bv[1] << bv[2] << bv[3] << bv[4] << bv[5] << std::endl;	// test use
	double arr[] = {1,2,3,5,8};
	std::cout << "arr size" << sizeof(arr) / sizeof(arr[0]) << std::endl;	// test use
	double arrA[] = {1,2,3,4,5};
	ArrayBag<double> c(arrA, 5);
	std::vector<double> cv = c.toVector();	// test use
	cv = c.toVector();
	std::cout << "Vector " << cv[0] << cv[1] << cv[2] << cv[3] << std::endl;	// test use
}
