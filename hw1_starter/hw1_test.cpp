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
}
