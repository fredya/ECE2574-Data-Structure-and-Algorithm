////////////////////////////////////////////////////////
//  ECE 2574, Homework 3  
//  Description: Specification file for several recursive functions.
//  Date:        2/19/2018
/** @file hw3_utilities.h */

#ifndef HW3_RECURSIVE_
#define HW3_RECURSIVE_

/** Perform multiplication by recursive addition.
    @param m  Both m and n are nonnegative integers.
	@param n  
    @return   m + m + m + ... + m  (add m to itself repeatedly to compute m*n)   */
unsigned int mult_recursive(unsigned int m, unsigned int n);

/** Perform exponentiation by recursive multiplication.
    @pre      Assume m >= 1 and n >= 0
    @param m  An integer >= 1
    @param n  An integer >= 0
    @return   m raised to the power n, computed using m * m * ... * m   */
unsigned int pow_recursive(unsigned int m, unsigned int n);

/** Perform palindrome detection recursively. This function is case sensitive.
    @param s  An arbitrary string
    @return   True if s contains a palindrome, otherwise return false   */
bool pal_recursive(std::string s);

/** Perform binary search (recursively) within an array of integers.
    @param anArray	Array of values to be searched
	@param first	Index of first element in subarray to be searched
    @param last		Index of last element in subarray to be searched
	@param target	Value to find in the array
	@return	        Index of target if found in anArray; 
	                 otherwise return -1 to indicate not found	 */
template<typename T>
int binary_search_recursive(const T anArray[], int first, int last, T target);

/** Copy items (recursively) from one array to another array in reverse order.
	Example: if inArray contains {1, 2, 3}, then this function should copy values
	to outArray so that outArray contains {3, 2, 1}.
	@pre   Both arrays have been allocated by the calling function,
			and both arrays are sufficiently large
	@param inArray	Array of values to be copied
	@param outArray	Array that will contain the result
	@param inIndex	An index into inArray; at the initial call, this should be 0
	@param outIndex	An index into outArray; at the intitial call, 
			this value is size of inArray minus 1 
 */
template<typename T>
void reverse_array_recursive(const T inArray[], T outArray[], int inIndex, int outIndex);

#include "hw3_utilities.cpp"
#endif