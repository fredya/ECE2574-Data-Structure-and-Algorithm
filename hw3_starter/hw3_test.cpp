////////////////////////////////////////////////////////
// ECE 2574, Homework 3
// Starter code for HW3.  
// Part of the assignment is that you should create a test suite that is much more extensive. 
//
#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE	// this line avoids problems due to color-coding the output
#include "catch.hpp"
#include "hw3_utilities.h"

TEST_CASE("Testing multiplication (by recursive addition)", "[regular functions]") 
{
	int m, n;

	INFO("Hint: testing mult_recursive with m!=0 and n!=0");
	m = 7;
	n = 8;
	REQUIRE(mult_recursive(m, n) == m * n);		
	std::cout << "mult_recursive(0, 1) " << mult_recursive(0, 1) << std::endl;
	std::cout << "mult_recursive(0, 0) " << mult_recursive(0, 0) << std::endl;
	std::cout << "mult_recursive(1, 0) " << mult_recursive(1, 0) << std::endl;
	std::cout << "mult_recursive(2, 3) " << mult_recursive(2, 3) << std::endl;
	std::cout << "pow_recursive(2, 0) " << pow_recursive(2, 0) << std::endl;
	std::cout << "pow_recursive(0, 0) " << pow_recursive(0, 0) << std::endl;
	// test 
	// pal_recursive()
	std::string a = "Racecar";
	std::string b = "racecar ";
	std::string c = " racecar";
	std::string d = "racecar";
	std::string e = " racecar ";
	std::string f;
	std::cout << "a " << pal_recursive(a) << std::endl;
	std::cout << "b " << pal_recursive(b) << std::endl;
	std::cout << "c " << pal_recursive(c) << std::endl;
	std::cout << "d " << pal_recursive(d) << std::endl;
	std::cout << "e " << pal_recursive(e) << std::endl;
	std::cout << "f " << pal_recursive(f) << std::endl;
	// test 
	// int binary_search_recursive(const T anArray[], int first, int last, T target)
	int anArray[] = { 0, 2, 4, 6, 8, 17, 21, 100 };
	std::cout << "anArray[] = { 0, 2, 4, 6, 8, 17, 21, 100 } " << std::endl;
	int target = 0;
	std::cout << "target = 0 " << binary_search_recursive(anArray, 0, 7, target) << std::endl;
	target = 2;
	std::cout << "target = 2 " << binary_search_recursive(anArray, 0, 7, target) << std::endl;
	target = 6;
	std::cout << "target = 6 " << binary_search_recursive(anArray, 0, 7, target) << std::endl;
	target = 21;
	std::cout << "target = 21 " << binary_search_recursive(anArray, 0, 7, target) << std::endl;
	target = 100;
	std::cout << "target = 100 " << binary_search_recursive(anArray, 0, 7, target) << std::endl;
	target = 16;
	std::cout << "target = 16 " << binary_search_recursive(anArray, 0, 7, target) << std::endl;
	target = 3;
	std::cout << "target = 3 " << binary_search_recursive(anArray, 0, 7, target) << std::endl;
	int anArray2[] = {8};
	std::cout << "anArray2[] = {8}; " << std::endl;
	target = 8;
	std::cout << "target = 8 " << binary_search_recursive(anArray2, 0, 1, target) << std::endl;
	target = 0;
	std::cout << "target = 0 " << binary_search_recursive(anArray2, 0, 1, target) << std::endl;
	// test 
	// void reverse_array_recursive(const T inArray[], T outArray[], int inIndex, int outIndex)
	int inArray[] = {8, 1, 2, 3, 5, 6};
	int outArray[6];
	std::cout << "inArray " << sizeof(inArray) / sizeof(inArray[0]) - 1 << std::endl;;
	reverse_array_recursive(inArray, outArray, 0, 5);
	std::cout << "outArray " << outArray[0];
	std::cout << " " << outArray[1];
	std::cout << " " << outArray[2];
	std::cout << " " << outArray[3];
	std::cout << " " << outArray[4];
	std::cout << " " << outArray[5] << std::endl;




}

//TEST_CASE("Testing reversal of array", "[regular functions]")
//{
//	int arr1[] = { 1, 2, 3 };
//	int arr2[3];
//
//	INFO("Hint: reversal of small array using integers");
//	reverse_array_recursive <int>(arr1, arr2, 0, 2);
//	REQUIRE(arr2[0] == 3);
//	REQUIRE(arr2[1] == 2);
//	REQUIRE(arr2[2] == 1);
//
//}