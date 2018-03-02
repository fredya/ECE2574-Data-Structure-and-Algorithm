/////////////////////////////////////////////////////////////
//  HW3 -- starter code - ALA 2/2018

/** Implementation file for recursive functions.
 @file hw3_utilities.cpp */

#include "hw3_utilities.h"

// TO-DO: Implement the following function
unsigned int mult_recursive(unsigned int m, unsigned int n)
{
	unsigned int result = 0;
	if ((m >= 0) && (n >= 0))
	{
		if (n > 0)
		{
			return m + mult_recursive(m, n - 1);
		}
		else
		{
			return 0;
		}
	}
	return result;
}

// TO-DO: Implement the following function
unsigned int pow_recursive(unsigned int m, unsigned int n)
{
	unsigned int result = 0;
	if (m >= 1 && n >= 0)
	{
		if (n > 0)
		{
			return m * pow_recursive(m, n - 1);
		}
		else
		{
			return 1;
		}
	}
	return result;
}

// TO-DO: Implement the following function
bool pal_recursive(std::string s)
{
	int strLength = s.length();
	if (strLength <= 1)
	{
		return true;
	}
	else
	{
		if (s[0] == s[strLength - 1])
		{
			return pal_recursive(s.substr(1, strLength - 2));
		}
		else
		{
			return false;
		}
	}
}

// TO-DO: Implement the following function
template<typename T>
int binary_search_recursive(const T anArray[], int first, int last, T target)
{
	if (first > last)
	{
		return -1;
	}
	else
	{
		int mid = (first + last) / 2;
		if (anArray[mid] == target)
		{
			return mid;
		}
		else if (target < anArray[mid])
		{
			return binary_search_recursive(anArray, first, mid - 1, target);
		}
		else
		{
			return binary_search_recursive(anArray, mid + 1, last, target);
		}
	}
}

// TO-DO: Implement the following function
template<typename T>
void reverse_array_recursive(const T inArray[], T outArray[], int inIndex, int outIndex)
{
	if (outIndex < 0)
	{
		return;
	}
	else
	{
		outArray[inIndex] = inArray[outIndex];
		return reverse_array_recursive(inArray, outArray, inIndex + 1, outIndex - 1);
	}
}
