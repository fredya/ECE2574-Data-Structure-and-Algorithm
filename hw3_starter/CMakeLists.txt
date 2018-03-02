cmake_minimum_required(VERSION 3.5)
project(HW3 CXX)

# Require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create unit tests 
# In the following, do NOT list hw3_utilities.cpp
# (To support templates, hw3_utilities.cpp is #included by hw3_utilities.h)
add_executable(hw3_test hw3_test.cpp hw3_utilities.h catch.hpp)

# The following will not be graded. It is for your convenience 
#  to experiment with your own main() function in hw2_main.cpp
add_executable(hw3_main hw3_main.cpp hw3_utilities.h)

# unit tests 
enable_testing(unittest hw3_test)

